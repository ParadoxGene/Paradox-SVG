cmake_minimum_required(VERSION 3.14)
project(c++_unit_tests)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(../../googletest googletest)

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
