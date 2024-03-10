#ifndef PARADOX_WORKS_C_CSS_DEFINES_H
#define PARADOX_WORKS_C_CSS_DEFINES_H

#include <paradox-platform/defines.h>

#ifdef PARADOX_CSS_STATIC
    #define PARADOX_CSS_API
#elif PARADOX_CSS_BUILD_DLL
    #define PARADOX_CSS_API PARADOX_EXPORT
#else
    #define PARADOX_CSS_API PARADOX_IMPORT
#endif

#endif