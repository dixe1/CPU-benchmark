cmake_minimum_required(VERSION 3.10)
project(Benchmark)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)

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
)

FetchContent_Declare(
        json
        URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(json)

target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)