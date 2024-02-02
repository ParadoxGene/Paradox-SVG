cmake_minimum_required(VERSION 3.14)

project(c_unit_tests C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(../../Unity unity)

add_executable(
    unit_tests
    unit_tests.c
)

target_link_libraries(
    unit_tests
    unity::framework
)
