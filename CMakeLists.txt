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
        src/Benchmark.cpp
        src/ClearTerminal.cpp
        src/ConfigLoader.cpp
        src/GetUserInput.cpp
        src/LoadingBar.cpp
        src/Menu.cpp
        src/PrintAndSaveResult.cpp
        src/Application.cpp
        includes/Application.h
)
