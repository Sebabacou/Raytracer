CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
set(LIB_NAME parser)

set(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -Werror -g")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/library)

include_directories(${PROJECT_SOURCE_DIR}/src/common)

file(GLOB SOURCES "*.cpp")

add_library(${LIB_NAME} SHARED ${SOURCES})

target_link_libraries(${LIB_NAME} config++)

set_target_properties(${LIB_NAME} PROPERTIES PREFIX "")
add_custom_command(TARGET ${LIB_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:${LIB_NAME}>
        ${PROJECT_SOURCE_DIR}/library/$<TARGET_FILE_NAME:${LIB_NAME}>)