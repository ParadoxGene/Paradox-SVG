#ifndef PARADOX_WORKS_C_XML_DEFINES_H
#define PARADOX_WORKS_C_XML_DEFINES_H

#include <paradox-platform/defines.h>

#ifdef PARADOX_XML_STATIC
    #define PARADOX_XML_API
#elif PARADOX_XML_BUILD_DLL
    #define PARADOX_XML_API PARADOX_EXPORT
#else
    #define PARADOX_XML_API PARADOX_IMPORT
#endif

#endif