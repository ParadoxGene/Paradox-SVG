#include <paradox-css/tracer.h>
#include <paradox-platform/characters.h>
#include <stdlib.h>
#include <string.h>

PARADOX_CSS_API paradox_css_tracer* paradox_css_create_tracer()
{ return malloc(sizeof(paradox_css_tracer)); }

PARADOX_CSS_API void paradox_css_destroy_tracer(paradox_css_tracer* tracer)
{
    if(!tracer) return;
    free(tracer);
}

PARADOX_CSS_API void paradox_css_tracer_load_str(paradox_css_tracer* tracer, paradox_str_t content)
{
    if(!tracer) return;

    tracer->content = content;
    tracer->length = strlen(content);
    tracer->index = 0;
}

PARADOX_CSS_API void paradox_css_tracer_pop(paradox_css_tracer* tracer)
{ tracer->index++; }

PARADOX_CSS_API void paradox_css_tracer_pop_seq(paradox_css_tracer* tracer, size_t len)
{ tracer->index += len > 0 ? len : 0; }

PARADOX_CSS_API paradox_uint32_t paradox_css_tracer_peek_code(paradox_css_tracer* tracer, size_t* num_bytes)
{
    if(tracer->index > tracer->length) return 0;
    return paradox_utf8_to_code(tracer->content + tracer->index, num_bytes);
}

PARADOX_CSS_API paradox_uint32_t* paradox_css_tracer_peek_code_seq(paradox_css_tracer* tracer, size_t len, size_t num_bytes)
{
    return NULL;
}
