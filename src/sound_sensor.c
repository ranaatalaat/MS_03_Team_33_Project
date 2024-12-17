#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "sound_sensor.h"

void sound_sensor_init(void) {
    adc_init();
    adc_gpio_init(SOUND_PIN);
    adc_select_input(1); 
}

uint16_t sound_sensor_read(void) {
    return adc_read();
}