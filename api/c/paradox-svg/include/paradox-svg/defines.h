#ifndef PARADOX_WORKS_C_SVG_DEFINES_H
#define PARADOX_WORKS_C_SVG_DEFINES_H

#include <paradox-platform/defines.h>

#ifdef PARADOX_SVG_STATIC
    #define PARADOX_SVG_API
#elif PARADOX_SVG_BUILD_DLL
    #define PARADOX_SVG_API PARADOX_EXPORT
#else
    #define PARADOX_SVG_API PARADOX_IMPORT
#endif

#endif