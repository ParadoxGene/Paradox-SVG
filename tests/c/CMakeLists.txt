cmake_minimum_required(VERSION 3.14)

project(c_unit_tests C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../..)
include(${PROJECT_DIR}/cmake/paradox-platform.cmake)
include(${PROJECT_DIR}/cmake/unity.cmake)

add_subdirectory(${PROJECT_DIR}/modules/Unity Unity)

add_executable(
    unit_tests
    unit_tests.c
)

target_link_libraries(
    unit_tests
    unity::framework
)
