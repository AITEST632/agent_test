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


## 📖 Doxygen Document
- ✅ Use Doxygen for generating documentation.
   - ✅ 1. If the `Doxyfile` or `Docs` folder does not exist, they must be created automatically.
   - ✅ 2. The workflow must be atomic: after creating the `Doxyfile` and `Docs` folder (if missing), immediately run `doxygen Doxyfile` in the same step, with no user intervention or extra prompt required.
   - ✅ 3. The process must always ensure the Doxyfile's `OUTPUT_DIRECTORY` is set to `Docs` (case-sensitive).
   - ✅ 4. The generated HTML documentation must be in `Docs/html/`.
   - ⚠️ All steps must be followed for every documentation generation or update, and the process must be fully automated and require no user intervention.
  

---

## Example Doxygen Comment
```c
/**
 * @brief Initializes the UART peripheral.
 * @param baudrate The baudrate to use.
 * @return 0 on success, non-zero error code on failure.
 */
int init_uart(uint32_t baudrate);
```

---

# 🛠️ Automation: Push Changes

- ✅ To push all changes to your remote repository, simply run the following command in your project directory:

  ```sh
  bash git-auto-push.sh
  ```

- ✅ This script will automatically add, commit, and push all changes with a default commit message.
- ✅ You can edit the script to customize the commit message if needed.
- ✅ Use this command whenever you want to push changes, instead of running `git add`, `git commit`, and `git push` separately.

---


End of Ruleset.

---

*This file is maintained and enforced by Agenti AI during every commit and pull request.*

