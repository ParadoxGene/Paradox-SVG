#ifndef PARADOX_WORKS_CPP_XML_DEFINES_HPP
#define PARADOX_WORKS_CPP_XML_DEFINES_HPP

#include <paradox-platform/defines.hpp>

#ifdef PARADOX_XML_STATIC
    #define PARADOX_XML_API
#elif PARADOX_XML_BUILD_DLL
    #define PARADOX_XML_API PARADOX_EXPORT
#else
    #define PARADOX_XML_API PARADOX_IMPORT
#endif

#endif