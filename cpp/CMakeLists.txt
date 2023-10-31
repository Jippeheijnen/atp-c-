cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(atp_cplusplus VERSION 0.1.0)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

# Include dir
include_directories(
        /usr/local/include
        ../extern/pybind11/include
)

# Src
AUX_SOURCE_DIRECTORY(src SRC_FILES)

# Headers
set(PROJECT_SOURCE_DIR "src")
set(PROJECT_INCLUDE_DIR "include/atp_cplusplus_parts")

# Source files
set(SOURCE_FILES
        # headers
        ${PROJECT_INCLUDE_DIR}/VEML6075.hpp
        ${PROJECT_INCLUDE_DIR}/TMC2209.hpp


        # sources
        ${PROJECT_SOURCE_DIR}/VEML6075.cpp
        ${PROJECT_SOURCE_DIR}/TMC2209.cpp
)

# Set up such that XCode organizes the files correctly
source_group(TREE .. FILES ${SOURCE_FILES})

# Add library
add_library(atp_cplusplus SHARED ${SOURCE_FILES})

# Include directories
target_include_directories(atp_cplusplus PRIVATE include/atp_cplusplus_parts)

target_link_libraries(atp_cplusplus ${PYTHON_LIBRARIES})

# Install
install(TARGETS atp_cplusplus DESTINATION lib)

# Install the headers
install(FILES include/atp_cplusplus DESTINATION include)

# Create base directory
install(DIRECTORY include/atp_cplusplus_parts DESTINATION include)