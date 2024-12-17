#ifndef VIBRATION_SENSOR_H
#define VIBRATION_SENSOR_H

#include "pico/stdlib.h"
#include "hardware/adc.h"

#define VIBRATION_SENSOR_PIN 26  
#define VIBRATION_THRESHOLD 1500  

void vibration_sensor_init(void);
bool vibration_detected(void);
uint16_t vibration_read(void);


#endif 