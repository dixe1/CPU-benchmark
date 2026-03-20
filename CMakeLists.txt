cmake_minimum_required(VERSION 3.28.3)
project(Benchmark)

set(CMAKE_CXX_STANDARD 23)

include_directories(includes)

add_executable(Benchmark
        src/main.cpp
        src/Benchmark.cpp
        src/ClearTerminal.cpp
        src/ConfigLoader.cpp
        src/GetUserInput.cpp
        src/LoadingBar.cpp
        src/Menu.cpp
        src/PrintAndSaveResult.cpp
        src/Application.cpp
        src/EnableANSI.cpp
        src/GetCPUName.cpp
)
