# Makefile for running unit tests with Unity
#
# This Makefile builds and runs unit tests for the led_hal module using the Unity framework.
# It mocks hardware dependencies and uses the UNIT_TEST macro to enable test-specific code.
#
# Usage:
#   make        - Build the test executable
#   make run    - Run the test executable
#   make clean  - Remove build artifacts
#
# Requirements:
#   - unity.c, unity.h, unity_internals.h in the tests/ directory
#   - mock_avr_io.h in the tests/ directory
#   - GCC compiler
#
CC = gcc
# CFLAGS includes:
#   -I.           : current directory (for Unity and mocks)
#   -I../inc      : project headers
#   -I../inc/hal  : HAL headers
#   -DUNIT_TEST   : enables test-specific code (e.g., mocks)
#   -Wall -Wextra : enable all warnings
#   -std=c99      : use C99 standard
CFLAGS = -I. -I../inc -I../inc/hal -I. -DUNIT_TEST -Wall -Wextra -std=c99
UNITY_SRC = unity.c

# Test target for led_hal
# TEST_SRC includes the test file and the module under test
TEST_SRC = test_led_hal.c ../src/hal/led_hal.c

# Default target: build the test executable
all: test_led_hal.exe

# Reminder to download Unity if missing
unity.c:
	@echo "Please download unity.c from https://github.com/ThrowTheSwitch/Unity and place it here."

# Build test executable
# You must have unity.c and unity.h in the tests/ directory

test_led_hal.exe: $(TEST_SRC) $(UNITY_SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Run the test executable
run: test_led_hal.exe
	./test_led_hal.exe

# Clean build artifacts
clean:
	rm -f *.exe *.o
