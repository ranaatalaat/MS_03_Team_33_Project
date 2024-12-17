#ifndef SOUND_SENSOR_H
#define SOUND_SENSOR_H

#include "pico/stdlib.h"

#define SOUND_PIN 27 // ADC1

void sound_sensor_init(void);
uint16_t sound_sensor_read(void);

#endif 