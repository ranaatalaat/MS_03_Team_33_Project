#include "dc_motor_driver.h"
#include "hardware/pwm.h"


void dc_motor_init() {
gpio_init(MOTOR_PIN1) ;
gpio_set_dir(MOTOR_PIN1, GPIO_OUT) ;
gpio_init(MOTOR_PIN2) ;
gpio_set_dir(MOTOR_PIN2, GPIO_OUT) ;

gpio_set_function(MOTOR_PWM, GPIO_FUNC_PWM) ;
uint slice_num = pwm_gpio_to_slice_num (MOTOR_PWM);
pwm_set_wrap (slice_num, 255);

pwm_set_clkdiv(slice_num, 4.0f);
pwm_set_enabled(slice_num, true);
}

void dc_motor_control(uint16_t speed, bool forward) {
if (speed > 255) speed = 255;

if (forward)
{
gpio_put (MOTOR_PIN1, 1); 
gpio_put (MOTOR_PIN2, 0);
} else {
gpio_put (MOTOR_PIN1, 0);
gpio_put (MOTOR_PIN2, 1);
}

pwm_set_gpio_level(MOTOR_PWM, speed);
}