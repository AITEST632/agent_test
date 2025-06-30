/**
 * @file led_hal.c
 * @brief Hardware Abstraction Layer for LED control.
 */

#include "led_hal.h"
#ifdef UNIT_TEST
#include "mock_avr_io.h"
#else
#include <avr/io.h>
#endif

#define LED_PORT   PORTB
#define LED_DDR    DDRB
#define LED_PIN    0

/**
 * @brief Initializes the LED hardware (sets pin as output).
 */
void led_init(void)
{
    LED_DDR |= (1 << LED_PIN);
}

/**
 * @brief Turns the LED on.
 */
void led_on(void)
{
    LED_PORT |= (1 << LED_PIN);
}

/**
 * @brief Turns the LED off.
 */
void led_off(void)
{
    LED_PORT &= ~(1 << LED_PIN);
}
