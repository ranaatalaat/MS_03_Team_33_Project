#ifndef BUZZER_DRIVER_H
#define BUZZER_DRIVER_H

#include <pico/stdlib.h>

#define BUZZER_PIN 9

void buzzer_init(void);
void buzzer_on(uint16_t frequency);
void buzzer_off(void);

#endif 