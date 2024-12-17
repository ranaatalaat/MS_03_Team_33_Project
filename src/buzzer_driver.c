#include <pico/stdlib.h>
#include "buzzer_driver.h"

void buzzer_init(void) {
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);
}

void buzzer_on(uint16_t frequency) {
  
        gpio_put(BUZZER_PIN, 1);  

    sleep_ms(2000 );

      gpio_put(BUZZER_PIN, 0); 
    

    
}

void buzzer_off(void) {
    gpio_put(BUZZER_PIN, 0); 
}
