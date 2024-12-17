#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include "pico/stdlib.h"

#define TEMPERATURE_PIN 28

void temperature_sensor_init(void);
float temperature_sensor_read(void);

#endif 
