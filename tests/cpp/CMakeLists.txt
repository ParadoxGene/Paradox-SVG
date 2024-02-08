cmake_minimum_required(VERSION 3.14)
project(cpp_unit_testing CXX)

set(PROJECT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../..")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(LINUX)
    set(CMAKE_CXX_EXTENSIONS ON)
endif()

include("${PROJECT_DIR}/cmake/googletest.cmake")
add_subdirectory("${PROJECT_DIR}/modules/googletest" googletest)

enable_testing()

add_executable(cpp_unit_tests "${PROJECT_DIR}/tests/cpp/unit_tests.cpp")

target_include_directories(cpp_unit_tests PRIVATE
    "${PROJECT_DIR}/api/cpp/include"
    "${PROJECT_DIR}/modules/paradox-platform/api/cpp/include")

target_link_libraries(cpp_unit_tests PRIVATE paradox-platform-framework paradox-svg-framework GTest::gtest_main)

target_link_directories(cpp_unit_tests PRIVATE
    "${PROJECT_DIR}/build/paradox-platform/cpp_framework/$<CONFIG>"
    "${PROJECT_DIR}/build/paradox-svg/cpp_framework/$<CONFIG>")

add_custom_command(TARGET cpp_unit_tests POST_BUILD 
    COMMAND ${CMAKE_COMMAND} -E copy "${PROJECT_DIR}/tests/assets/example1.svg" "example1.svg"
    COMMENT "Copying assets to bin")
    
include(GoogleTest)
gtest_discover_tests(cpp_unit_tests)