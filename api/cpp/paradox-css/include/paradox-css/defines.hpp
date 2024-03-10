#ifndef PARADOX_WORKS_CPP_CSS_DEFINES_HPP
#define PARADOX_WORKS_CPP_CSS_DEFINES_HPP

#include <paradox-platform/defines.hpp>

#ifdef PARADOX_CSS_STATIC
    #define PARADOX_CSS_API
#elif PARADOX_CSS_BUILD_DLL
    #define PARADOX_CSS_API PARADOX_EXPORT
#else
    #define PARADOX_CSS_API PARADOX_IMPORT
#endif

#endif