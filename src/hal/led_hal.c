#include "led_hal.h"
#include <avr/io.h>

#define LED_PORT   PORTB
#define LED_DDR    DDRB
#define LED_PIN    0

void led_init(void)
{
    LED_DDR |= (1 << LED_PIN);
}

void led_on(void)
{
    LED_PORT |= (1 << LED_PIN);
}

void led_off(void)
{
    LED_PORT &= ~(1 << LED_PIN);
}
