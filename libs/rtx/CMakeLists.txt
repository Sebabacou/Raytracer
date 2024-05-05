cmake_minimum_required(VERSION 3.10)

project(rtxlib)

set(SOURCES
    src/color/color.cpp
    src/color/screen.cpp
    src/ray/ray.cpp
    src/vec3/vec3.cpp
    )

add_library(rtxlib STATIC ${SOURCES})

target_include_directories(rtxlib PUBLIC ${PROJECT_SOURCE_DIR}/src)
