cmake_minimum_required(VERSION 3.10)
project(Benchmark)

set(CMAKE_CXX_STANDARD 23)

include_directories(includes)
include_directories(libs/includes)

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

if (MSVC)
    add_library(ConfigLoader STATIC IMPORTED)
    set_target_properties(ConfigLoader PROPERTIES
            IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/libConfigLoader.lib
            INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/libs/includes
    )
else()
    add_library(ConfigLoader STATIC IMPORTED)
    set_target_properties(ConfigLoader PROPERTIES
            IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/libConfigLoader.a
            INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/libs/includes
    )
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE ConfigLoader)