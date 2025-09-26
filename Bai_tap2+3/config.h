#ifndef CONFIG_H
#define CONFIG_H

// ===== Định nghĩa cấu hình hệ thống =====
typedef enum { MODE_AUTO, MODE_MANUAL } Mode;
typedef enum { PUMP_OFF, PUMP_ON } PumpState;
typedef enum { LED_NORMAL, LED_WARNING } LedState;

typedef struct {
    int moisture_min;
    int moisture_max;
    int watering_time_max;   // giây
    int check_interval;      // giây
    Mode mode;
} SystemConfig;

typedef struct {
    PumpState pump;
    LedState led;
    int sensor[2];           // [0]=độ ẩm đất, [1]=nhiệt độ
    int last_watering;       // thời gian lần tưới cuối
} SystemState;

#endif
