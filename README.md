# Highway Speed Enforcement System (Tutor)

A C++ project developed for the Programming Lab course. This system models a highway speed enforcement mechanism (Tutor) alongside a dedicated simulator to model vehicle traffic and generate transit data.

## Authors

* ⁠**Sebastian Holospin** - [@sebyonn](https://github.com/sebyonn)
  * Designed the overall software architecture for both 'tutor' and 'simulator' modules.
  * Implemented the core logic, data structures, and algorithms.
  * Handled debugging.

*⁠ **Francesco Barban**
  * Configured and optimized the entire build environment via 'CMakeLists.txt' (enabling '-02' compiler optimizations).
  * Contributed to C++ module implementation and component integration.

*⁠ *⁠*Giacomo Alberto Dalla Riva**
  * Managed comprehensive inline code documentation and header comments across all source files.
  * Assisted with code review, formatting, and compliancce with project style guidelines.

---

## Overview

The project consists of two independent executables:

1.⁠ ⁠*⁠simulatore⁠*: Generates randomized vehicle profiles, departure times, and speed trajectories based on highway entry/exit points described in ⁠ Data/Highway.txt ⁠. Outputs logs to ⁠ Data/Runs.txt ⁠ and passage records to ⁠ Data/Passages.txt ⁠.
2.⁠ ⁠*⁠tutor⁠*: Processes the generated passage data chronologically. It monitors vehicles traveling between consecutive highway gates, calculates their average speed against a 130 km/h speed limit, flags violations, and provides statistics via interactive CLI commands (⁠ set_time ⁠, ⁠ stats ⁠, ⁠ reset ⁠).

---

## Requirements

•⁠  ⁠C++11 compiler (or higher)
•⁠  ⁠CMake 3.10+
•⁠  ⁠POSIX-compliant environment (Linux/macOS) or MinGW on Windows

---

## Build Instructions

This project uses CMake for out-of-source builds.

```bash
# 1. Create and enter the build directory
mkdir build
cd build

# 2. Generate Makefiles and compile
cmake ..
make