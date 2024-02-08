cmake_minimum_required(VERSION 3.14)
project(c_unit_testing C)

set(PROJECT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../..")

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(LINUX)
    set(CMAKE_C_EXTENSIONS ON)
endif()

include("${PROJECT_DIR}/cmake/unity.cmake")
add_subdirectory("${PROJECT_DIR}/modules/Unity" unity)

add_executable(c_unit_tests "${PROJECT_DIR}/tests/c/unit_tests.c")

target_include_directories(c_unit_tests PRIVATE
    "${PROJECT_DIR}/api/c/include"
    "${PROJECT_DIR}/modules/Paradox-Platform/api/c/include")

target_link_libraries(c_unit_tests PRIVATE paradox-platform paradox-svg unity::framework)

target_link_directories(c_unit_tests PRIVATE
    "${PROJECT_DIR}/build/paradox-platform/c_framework/$<CONFIG>"
    "${PROJECT_DIR}/build/paradox-svg/c_framework/$<CONFIG>")

add_custom_command(TARGET c_unit_tests POST_BUILD 
    COMMAND ${CMAKE_COMMAND} -E copy "${PROJECT_DIR}/tests/assets/example1.svg" "example1.svg"
    COMMENT "Copying assets to bin")