#ifndef PARADOX_WORKS_C_CSS_TRACER_H
#define PARADOX_WORKS_C_CSS_TRACER_H

#include <paradox-svg/defines.h>

typedef struct paradox_css_tracer 
{
    size_t index, length;
    paradox_str_t content;
} paradox_css_tracer;

#endif