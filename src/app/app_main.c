#include "hal/led_hal.h"
#include "services/delay_service.h"

/**
 * @brief Application entry point for LED blink demo.
 * @return int 0 on success (never returns in embedded loop).
 *added comments
 */
int app_main(void)
{
    led_init();
    while (1)
    {
        led_on();
        delay_ms(500);
        led_off();
        delay_ms(500);
    }
    return 0;
}
