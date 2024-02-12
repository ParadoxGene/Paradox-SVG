#ifndef PARADOX_WORKS_C_SVG_TRACER_H
#define PARADOX_WORKS_C_SVG_TRACER_H

#include <paradox-svg/defines.h>

typedef struct paradox_svg_tracer 
{
    size_t index, length;
    paradox_str_t content;
} paradox_svg_tracer;

#endif