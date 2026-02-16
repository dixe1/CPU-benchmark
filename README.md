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

## Build

### 1. Clone the repository
```bash
git clone https://github.com/dixe1/CPU-Benchmark.git
cd CPU-Benchmark
```

### 2. Build Project

#### For Visual Studio 2022:
```bash
cmake -G "Visual Studio 17 2022" -A x64 . -B build
```

#### For Visual Studio 2019:
```bash
cmake -G "Visual Studio 16 2019" -A x64 . -B build
```

#### For Linux / macOS (Unix Makefiles):
```bash
cmake -G "Unix Makefiles" -B build
cmake --build build
```
### 3 Move config folder to built
Move folder "config" from "CPU-Benchmark" to folder where is your binary


