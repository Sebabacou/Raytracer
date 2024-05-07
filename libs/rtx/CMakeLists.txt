cmake_minimum_required(VERSION 3.10)

project(rtxlib)
set(LIB_NAME rtxlib)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(SOURCES
    src/color/color.cpp
    src/color/screen.cpp
    src/ray/ray.cpp
    src/vec3/vec3.cpp
    )

add_library(rtxlib STATIC ${SOURCES})

target_include_directories(rtxlib PUBLIC ${PROJECT_SOURCE_DIR}/src)

set_target_properties(${LIB_NAME} PROPERTIES PREFIX "")
add_custom_command(TARGET ${LIB_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:${LIB_NAME}>
        ${PROJECT_SOURCE_DIR}/../$<TARGET_FILE_NAME:${LIB_NAME}>)
