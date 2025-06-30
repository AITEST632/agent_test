/**
 * @file delay_service.c
 * @brief Provides millisecond delay functionality for timing operations.
 */

#include "delay_service.h"

/**
 * @brief Delays execution for a specified number of milliseconds.
 * @param ms Number of milliseconds to delay.
 */
void delay_ms(uint16_t ms)
{
    // Simple delay loop (not accurate, for demonstration only)
    volatile uint32_t count;
    while (ms--)
    {
        count = 1000;
        while (count--);
    }
}
