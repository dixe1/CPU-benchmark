cmake_minimum_required(VERSION 3.10)
project(Benchmark)

set(CMAKE_CXX_STANDARD 23)

include_directories(includes)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/Benchmark.cpp
        src/ClearTerminal.cpp
        src/GetUserInput.cpp
        src/LoadingBar.cpp
        src/Menu.cpp
        src/PrintAndSaveResult.cpp
        src/Application.cpp
        src/EnableANSI.cpp
        src/GetCPUName.cpp
        includes/Config.h
)