#include <stdio.h>
#include "buttons.h"
#include "actuators.h"

void buttons_init(void) {
    printf("[Buttons] Initialized\n");
}

void button_toggle_mode(SystemConfig *config, SystemState *state) {
    config->mode = (config->mode == MODE_AUTO) ? MODE_MANUAL : MODE_AUTO;
    printf("[Button] Mode toggled -> %s\n", config->mode == MODE_AUTO ? "AUTO" : "MANUAL");
    led_control(state, config->mode == MODE_AUTO ? LED_NORMAL : LED_WARNING);
}

void button_manual_water(SystemConfig *config, SystemState *state) {
    printf("[Button] Manual watering triggered!\n");
    pump_control(state, PUMP_ON);
}
