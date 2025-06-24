#define UNIT_TEST
#include "unity.h"
#include "mock_avr_io.h"
#include "../inc/hal/led_hal.h"

unsigned char PORTB = 0;
unsigned char DDRB = 0;

void setUp(void) {
    PORTB = 0;
    DDRB = 0;
}
void tearDown(void) {}

void test_led_init_should_set_ddrb_bit(void)
{
    led_init();
    TEST_ASSERT_BITS_HIGH((1 << 0), DDRB);
}

void test_led_on_should_set_portb_bit(void)
{
    led_on();
    TEST_ASSERT_BITS_HIGH((1 << 0), PORTB);
}

void test_led_off_should_clear_portb_bit(void)
{
    PORTB = 0xFF;
    led_off();
    TEST_ASSERT_BITS_LOW((1 << 0), PORTB);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_led_init_should_set_ddrb_bit);
    RUN_TEST(test_led_on_should_set_portb_bit);
    RUN_TEST(test_led_off_should_clear_portb_bit);
    return UNITY_END();
}
