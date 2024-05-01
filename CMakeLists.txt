cmake_minimum_required(VERSION 3.10)

project(beton)

# find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

include_directories(
    # ${SFML_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src/rtx
    ${CMAKE_CURRENT_SOURCE_DIR}/src/raytracer
)

set(SOURCES
    src/rtx/vec3/vec3.cpp
    src/rtx/ray/ray.cpp
    src/raytracer/main.cpp
    src/raytracer/objects/sphere.cpp
    src/raytracer/camera.cpp
    src/raytracer/world.cpp
    src/rtx/color/color.cpp
    src/rtx/color/screen.cpp
    src/raytracer/lights/directionalLight.cpp
    src/raytracer/lights/ambientLight.cpp
    src/raytracer/lights/pointLight.cpp
)

set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)
