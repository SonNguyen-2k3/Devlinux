#include <stdio.h>
#include "actuators.h"

void actuators_init(void) {
    printf("[Actuators] Initialized\n");
}

void pump_control(SystemState *state, PumpState new_state) {
    state->pump = new_state;
    printf("[Pump] State: %s\n", new_state == PUMP_ON ? "ON" : "OFF");
}

void led_control(SystemState *state, LedState new_state) {
    state->led = new_state;
    printf("[LED] State: %s\n", new_state == LED_NORMAL ? "NORMAL" : "WARNING");
}
