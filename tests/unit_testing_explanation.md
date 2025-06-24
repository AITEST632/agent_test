# Embedded C Unit Testing with Unity: Detailed Explanation

## 1. Why Unit Testing?
Unit testing ensures each module of your embedded code works as expected, increases reliability, and makes refactoring safer. For embedded systems, it also helps catch logic errors before deploying to hardware.

---

## 2. Framework Selection: Unity
We chose the [Unity](https://github.com/ThrowTheSwitch/Unity) framework because it is lightweight, portable, and designed for C projects, especially in embedded environments.

---

## 3. Directory Structure
- `tests/` — All test code and framework files
  - `test_led_hal.c` — Test cases for the LED HAL module
  - `unity.c`, `unity.h`, `unity_internals.h` — Unity framework
  - `mock_avr_io.h` — Mocks for AVR hardware registers
  - `Makefile` — Build and run tests

---

## 4. Mocking Hardware Dependencies
- Production code uses `<avr/io.h>`, which is not available on a PC.
- We created `mock_avr_io.h` with `unsigned char PORTB` and `DDRB` to simulate hardware registers.
- In `led_hal.c`, we use:
  ```c
  #ifdef UNIT_TEST
  #include "mock_avr_io.h"
  #else
  #include <avr/io.h>
  #endif
  ```
  This allows the same code to be built for both hardware and tests.

---

## 5. Writing Test Cases
- Each function in `led_hal.c` has a corresponding test in `test_led_hal.c`.
- Example:
  - `test_led_init_should_set_ddrb_bit` checks if `led_init()` sets the correct bit in `DDRB`.
  - `test_led_on_should_set_portb_bit` and `test_led_off_should_clear_portb_bit` check the correct manipulation of `PORTB`.
- Unity macros like `TEST_ASSERT_BITS_HIGH` and `TEST_ASSERT_BITS_LOW` are used for assertions.

---

## 6. Makefile Automation
- The Makefile compiles the test and production code with the `UNIT_TEST` macro.
- It provides targets for building (`make`), running (`make run`), and cleaning (`make clean`).
- All paths and flags are set for easy use and portability.

---

## 7. Running the Tests
1. Place Unity files and mocks in `tests/`.
2. In terminal, run:
   ```
   make
   make run
   ```
3. Unity will output the results of each test.

---

## 8. Summary
- Hardware dependencies are mocked for PC-based testing.
- Preprocessor flags (`UNIT_TEST`) allow the same codebase for production and testing.
- Unity provides a simple, readable way to write and run tests.
- The Makefile automates the process for consistency and ease.

---

*Keep this document for future reference to onboard new developers or when expanding your test suite.*
