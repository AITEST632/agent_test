/**
 * @file delay_service.c
 * @brief Provides millisecond delay functionality for timing operations.
 * @note This delay implementation is a busy-wait and is not accurate. Do not use for production timing.
 * @note Platform-dependent: DELAY_SERVICE_LOOP_COUNT_PER_MS may need adjustment for different MCUs.
 */

#include <stdint.h>
#include "delay_service.h"

/**
 * @brief Number of loop iterations per millisecond for delay.
 */
#define DELAY_SERVICE_LOOP_COUNT_PER_MS 1000 /**< Number of loop iterations per millisecond for delay */

/**
 * @brief Delays execution for a specified number of milliseconds (busy-wait).
 * @param ms Number of milliseconds to delay.
 * @return void
 * @warning Busy-wait loop, not suitable for precise timing or low-power applications.
 */
void delay_ms(uint16_t ms)
{
    // Simple delay loop (not accurate, for demonstration only)
    while (ms--)
    {
        volatile uint32_t count = DELAY_SERVICE_LOOP_COUNT_PER_MS;
        while (count--);
    }
}
