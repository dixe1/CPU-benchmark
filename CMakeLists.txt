cmake_minimum_required(VERSION 4.1)
project(Benchmark)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_RELEASE "-O0 -g")

add_executable(Benchmark src/main.cpp
        includes/Menu.h
        includes/GetUserInput.h
        includes/ClearTerminal.h
        includes/Benchmark.h)
