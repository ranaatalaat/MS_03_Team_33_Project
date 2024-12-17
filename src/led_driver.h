#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include "pico/stdlib.h"

#define LED_PIN 13

void led_init(void);
void led_on(void);
void led_off(void);
void led_toggle(void);

#endif 