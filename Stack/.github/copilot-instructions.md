# Copilot Instructions for stackAndqueues C++ Codebase

## Project Overview
This repository contains C++ implementations of stack and queue data structures, along with related algorithms and problems. Each `.cpp` file typically demonstrates a specific concept or algorithm, often with a `main()` function for demonstration and testing.

## File Structure and Key Files
- `arrayImplimentation.cpp`, `vectorImplimentation.cpp`: Stack/queue using arrays or vectors.
- `LinkedListImplimentation.cpp`: Stack/queue using linked lists.
- `parenthesisValidation.cpp`: Algorithm for validating balanced parentheses using stacks.
- `NextGreatest.cpp`, `previousGreatest.cpp`, `stockSpan.cpp`: Stack-based algorithms for array processing.
- `reverseStackRecursion.cpp`, `reversePrintRecursion.cpp`, `normalPrintRecursion.cpp`: Recursive stack operations.
- `removeConsecutive.cpp`, `push_index.cpp`: Specialized stack/queue problems.

## Build and Run
- There is no build system (e.g., Makefile, CMake). Compile individual files as needed:
  - Example: `g++ parenthesisValidation.cpp -o parenthesisValidation.exe`
- No automated tests are present; validation is via running the compiled executables.

## Coding Patterns and Conventions
- Each file is self-contained, usually with its own `main()`.
- Standard C++ STL is used in some files (see `basicSTL.cpp`).
- Naming: Filenames and functions use camelCase or PascalCase, but are not strictly consistent.
- No external dependencies beyond the C++ standard library.

## Recommendations for AI Agents
- When adding new algorithms, follow the pattern of a single `.cpp` file with a `main()` for demonstration.
- Keep implementations self-contained unless refactoring for shared utilities.
- Reference existing files for examples of stack/queue usage and algorithmic patterns.
- If introducing a build system or tests, document the workflow in this file.

## Example: Compiling and Running
```sh
g++ reverseStackRecursion.cpp -o reverseStackRecursion.exe
./reverseStackRecursion.exe
```

---
For questions about project structure or conventions, review this file and the example `.cpp` files.