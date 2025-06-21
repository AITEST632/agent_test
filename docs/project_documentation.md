# Embedded C Project Documentation

## 1. Project Overview
This project is an embedded C firmware application, structured for maintainability, reliability, and scalability. It follows Agenti AI Embedded C Development Rules for code quality, modularity, and best practices.

## 2. Directory Structure
```
/ (root)
│
├── src/                # Application source files
│   ├── main.c          # Main application entry point
│   ├── app/            # Application logic (business logic, state machines)
│   ├── hal/            # Hardware Abstraction Layer (drivers, low-level hardware)
│   └── services/       # Middleware, reusable services (timers, communication, etc.)
│
├── inc/                # Public header files
│   ├── app/
│   ├── hal/
│   └── services/
│
├── tests/              # Unit tests and test hooks
│
├── build/              # Build output (object files, binaries)
│
├── docs/               # Project documentation
│
├── Makefile or CMakeLists.txt  # Build system
│
├── README.md
└── settings.json
```

## 3. Build & CI/CD
- Use the provided `Makefile` or `CMakeLists.txt` for building the project.
- All builds must be reproducible with a single command.
- Build output is placed in the `build/` directory.
- CI pipelines should run static analysis, format checks, and unit tests.

## 4. Coding Standards
- Modular, layered design (HAL, business logic, application).
- Explicit typing for all variables and functions.
- 4 spaces per indent, K&R or Allman style.
- Constants via `#define` or `const` with descriptive names.
- Snake_case for variables/functions, ALL_CAPS for macros.
- Header files use include guards.
- No dynamic memory unless justified.
- All public functions return status codes or error enums.
- Every function has a comment block (purpose, params, return, side effects).

## 5. Testing & Debugging
- Unit tests in `tests/` directory.
- Use preprocessor flags for debug/test code (`#ifdef DEBUG_MODE`).
- No permanent debug prints in production.

## 6. Error Handling
- All errors are handled via status codes or error callbacks.
- Use enums or `#define` for error codes.
- Never silently ignore errors.

## 7. Contribution Guidelines
- Follow the coding standards and directory structure.
- All changes must pass static analysis and unit tests before merging.
- Use meaningful commit messages.
- Code review is mandatory for every pull request.

## 8. License
Specify your project license here.

---

*This document is maintained and enforced by Agenti AI during every commit and pull request.*
