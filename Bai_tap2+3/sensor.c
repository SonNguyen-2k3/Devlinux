#include <stdio.h>
#include <stdlib.h>
#include "sensor.h"

void sensors_init(void) {
    printf("[Sensor] Initialized\n");
}

int read_moisture(void) {
    return rand() % 100; // giả lập % độ ẩm
}

int read_temperature(void) {
    return 20 + rand() % 15; // giả lập 20-35°C
}
