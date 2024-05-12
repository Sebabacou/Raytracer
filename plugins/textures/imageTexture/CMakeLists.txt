cmake_minimum_required(VERSION 3.10)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)


# Set the project name
set(LIB_NAME imageTexture)

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
target_link_libraries(${LIB_NAME} rtxlib sfml-graphics sfml-window sfml-system)

# Copy the library to the plugins directory
set_target_properties(${LIB_NAME} PROPERTIES PREFIX "")
add_custom_command(TARGET ${LIB_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:${LIB_NAME}>
        ${PROJECT_SOURCE_DIR}/plugins/textures/$<TARGET_FILE_NAME:${LIB_NAME}>)