cmake_minimum_required(VERSION 3.14)
project(paradox-svg-cpp-framework CXX)

set(PROJECT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../..")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(LINUX)
    set(CMAKE_CXX_EXTENSIONS ON)
endif()

file(GLOB_RECURSE CXX_SRC **.cpp)

add_library(paradox-svg-framework SHARED ${CXX_SRC})

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(paradox-svg-framework PRIVATE -Werror)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(paradox-svg-framework PRIVATE /WX)
endif()
target_compile_definitions(paradox-svg-framework PRIVATE PARADOX_SVG_BUILD_DLL)
target_include_directories(paradox-svg-framework PUBLIC ./include "${PROJECT_DIR}/modules/Paradox-Platform/api/cpp/include")
target_link_directories(paradox-svg-framework PUBLIC "${PROJECT_DIR}/build/paradox-platform/cpp_framework/$<CONFIG>")
target_link_libraries(paradox-svg-framework PUBLIC paradox-platform-framework)