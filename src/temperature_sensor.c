#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "temperature_sensor.h"

#define ADC_VREF 3.3        
#define ADC_RANGE (1 << 12) 
#define ADC_CONVERT (ADC_VREF / (ADC_RANGE - 1))

void temperature_sensor_init(void) {
    adc_init();                     
    adc_gpio_init(TEMPERATURE_PIN);  
    adc_select_input(2);              
}

float temperature_sensor_read(void) {
    uint16_t result = adc_read();           
    float voltage = result * ADC_CONVERT;  
    float temperature = voltage * 100.0;    
    return temperature;                     
}
