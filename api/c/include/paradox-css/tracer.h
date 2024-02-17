#ifndef PARADOX_WORKS_C_CSS_TRACER_H
#define PARADOX_WORKS_C_CSS_TRACER_H

#include <paradox-svg/defines.h>

typedef struct paradox_css_tracer 
{
    size_t index, length;
    paradox_cstr_t content;
} paradox_css_tracer;

PARADOX_SVG_API paradox_css_tracer* paradox_css_create_tracer();
PARADOX_SVG_API void paradox_css_destroy_tracer(paradox_css_tracer* tracer);
PARADOX_SVG_API void paradox_css_tracer_load_str(paradox_css_tracer* tracer, paradox_cstr_t content);

PARADOX_SVG_API void paradox_css_tracer_pop(paradox_css_tracer* tracer);
PARADOX_SVG_API void paradox_css_tracer_pop_seq(paradox_css_tracer* tracer, size_t num);

PARADOX_SVG_API paradox_uint32_t paradox_css_tracer_peek_code(paradox_css_tracer* tracer);
PARADOX_SVG_API paradox_uint32_t paradox_css_tracer_pop_code(paradox_css_tracer* tracer);

PARADOX_SVG_API paradox_uint32_t* paradox_css_tracer_peek_code_seq(paradox_css_tracer* tracer);
PARADOX_SVG_API paradox_uint32_t* paradox_css_tracer_pop_code_seq(paradox_css_tracer* tracer);

PARADOX_SVG_API paradox_str_t paradox_css_tracer_peek_char(paradox_css_tracer* tracer);
PARADOX_SVG_API paradox_str_t paradox_css_tracer_pop_char(paradox_css_tracer* tracer);

PARADOX_SVG_API paradox_str_t paradox_css_tracer_peek_char_seq(paradox_css_tracer* tracer, size_t num);
PARADOX_SVG_API paradox_str_t paradox_css_tracer_pop_char_seq(paradox_css_tracer* tracer, size_t num);

#endif