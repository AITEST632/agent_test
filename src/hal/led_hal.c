/**
 * @file led_hal.c
 * @brief Hardware Abstraction Layer for LED control.
 * @note Platform-dependent: This implementation assumes AVR register naming and may need changes for other MCUs.
 */

#include <stdint.h>
#include "led_hal.h"
#ifdef UNIT_TEST
#include "mock_avr_io.h"
#else
#include <avr/io.h>
#endif

/**
 * @brief Port register for LED control.
 */
#define LED_HAL_PORTB   PORTB
/**
 * @brief Data direction register for LED control.
 */
#define LED_HAL_DDRB    DDRB
/**
 * @brief Pin number for LED control.
 */
#define LED_HAL_PIN 0

/**
 * @brief Initializes the LED hardware (sets pin as output).
 * @return void
 */
void led_init(void)
{
    LED_HAL_DDRB |= (1 << LED_HAL_PIN);
}

/**
 * @brief Turns the LED on.
 * @return void
 */
void led_on(void)
{
    LED_HAL_PORTB |= (1 << LED_HAL_PIN);
}

/**
 * @brief Turns the LED off.
 * @return void
 */
void led_off(void)
{
    LED_HAL_PORTB &= ~(1 << LED_HAL_PIN);
}
