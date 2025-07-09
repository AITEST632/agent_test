/**
 * @file app_main.c
 * @brief Main application logic for LED blinking demo.
 * @note This application runs an infinite loop and is intended for embedded systems only.
 */
#include <stdint.h>
#include "hal/led_hal.h"
#include "services/delay_service.h"

#define APP_MAIN_BLINK_DELAY_MS 500 /**< Delay in milliseconds for LED blink interval */

int app_main(void)
{
    led_init();
    while (1)
    {
        led_on();
        delay_ms(APP_MAIN_BLINK_DELAY_MS);
        led_off();
        delay_ms(APP_MAIN_BLINK_DELAY_MS);
    }
    // Should never reach here
    return 0;
}






