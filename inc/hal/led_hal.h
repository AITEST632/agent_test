#ifndef LED_HAL_H
#define LED_HAL_H

#include <stdint.h>

/**
 * @brief Initializes the LED hardware (sets the pin as output).
 */
void led_init(void);

/**
 * @brief Turns the LED on.
 */
void led_on(void);

/**
 * @brief Turns the LED off.
 */
void led_off(void);

#endif // LED_HAL_H
