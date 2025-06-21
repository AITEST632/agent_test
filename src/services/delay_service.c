#include "delay_service.h"

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
