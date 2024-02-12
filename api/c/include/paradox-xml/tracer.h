#ifndef PARADOX_WORKS_C_XML_TRACER_H
#define PARADOX_WORKS_C_XML_TRACER

#include <paradox-svg/defines.h>

typedef struct paradox_xml_tracer 
{
    paradox_str_t content;
    size_t index, length;
} paradox_xml_tracer;

#endif