#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_log.h"

//#define BLINK_GPIO CONFIG_BLINK_GPIO
#define BLINK_GPIO CONFIG_BLINK_GPIO
#define SLEEP_TIME_MS CONFIG_SLEEP_TIME_MS
#define BLINK_TIME_MS CONFIG_BLINK_TIME_MS

static const char *TAG = "BLINK";

static void configure_led(void)
{
    ESP_LOGI(TAG, "Example configured to blink GPIO LED!");
    gpio_reset_pin(BLINK_GPIO);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
}

void app_main(void){
	//esp_log_level_set("BLINK", ESP_LOG_ERROR);       
	esp_log_level_set("BLINK", ESP_LOG_INFO);  
	configure_led();     
 	//int SLEEP_TIME_MS = 1000;
 	//int BLINK_TIME_MS = 5000;
	configure_led();
	ESP_ERROR_CHECK(gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT));

	while(1) {
        /* Blink on (output low) */
		ESP_LOGI(TAG, "Turning on the LED");
		ESP_ERROR_CHECK(gpio_set_level(BLINK_GPIO, 0));
		vTaskDelay(SLEEP_TIME_MS / portTICK_PERIOD_MS);
        /* Blink off (output high) */
		ESP_LOGI(TAG, "Turning off the LED");
		ESP_ERROR_CHECK(gpio_set_level(BLINK_GPIO, 1));
		vTaskDelay(BLINK_TIME_MS / portTICK_PERIOD_MS);
	}
}

// //pullup, LED shines when switch is open
// #define SWITCH_GPIO 22
// #define LED_GPIO 5

// static const char *TAG = "SWITCH";

// void app_main(void){
// 	esp_log_level_set("SWITCH", ESP_LOG_INFO);       
	
// 	ESP_ERROR_CHECK(gpio_set_direction(SWITCH_GPIO,GPIO_MODE_INPUT));
// 	ESP_ERROR_CHECK(gpio_pullup_en(SWITCH_GPIO));
// 	ESP_ERROR_CHECK(gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT));
// 	while(1) {

// 		if (gpio_get_level(SWITCH_GPIO)) {
// 			ESP_ERROR_CHECK(gpio_set_level(LED_GPIO, 1));
// 		} else {
// 			ESP_ERROR_CHECK(gpio_set_level(LED_GPIO, 0));
// 		}
        
// 	}
// }


// //pulldown, LED shines when switch is closed
// #define SWITCH_GPIO 22
// #define LED_GPIO 5

// static const char *TAG = "SWITCH";

// void app_main(void){
// 	esp_log_level_set("SWITCH", ESP_LOG_INFO);       
	
// 	ESP_ERROR_CHECK(gpio_set_direction(SWITCH_GPIO,GPIO_MODE_INPUT));
// 	ESP_ERROR_CHECK(gpio_pulldown_en(SWITCH_GPIO));
// 	ESP_ERROR_CHECK(gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT));
// 	while(1) {

// 		if (gpio_get_level(SWITCH_GPIO)) {
// 			ESP_ERROR_CHECK(gpio_set_level(LED_GPIO, 1));
// 		} else {
// 			ESP_ERROR_CHECK(gpio_set_level(LED_GPIO, 0));
// 		}
        
// 	}
// }

