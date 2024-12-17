#ifndef DC_MOTOR_DRIVER_H
#define DC_MOTOR_DRIVER_H

#include "pico/stdlib.h"

#define MOTOR_PIN1 2
#define MOTOR_PIN2 3
#define MOTOR_PWM 6

void dc_motor_init(void);
void dc_motor_control(uint16_t speed, bool forward);


#endif 