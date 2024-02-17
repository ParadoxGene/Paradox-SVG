#include <paradox-css/lexer.h>
#include <paradox-platform/io.h>
#include <paradox-platform/char.h>
#include <stdlib.h>

PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_file(paradox_cstr_t path)
{
    FILE* file = paradox_bin_dir_fopen(path, "r");
    paradox_css_tracer* tracer = paradox_css_create_tracer();
    tracer->index = 0;
    tracer->content = paradox_file_to_str(file, &tracer->length);

    while(tracer->index <= tracer->length)
    {
        paradox_bool8_t token_found =
            paradox_css_tokenize_ident(tracer)
            || paradox_css_tokenize_atkeyword(tracer)
            || paradox_css_tokenize_string(tracer)
            || paradox_css_tokenize_bad_string(tracer)
            || paradox_css_tokenize_bad_uri(tracer)
            || paradox_css_tokenize_bad_comment(tracer)
            || paradox_css_tokenize_hash(tracer)
            || paradox_css_tokenize_number(tracer)
            || paradox_css_tokenize_percentage(tracer)
            || paradox_css_tokenize_dimension(tracer)
            || paradox_css_tokenize_uri(tracer)
            || paradox_css_tokenize_unicode_range(tracer)
            || paradox_css_tokenize_cdo(tracer)
            || paradox_css_tokenize_cdc(tracer)
            || paradox_css_tokenize_colon(tracer)
            || paradox_css_tokenize_semicolon(tracer)
            || paradox_css_tokenize_open_brace(tracer)
            || paradox_css_tokenize_close_brace(tracer)
            || paradox_css_tokenize_open_parenthesis(tracer)
            || paradox_css_tokenize_close_parenthesis(tracer)
            || paradox_css_tokenize_open_bracket(tracer)
            || paradox_css_tokenize_close_bracket(tracer)
            || paradox_css_tokenize_s(tracer)
            || paradox_css_tokenize_comment(tracer)
            || paradox_css_tokenize_function(tracer)
            || paradox_css_tokenize_includes(tracer)
            || paradox_css_tokenize_dash_match(tracer)
            || paradox_css_tokenize_delim(tracer);
        paradox_css_tracer_pop(tracer);
    }

    paradox_css_destroy_tracer(tracer);
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_ident(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_atkeyword(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_string(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_bad_string(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_bad_uri(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_bad_comment(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_hash(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_number(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_percentage(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_dimension(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_uri(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_unicode_range(paradox_css_tracer* tracer)
{
    size_t index = tracer->index;

    // "u"
    if(!paradox_uchar32_lower_eq(117, paradox_css_tracer_peek_code(tracer))) goto error;
    paradox_css_tracer_pop(tracer);
    
    // "+"
    if(paradox_css_tracer_peek_code(tracer) != 43) goto error;
    paradox_css_tracer_pop(tracer);

    error:
    tracer->index = index;
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_cdo(paradox_css_tracer* tracer)
{
    size_t index = tracer->index;

    // "<"
    if(paradox_css_tracer_peek_code(tracer) != 60) goto error;
    paradox_css_tracer_pop(tracer);

    // "!"
    if(paradox_css_tracer_peek_code(tracer) != 33) goto error;
    paradox_css_tracer_pop(tracer);

    // "-"
    if(paradox_css_tracer_peek_code(tracer) != 45) goto error;
    paradox_css_tracer_pop(tracer);

    // "-"
    if(paradox_css_tracer_peek_code(tracer) != 45) goto error;
    else
    {
        paradox_css_tracer_pop(tracer);
        return PARADOX_TRUE;
    }

    error:
    tracer->index = index;
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_cdc(paradox_css_tracer* tracer)
{
    size_t index = tracer->index;

    // "-"
    if(paradox_css_tracer_peek_code(tracer) != 45) goto error;
    paradox_css_tracer_pop(tracer);

    // "-"
    if(paradox_css_tracer_peek_code(tracer) != 45) goto error;
    paradox_css_tracer_pop(tracer);

    // ">"
    if(paradox_css_tracer_peek_code(tracer) != 62) goto error;
    else
    {
        paradox_css_tracer_pop(tracer);
        return PARADOX_TRUE;
    }

    error:
    tracer->index = index;
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_colon(paradox_css_tracer* tracer)
{
    paradox_uint32_t code = paradox_css_tracer_peek_code(tracer);

    // ":"
    if(code != 58) return PARADOX_FALSE;
    paradox_css_tracer_pop(tracer);
    return PARADOX_TRUE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_semicolon(paradox_css_tracer* tracer)
{
    paradox_uint32_t code = paradox_css_tracer_peek_code(tracer);

    // ";"
    if(code != 59) return PARADOX_FALSE;
    paradox_css_tracer_pop(tracer);
    return PARADOX_TRUE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_open_brace(paradox_css_tracer* tracer)
{
    if(paradox_css_tracer_peek_code(tracer) == 123) // "\{"
    {
        paradox_css_tracer_pop(tracer);
        return PARADOX_TRUE;
    }
    else return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_close_brace(paradox_css_tracer* tracer)
{
    if(paradox_css_tracer_peek_code(tracer) == 125) // "\}"
    {
        paradox_css_tracer_pop(tracer);
        return PARADOX_TRUE;
    }
    else return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_open_parenthesis(paradox_css_tracer* tracer)
{
    if(paradox_css_tracer_peek_code(tracer) == 40) // "\("
    {
        paradox_css_tracer_pop(tracer);
        return PARADOX_TRUE;
    }
    else return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_close_parenthesis(paradox_css_tracer* tracer)
{
    if(paradox_css_tracer_peek_code(tracer) == 41) // "\)"
    {
        paradox_css_tracer_pop(tracer);
        return PARADOX_TRUE;
    }
    else return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_open_bracket(paradox_css_tracer* tracer)
{
    if(paradox_css_tracer_peek_code(tracer) == 91) // "\["
    {
        paradox_css_tracer_pop(tracer);
        return PARADOX_TRUE;
    }
    else return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_close_bracket(paradox_css_tracer* tracer)
{
    if(paradox_css_tracer_peek_code(tracer) == 93) // "\]"
    {
        paradox_css_tracer_pop(tracer);
        return PARADOX_TRUE;
    }
    else return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_s(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_comment(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_function(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_includes(paradox_css_tracer* tracer)
{
    size_t index = tracer->index;

    // "~"
    if(paradox_css_tracer_peek_code(tracer) != 126) goto error;
    paradox_css_tracer_pop(tracer);

    // "="
    if(paradox_css_tracer_peek_code(tracer) != 61) goto error;
    else
    {
        paradox_css_tracer_pop(tracer);
        return PARADOX_TRUE;
    }

    error:
    tracer->index = index;
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_dash_match(paradox_css_tracer* tracer)
{
    size_t index = tracer->index;

    // "|"
    if(paradox_css_tracer_peek_code(tracer) != 124) goto error;
    paradox_css_tracer_pop(tracer);

    // "="
    if(paradox_css_tracer_peek_code(tracer) != 61) goto error;
    else
    {
        paradox_css_tracer_pop(tracer);
        return PARADOX_TRUE;
    }

    error:
    tracer->index = index;
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_tokenize_delim(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}

PARADOX_SVG_API const paradox_bool8_t paradox_css_consume_ident_macro(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_consume_name_macro(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_consume_nmstart_macro(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_consume_nonascii_macro(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_consume_unicode_macro(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_consume_escape_macro(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_consume_nmchar_macro(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_consume_num_macro(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_consume_string_macro(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_consume_string1_macro(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_consume_string2_macro(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_consume_badstring_macro(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_consume_badstring1_macro(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_consume_badstring2_macro(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_consume_badcomment_macro(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_consume_badcomment1_macro(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_consume_badcomment2_macro(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_consume_baduri_macro(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_consume_baduri1_macro(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_consume_baduri2_macro(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_consume_baduri3_macro(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_consume_nl_macro(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}
PARADOX_SVG_API const paradox_bool8_t paradox_css_consume_w_macro(paradox_css_tracer* tracer)
{
    return PARADOX_FALSE;
}