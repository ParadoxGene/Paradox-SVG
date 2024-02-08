#ifndef PARADOX_WORKS_CPP_SVG_DEFINES_HPP
#define PARADOX_WORKS_CPP_SVG_DEFINES_HPP

#include <paradox-platform/defines.hpp>

#ifdef PARADOX_SVG_STATIC
    #define PARADOX_SVG_API
#elif PARADOX_SVG_BUILD_DLL
    #define PARADOX_SVG_API PARADOX_EXPORT
#else
    #define PARADOX_SVG_API PARADOX_IMPORT
#endif

#endif