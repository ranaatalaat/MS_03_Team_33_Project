#include "vibration_sensor.h"

void vibration_sensor_init(void) {
    adc_init();
    adc_gpio_init(VIBRATION_SENSOR_PIN);
    adc_select_input(0);  
}

bool vibration_detected(void) {
    uint16_t result = adc_read();
    return result > VIBRATION_THRESHOLD;
}

uint16_t vibration_read(void) {
    return adc_read(); 
}