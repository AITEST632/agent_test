#define UNIT_TEST
#include "unity.h"
#include "mock_avr_io.h"
#include "../inc/app/app_main.h"
#include "../inc/hal/led_hal.h"
#include "../inc/services/delay_service.h"

void setUp(void) {
    PORTB = 0;
    DDRB = 0;
}
void tearDown(void) {}

void test_app_main_should_initialize_led_and_blink(void)
{
    led_init();
    // After led_init, DDRB bit 0 should be set
    TEST_ASSERT_BITS_HIGH(1 << 0, DDRB);

    led_on();
    // After led_on, PORTB bit 0 should be set
    TEST_ASSERT_BITS_HIGH(1 << 0, PORTB);

    led_off();
    // After led_off, PORTB bit 0 should be cleared
    TEST_ASSERT_BITS_LOW(1 << 0, PORTB);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_app_main_should_initialize_led_and_blink);
    return UNITY_END();
}
