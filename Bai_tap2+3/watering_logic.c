#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "watering_logic.h"
#include "sensor.h"
#include "actuators.h"

void watering_check(SystemConfig *config, SystemState *state) {
    state->sensor[0] = read_moisture();
    state->sensor[1] = read_temperature();

    printf("[Sensor] Moisture=%d%%, Temp=%dC\n", state->sensor[0], state->sensor[1]);

    if (config->mode == MODE_AUTO) {
        if (state->sensor[0] < config->moisture_min) {
            printf("[Logic] Soil dry! Pump ON\n");
            pump_control(state, PUMP_ON);
            sleep(config->watering_time_max);
            pump_control(state, PUMP_OFF);
        } else {
            printf("[Logic] Moisture OK -> Pump OFF\n");
            pump_control(state, PUMP_OFF);
        }
    }
}
