cmake_minimum_required(VERSION 3.10)

# Set the project name
project(basicCamera)

# Add the include directories
include_directories(../../../includes)
include_directories(../../../libs/rtx/src)
include_directories(../../../src/raytracing)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs/cameras)

# Add the library directory
link_directories(../../../libs/rtx)

# Add the source files to the executable
file(GLOB SOURCES "src/*.cpp")
add_library(basicCamera SHARED ${SOURCES})

# Link the static library to the executable
target_link_libraries(basicCamera rtxlib)