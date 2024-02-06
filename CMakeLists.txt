cmake_minimum_required(VERSION 3.14)
project(Paradox-SVG)

set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/.)

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

include(cmake/paradox-platform.cmake)
add_subdirectory(modules/Paradox-Platform ${PROJECT_DIR}/build/paradox-platform)

if(APPLE)
    add_subdirectory(source/swift swift_framework)
elseif(LINUX)
    add_subdirectory(source/c c_framework)
    add_subdirectory(source/c++ c++_framework)
elseif(WIN32)
    add_subdirectory(source/c c_framework)
    add_subdirectory(source/c++ c++_framework)
endif()