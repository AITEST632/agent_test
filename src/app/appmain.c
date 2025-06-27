#include "hal/led_hal.h"
#include "services/delay_service.h"


int app_main(void)
{
    led_init();
    while (1)
    {
        led_on();
        delay_ms(500);
        led_off();
        delay_ms(500);

        led_on();
        delay_ms(500);
        led_off();
        delay_ms(500);

        led_on();
        delay_ms(500);
        led_off();
        delay_ms(500);
    
    return 0;
}