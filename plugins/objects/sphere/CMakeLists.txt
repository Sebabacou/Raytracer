cmake_minimum_required(VERSION 3.10)

# Set the project name
set(LIB_NAME sphere)

# Add the include directories
include_directories({PROJECT_SOURCE_DIR}/includes)
include_directories({PROJECT_SOURCE_DIR}/libs/rtx/src)
include_directories({PROJECT_SOURCE_DIR}/src/raytracing)

# Add the library directory
link_directories({PROJECT_SOURCE_DIR}/libs/rtx)

# Add the source files to the executable
file(GLOB SOURCES "src/*.cpp")
add_library(${LIB_NAME} SHARED ${SOURCES})

# Link the static library to the executable
target_link_libraries(${LIB_NAME} rtxlib)

# Copy the library to the plugins directory
set_target_properties(${LIB_NAME} PROPERTIES PREFIX "")
add_custom_command(TARGET ${LIB_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:${LIB_NAME}>
        ${PROJECT_SOURCE_DIR}/plugins/objects/$<TARGET_FILE_NAME:${LIB_NAME}>)