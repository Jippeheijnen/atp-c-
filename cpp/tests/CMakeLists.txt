cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(test)

include_directories(/usr/local/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin)

find_library(atp_cplusplus atp_cplusplus HINTS /usr/local/lib/)

add_executable(test
        src/test_VEML6075.cpp
        src/test_TMC2209.cpp)

target_link_libraries(test PUBLIC ${atp_cplusplus})