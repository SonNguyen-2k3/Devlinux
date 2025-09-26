#ifndef ACTUATORS_H
#define ACTUATORS_H

#include "config.h"

void actuators_init(void);
void pump_control(SystemState *state, PumpState new_state);
void led_control(SystemState *state, LedState new_state);

#endif
