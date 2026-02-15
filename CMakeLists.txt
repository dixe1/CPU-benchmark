cmake_minimum_required(VERSION 3.28.3)
project(Benchmark)

set(CMAKE_CXX_STANDARD 20)

add_executable(Benchmark src/main.cpp
        includes/Menu.h
        includes/GetUserInput.h
        includes/ClearTerminal.h
        includes/Benchmark.h
        includes/PrintAndSaveResult.h
        includes/LoadingBar.h
)
