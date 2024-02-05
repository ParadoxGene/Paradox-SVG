cmake_minimum_required(VERSION 3.14)

project(c_unit_tests C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../..)
include(${PROJECT_DIR}/cmake/paradox-platform.cmake)
include(${PROJECT_DIR}/cmake/unity.cmake)

add_subdirectory(${PROJECT_DIR}/modules/Unity Unity)

file(GLOB_RECURSE Paradox_SVG_SRC ${PROJECT_DIR}/source/c/**.c)
file(GLOB_RECURSE Paradox_Platform_SRC ${PROJECT_DIR}/modules/Paradox-Platform/source/c/**.c)

add_executable(
    unit_tests
    unit_tests.c
    ${Paradox_SVG_SRC}
    ${Paradox_Platform_SRC}
)

target_include_directories(
    unit_tests PRIVATE
    ${PROJECT_DIR}/source/c/include
    ${PROJECT_DIR}/modules/Paradox-Platform/source/c/include
)

target_link_libraries(
    unit_tests
    unity::framework
)

add_custom_command(
    TARGET unit_tests POST_BUILD 
    COMMAND ${CMAKE_COMMAND} -E copy "${PROJECT_DIR}/tests/assets/example1.svg" "${CMAKE_BINARY_DIR}/$<CONFIG>/example1.svg"
    COMMENT "Copying assets to bin"
)
