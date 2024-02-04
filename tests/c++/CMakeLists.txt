cmake_minimum_required(VERSION 3.14)

project(c++_unit_tests CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../..)
include(${PROJECT_DIR}/cmake/paradox-platform.cmake)
include(${PROJECT_DIR}/cmake/googletest.cmake)

add_subdirectory(${PROJECT_DIR}/modules/googletest googletest)

enable_testing()

add_executable(
    unit_tests
    unit_tests.cpp
)

target_link_libraries(
    unit_tests
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(unit_tests)
