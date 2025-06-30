/**
 * @file app_main.c
 * @brief Application entry point for LED blink example.
 */

#include "hal/led_hal.h"
#include "services/delay_service.h"

#define BLINK_DELAY_MS 500

int app_main(void)
{
    led_init();
    while (1)
    {
        led_on();
        delay_ms(BLINK_DELAY_MS);
        led_off();
        delay_ms(BLINK_DELAY_MS);
    }
    // Should never reach here
    return 0;
}






