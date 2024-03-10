#ifndef PARADOX_WORKS_C_XML_TRACER_H
#define PARADOX_WORKS_C_XML_TRACER_H

#include <paradox-xml/defines.h>

typedef struct paradox_xml_tracer 
{
    size_t index, length;
    paradox_str_t content;
} paradox_xml_tracer;

#endif