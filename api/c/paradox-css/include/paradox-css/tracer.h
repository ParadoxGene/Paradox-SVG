#ifndef PARADOX_WORKS_C_CSS_TRACER_H
#define PARADOX_WORKS_C_CSS_TRACER_H

#include <paradox-css/defines.h>

typedef struct paradox_css_tracer 
{
    size_t index, length;
    paradox_str_t content;
} paradox_css_tracer;

PARADOX_CSS_API paradox_css_tracer* paradox_css_create_tracer();
PARADOX_CSS_API void paradox_css_destroy_tracer(paradox_css_tracer* tracer);

PARADOX_CSS_API void paradox_css_tracer_load_str(paradox_css_tracer* tracer, paradox_str_t content);

PARADOX_CSS_API void paradox_css_tracer_pop(paradox_css_tracer* tracer);
PARADOX_CSS_API void paradox_css_tracer_pop_seq(paradox_css_tracer* tracer, size_t len);

PARADOX_CSS_API paradox_uint32_t paradox_css_tracer_peek_code(paradox_css_tracer* tracer, size_t* num_bytes);
PARADOX_CSS_API paradox_uint32_t* paradox_css_tracer_peek_code_seq(paradox_css_tracer* tracer, size_t len, size_t num_bytes);

#endif