#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include "sound_sensor.h"
#include "led_driver.h"
#include "buzzer_driver.h"
#include "vibration_sensor.h"
#include "temperature_sensor.h"
#include "dc_motor_driver.h"

#define SAMPLE_INTERVAL_MS 2000
#define VIBRATION_THRESHOLD 1500
#define SOUND_THRESHOLD 1000
#define TEMP_THRESHOLD_MOTOR 27.0

void temperatureTask(void *pvParameters) {
    TickType_t xLastWakeTime;
    const TickType_t xPeriod = pdMS_TO_TICKS(SAMPLE_INTERVAL_MS);

    temperature_sensor_init();
    dc_motor_init();

    xLastWakeTime = xTaskGetTickCount();

    for (;;) {
        float temperature = temperature_sensor_read();
        printf("Current Temperature: %.2f°C\n", temperature);

        if (temperature > TEMP_THRESHOLD_MOTOR) {
            dc_motor_control(255, true);
            printf("Temperature exceeds %.2f°C! DC Motor ON (Forward)\n", TEMP_THRESHOLD_MOTOR);
        } else {
            dc_motor_control(0, true);
            printf("Temperature below %.2f°C! DC Motor OFF\n", TEMP_THRESHOLD_MOTOR);
        }

        vTaskDelayUntil(&xLastWakeTime, xPeriod);
    }
}

void vibrationTask(void *pvParameters) {
    TickType_t xLastWakeTime;
    const TickType_t xPeriod = pdMS_TO_TICKS(SAMPLE_INTERVAL_MS);

    vibration_sensor_init();
    buzzer_init();

    xLastWakeTime = xTaskGetTickCount();

    for (;;) {
        uint16_t vibration_value = vibration_read();
        printf("Vibration reading: %u\n", vibration_value);

        if (vibration_value >= VIBRATION_THRESHOLD) {
            buzzer_on(1000);
            printf("Vibration detected within range! Buzzer ON\n");
        } else {
            buzzer_off();
            printf("Vibration outside the range. Buzzer OFF\n");
        }

        vTaskDelayUntil(&xLastWakeTime, xPeriod);
    }
}

void soundTask(void *pvParameters) {
    TickType_t xLastWakeTime;
    const TickType_t xPeriod = pdMS_TO_TICKS(SAMPLE_INTERVAL_MS);

    sound_sensor_init();
    led_init();

    xLastWakeTime = xTaskGetTickCount();

    for (;;) {
        uint16_t sound_level = sound_sensor_read();
        printf("Sound level: %u\n", sound_level);

        if (sound_level > SOUND_THRESHOLD) {
            led_on();
            printf("Sound detected! LED ON\n");
        } else {
            led_off();
            printf("Quiet. LED OFF\n");
        }

        vTaskDelayUntil(&xLastWakeTime, xPeriod);
    }
}

void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName) {
    printf("Stack overflow in task: %s\n", pcTaskName);
    while(1);
}

int main() {
    stdio_init_all();

    printf("Sound-activated LED, vibration-activated Buzzer, temperature-activated LED, and temperature-controlled DC motor system initialized.\n");

    xTaskCreate(temperatureTask, "Temperature Task", configMINIMAL_STACK_SIZE * 2, NULL, 1, NULL);
    xTaskCreate(vibrationTask, "Vibration Task", configMINIMAL_STACK_SIZE * 2, NULL, 1, NULL);
    xTaskCreate(soundTask, "Sound Task", configMINIMAL_STACK_SIZE * 2, NULL, 1, NULL);

    vTaskStartScheduler();

    while (1) {
        // The program should never reach here
    }

    return 0;
}