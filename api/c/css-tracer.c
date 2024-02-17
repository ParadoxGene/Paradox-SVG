#include <paradox-css/tracer.h>
#include <stdlib.h>
#include <string.h>

PARADOX_SVG_API paradox_css_tracer* paradox_css_create_tracer()
{
    return malloc(sizeof(paradox_css_tracer));
}

PARADOX_SVG_API void paradox_css_destroy_tracer(paradox_css_tracer* tracer)
{
    if(!tracer) return;

    free(tracer);
}

PARADOX_SVG_API void paradox_css_tracer_load_str(paradox_css_tracer* tracer, paradox_cstr_t content)
{
    if(!tracer) return;

    tracer->content = content;
    tracer->length = strlen(content);
    tracer->index = 0;
}

PARADOX_SVG_API void paradox_css_tracer_pop(paradox_css_tracer* tracer)
{
    tracer->index++;
}
PARADOX_SVG_API void paradox_css_tracer_pop_seq(paradox_css_tracer* tracer, size_t num)
{
    tracer->index += num;
}

PARADOX_SVG_API paradox_uint32_t paradox_css_tracer_peek_code(paradox_css_tracer* tracer)
{
    if(tracer->index > tracer->length) return 0;
    return tracer->content[tracer->index];
}
PARADOX_SVG_API paradox_uint32_t paradox_css_tracer_pop_code(paradox_css_tracer* tracer)
{
    if(tracer->index > tracer->length) return 0;
    return tracer->content[tracer->index++];
}

PARADOX_SVG_API paradox_str_t paradox_css_tracer_peek_char(paradox_css_tracer* tracer)
{
    return NULL;
}
PARADOX_SVG_API paradox_str_t paradox_css_tracer_pop_char(paradox_css_tracer* tracer)
{
    return NULL;
}

PARADOX_SVG_API paradox_str_t paradox_css_tracer_peek_char_seq(paradox_css_tracer* tracer, size_t num)
{
    return NULL;
}
PARADOX_SVG_API paradox_str_t paradox_css_tracer_pop_char_seq(paradox_css_tracer* tracer, size_t num)
{
    return NULL;
}