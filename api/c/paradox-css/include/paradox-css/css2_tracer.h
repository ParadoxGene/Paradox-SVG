#ifndef PARADOX_WORKS_C_CSS2_TRACER_H
#define PARADOX_WORKS_C_CSS2_TRACER_H

#include <paradox-css/defines.h>

typedef struct paradox_css2_tracer 
{
    size_t index, length;
    paradox_str_t content;
} paradox_css2_tracer;

PARADOX_CSS_API paradox_css2_tracer* paradox_css2_create_tracer();
PARADOX_CSS_API void paradox_css2_destroy_tracer(paradox_css2_tracer* tracer);

PARADOX_CSS_API void paradox_css2_tracer_load_str(paradox_css2_tracer* tracer, paradox_str_t content);

PARADOX_CSS_API void paradox_css2_tracer_pop(paradox_css2_tracer* tracer);
PARADOX_CSS_API void paradox_css2_tracer_pop_seq(paradox_css2_tracer* tracer, size_t len);

PARADOX_CSS_API paradox_uint32_t paradox_css2_tracer_peek_code(paradox_css2_tracer* tracer, size_t* num_bytes);
PARADOX_CSS_API paradox_uint32_t* paradox_css2_tracer_peek_code_seq(paradox_css2_tracer* tracer, size_t len, size_t num_bytes);

#endif