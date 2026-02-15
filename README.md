# CPU Benchmark

CPU benchmarking tool written in C++20 to measure single-core and multi-core performance.

---

## Features

- Multi-core and single-core benchmarking
- Loading bar animation while benchmarking
- Results printed to console and saved to `Result.log`
- Configurable cycles and number using `config/config.txt`

---

## Requirements

- C++20 compatible compiler
- CMake 4.1 or higher
- Git (optional, for cloning)

## Configuration
Edit config/config.txt to adjust benchmarking parameters:
- cycles = 10000000000
- num = 3.123141

cycles: Total iterations to perform  
num: Base number used in computation

## Installation

1. Clone the repository:

```bash
git clone https://github.com/dixe1/CPU-Benchmark.git
cd CPU-Benchmark

mkdir build
cd build
cmake ..
cmake --build
```
