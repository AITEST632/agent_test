# 📘 Embedded C Development Rules

> A curated set of rules and best practices to ensure high-quality, maintainable, and reliable Embedded C code. Used by Agenti AI for code reviews.

---

## 📂 Structure & Architecture

- ✅ **Modular Codebase**: Code should be organized into logical modules (drivers, services, interfaces).
- ✅ **Layered Design**: Separate hardware abstraction (HAL), business logic, and application layers.
- ✅ **Reusability**: Write reusable functions and avoid code duplication.

---

## 📄 File Naming & Structure

- ✅ File names must be lowercase, use underscores (`_`) and reflect their purpose (e.g., `sensor_driver.c`).
- ✅ Header files should follow the same name as their source (e.g., `sensor_driver.h` for `sensor_driver.c`).
- ❌ Avoid putting multiple unrelated modules in the same file.

---

## 🧠 Coding Style

- ✅ Use **K&R style** or **Allman** consistently across the codebase.
- ✅ All functions and variables must be explicitly typed.
- ✅ Constants must use `#define` or `const` with descriptive names (`#define MAX_RETRY_COUNT 3`).
- ✅ Indent with 4 spaces. No tabs.
- ✅ Limit line length to 100 characters.

---

## 📆 Header Files

- ✅ Use **include guards** or `#pragma once`:

  ```c
  #ifndef SENSOR_DRIVER_H
  #define SENSOR_DRIVER_H
  ...
  #endif
  ```

- ✅ Include only what you need.

- ❌ Do not include `.c` files inside other files.

---

## 📣 Naming Conventions

- ✅ Variables: `snake_case`, descriptive (`uint8_t sensor_value`).
- ✅ Functions: `snake_case`, with verb-first naming (`init_uart`, `read_sensor_data`).
- ✅ Macros & Constants: `ALL_CAPS_WITH_UNDERSCORES`.

---

## 🧪 Testing & Debugging

- ✅ Each module must have a unit test or test hook where applicable.
- ✅ Use preprocessor flags for test/debug code (`#ifdef DEBUG_MODE`).
- ✅ Avoid permanent debug prints in production (`printf`, `UART_send`).

---

## 🧷 Memory & Safety

- ✅ Always initialize variables.
- ✅ Avoid dynamic memory (`malloc/free`) in firmware unless justified.
- ✅ Check for buffer overflows in all memory operations (`memcpy`, `strncpy`, etc.).
- ✅ Never assume memory alignment. Use `packed` structs if necessary.
- ✅ Avoid global variables unless absolutely required.

---

## 🕒 Timing & Delays

- ✅ Use timer modules or OS delays, not busy-wait loops.
- ❌ Avoid hardcoded delays (`for` loops for delay).

---

## 🚩 Error Handling

- ✅ All public functions should return status codes or have error callbacks.
- ✅ Never silently ignore errors.
- ✅ Use `enum` or `#define` for error codes.

---

## 🔐 MISRA Compliance (if applicable)

- ✅ Follow MISRA C:2012 guidelines where applicable.
- ❌ No use of non-standard libraries or compiler extensions without documentation.

---

## 📜 Documentation & Comments

- ✅ Every function should have a comment block describing:

  - Purpose
  - Parameters
  - Return value
  - Side effects (if any)

  ```c
  /**
   * @brief Initializes the UART peripheral.
   * @param baudrate The baudrate to use.
   * @return 0 on success, non-zero error code on failure.
   */
  int init_uart(uint32_t baudrate);
  ```

- ✅ Use `//` for inline comments.

- ❌ Do not use comments to explain what is already obvious.

---

## 🔄 Version Control & Review

- ✅ Code must be pushed with meaningful commit messages.
- ✅ Each commit should pass basic static checks and unit tests.
- ✅ Code review is mandatory for every pull request.

---

## ✨ CI/CD and Build Process

- ✅ Use Makefiles or CMake for consistent builds.
- ✅ All builds must be reproducible with a single command.
- ✅ Include build output and error logs in review if failure occurs.
- ✅ Setup CI pipelines to run static analysis, format check, and unit tests.

---

## ⏱ RTOS & Multithreading (if applicable)

- ✅ Threads must have defined priorities and stack sizes.
- ✅ Use semaphores/mutexes for shared resources.
- ✅ Avoid deadlocks and starvation through careful resource planning.

---

## 💪 Bootloaders & Firmware Updates

- ✅ Ensure update integrity via CRC or SHA verification.
- ✅ Maintain a rollback mechanism if update fails.
- ✅ Update code must be tested in both normal and edge-case conditions.

---

End of Ruleset.

---

*This file is maintained and enforced by Agenti AI during every commit and pull request.*

