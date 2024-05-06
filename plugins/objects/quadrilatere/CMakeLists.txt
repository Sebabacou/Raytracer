CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
set(LIB_NAME quadrilatere)

set(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -Werror -g")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins/lights/)

file(GLOB SOURCES "*.cpp")

include_directories(${PROJECT_SOURCE_DIR}/plugins/objects)
include_directories(${PROJECT_SOURCE_DIR}/includes)

add_library(${LIB_NAME} SHARED ${SOURCES})

set_target_properties(${LIB_NAME} PROPERTIES PREFIX "")
add_custom_command(TARGET ${LIB_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:${LIB_NAME}>
        ${PROJECT_SOURCE_DIR}/plugins/objects/$<TARGET_FILE_NAME:${LIB_NAME}>)