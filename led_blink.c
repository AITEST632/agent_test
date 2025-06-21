#include <stdint.h>
#include "app/app_main.h"

// Define the port and pin for the LED (example: PORTB, PIN0)
#define LED_PORT   PORTB
#define LED_DDR    DDRB
#define LED_PIN    0

void delay_ms(uint16_t ms) {
    // Simple delay loop (not accurate, for demonstration only)
    volatile uint32_t count;
    while (ms--) {
        count = 1000;
        while (count--);
    }
}

/**
 * @brief Main entry point. Calls application main.
 * @return int 0 on success.
 */
int main(void)
{
    // Set LED pin as output
    LED_DDR |= (1 << LED_PIN);

    while (1) {
        // Turn LED on
        LED_PORT |= (1 << LED_PIN);
        delay_ms(500);

        // Turn LED off
        LED_PORT &= ~(1 << LED_PIN);
        delay_ms(500);
    }

    return app_main();
}
