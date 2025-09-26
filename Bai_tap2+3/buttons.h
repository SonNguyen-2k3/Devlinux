#ifndef BUTTONS_H
#define BUTTONS_H

#include "config.h"

void buttons_init(void);
void button_toggle_mode(SystemConfig *config, SystemState *state);
void button_manual_water(SystemConfig *config, SystemState *state);

#endif
