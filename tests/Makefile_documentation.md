# Makefile Documentation: Unit Testing with Unity

## Overview
This Makefile is designed to build and run unit tests for the `led_hal` module in your Embedded C project using the Unity framework. It supports mocking hardware dependencies and uses the `UNIT_TEST` macro to enable test-specific code.

---

## Usage
- `make`        : Build the test executable
- `make run`    : Run the test executable
- `make clean`  : Remove build artifacts

---

## Requirements
- `unity.c`, `unity.h`, `unity_internals.h` in the `tests/` directory
- `mock_avr_io.h` in the `tests/` directory
- GCC compiler

---

## Key Variables
- `CC`      : The compiler (GCC)
- `CFLAGS`  : Compiler flags for includes, warnings, and C99 standard
- `UNITY_SRC`: Unity framework source file
- `TEST_SRC`: Test file and the module under test

---

## Targets
- `all` (default): Builds `test_led_hal.exe`
- `unity.c`: Reminder to download Unity if missing
- `test_led_hal.exe`: Compiles the test and module code with Unity
- `run`: Runs the test executable
- `clean`: Removes build artifacts

---

## Notes
- The Makefile uses the `UNIT_TEST` macro to include mock headers and enable test-specific code.
- All paths are relative to the `tests/` directory.
- The Makefile is documented for clarity and maintainability.

---

For more details, see the comments in the Makefile itself.
