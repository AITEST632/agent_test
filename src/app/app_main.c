#include "hal/led_hal.h"
#include "services/delay_service.h"


/**
 * @brief Main application loop for LED blinking.
 *
 * Initializes the LED hardware and blinks the LED with a fixed delay.
 *
 * @return 0 on success (theoretically unreachable due to infinite loop).
 */
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
}
