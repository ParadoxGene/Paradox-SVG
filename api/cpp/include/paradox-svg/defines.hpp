#ifndef PARADOX_WORKS_CPP_SVG_DEFINES_HPP
#define PARADOX_WORKS_CPP_SVG_DEFINES_HPP

#include <inttypes.h>
#include <uchar.h>
#include <wchar.h>
#include <string>

#ifdef _MSC_VER
    // Microsoft C/C++

    #define PARADOX_EXPORT __declspec(dllexport)
    #define PARADOX_IMPORT __declspec(dllimport)
#elif __GNUC__
    // GCC C/C++

    #define PARADOX_EXPORT __attribute__((visibility("default")))
    #define PARADOX_IMPORT
#else
    // Unrecognized Compiler

    #define PARADOX_EXPORT
    #define PARADOX_IMPORT
    #pragma warning Unknown dynamic link import/export semantics.
#endif

#ifdef PARADOX_SVG_STATIC
    #define PARADOX_SVG_API
#elif PARADOX_SVG_BUILD_DLL
    #define PARADOX_SVG_API PARADOX_EXPORT
#else
    #define PARADOX_SVG_API PARADOX_IMPORT
#endif

#endif