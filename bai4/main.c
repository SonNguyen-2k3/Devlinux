#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "config.h"
#include "sensor.h"
#include "actuators.h"
#include "buttons.h"
#include "watering_logic.h"

int main(void) {
    srand(time(NULL));

    SystemConfig config = {
        .moisture_min = 40,
        .moisture_max = 70,
        .watering_time_max = 5,
        .check_interval = 3,
        .mode = MODE_AUTO
    };

    SystemState state = {
        .pump = PUMP_OFF,
        .led = LED_NORMAL,
        .sensor = {0,0},
        .last_watering = 0
    };

    sensors_init();
    actuators_init();
    buttons_init();

    printf("[System] Smart Plant Watering System started.\n");

    while (1) {
        if (rand() % 30 == 0) button_toggle_mode(&config, &state);
        if (rand() % 50 == 0) button_manual_water(&config, &state);

        watering_check(&config, &state);

        sleep(config.check_interval);
    }

    return 0;
}
