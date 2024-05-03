cmake_minimum_required(VERSION 3.0)
project(raytracer)

# Set settings for the C++ compiler
set(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -Werror -g")

# Add the include directory to the include path
include_directories(src/)
include_directories(src/parser/)

# Add the source files to the executable for this CMakeLists.txt
add_executable(raytracer
        src/main.cpp
        src/parser/Parser.cpp
        src/parser/Settings.cpp
        src/parser/Object.cpp
        )

# Link the libraries to the executable
target_link_libraries(raytracer
        config++
        )

# Copy the executable to the root directory
add_custom_command(TARGET raytracer POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:raytracer>
        ${PROJECT_SOURCE_DIR}/$<TARGET_FILE_NAME:raytracer>)
