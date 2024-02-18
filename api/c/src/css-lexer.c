#include <paradox-css/lexer.h>
#include <paradox-platform/io.h>
#include <paradox-platform/char.h>

PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_file(paradox_cstr_t path)
{
    FILE* file = paradox_bin_dir_fopen(path, "r");
    paradox_css_tracer* tracer = paradox_css_create_tracer();
    tracer->index = 0;
    tracer->content = paradox_file_to_str(file, &tracer->length);

    while(tracer->index <= tracer->length)
    {
        paradox_css_token* token;
        paradox_bool8_t token_found =
            PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_ident(tracer)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_atkeyword(tracer)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_string(tracer)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_bad_string(tracer)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_bad_uri(tracer)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_bad_comment(tracer)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_hash(tracer)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_number(tracer)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_percentage(tracer)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_dimension(tracer)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_uri(tracer)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_unicode_range(tracer, &token)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_cdo(tracer, &token)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_cdc(tracer, &token)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_colon(tracer, &token)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_semicolon(tracer, &token)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_open_brace(tracer, &token)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_close_brace(tracer, &token)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_open_parenthesis(tracer, &token)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_close_parenthesis(tracer, &token)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_open_bracket(tracer, &token)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_close_bracket(tracer, &token)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_s(tracer)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_comment(tracer)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_function(tracer)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_includes(tracer, &token)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_dash_match(tracer, &token)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_delim(tracer);
        paradox_css_tracer_pop(tracer);
    }

    paradox_css_destroy_tracer(tracer);
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_ident(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_atkeyword(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_string(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_bad_string(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_bad_uri(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_bad_comment(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_hash(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_number(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_percentage(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_dimension(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_uri(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}

PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_unicode_range(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!token) return PARADOX_CSS_LEXER_NO_TOKEN;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_token;
    }
    
    size_t index = tracer->index;
    size_t num_bytes;

    // step 1: "u"
    if(!paradox_uchar32_lower_eq(117, paradox_css_tracer_peek_code(tracer, &num_bytes)))
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto reset_tracer;
    }
    paradox_css_tracer_pop(tracer);
    
    // step 2: "+"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '+')
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto reset_tracer;
    }
    paradox_css_tracer_pop(tracer);

    // step 3: [0-9a-f?]{1, 6}

    paradox_str_t  range_start_ptr = NULL;
    size_t         range_start_len = 0;
    for(paradox_int8_t i = 0; i < 6; ++i)
    {
        paradox_uint32_t c = paradox_css_tracer_peek_code(tracer, &num_bytes);
        if(paradox_uchar32_ishex(c) || '?' == c)
        {
            if(!range_start_ptr) range_start_ptr = tracer->content + tracer->index;
            range_start_len++;
            paradox_css_tracer_pop(tracer);
        }
        else break;
    }
    if(!range_start_ptr)
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto reset_tracer;
    }

    // optional step 4: (-[0-9a-f]{1,6})?
    // step 4a: "-"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '-')
    {
        *token = paradox_css_create_unicode_range_token(range_start_ptr, range_start_len, NULL, 0);
        
        if(*token == NULL)
        {
            err = PARADOX_CSS_LEXER_TOKEN_ALLOC_FAILURE;
            goto reset_tracer;
        }
        else return PARADOX_CSS_LEXER_SUCCESS;
    }
    paradox_css_tracer_pop(tracer);

    // step 4b: [0-9a-f]{1, 6}

    paradox_str_t  range_end_ptr = NULL;
    size_t         range_end_len = 0;
    for(paradox_int8_t i = 0; i < 6; ++i)
    {
        paradox_uint32_t c = paradox_css_tracer_peek_code(tracer, &num_bytes);
        if(paradox_uchar32_ishex(c))
        {
            if(!range_end_ptr) range_end_ptr = tracer->content + tracer->index;
            range_end_len++;
            paradox_css_tracer_pop(tracer);
        }
        else break;
    }
    if(!range_end_ptr)
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto reset_tracer;
    }
    
    *token = paradox_css_create_unicode_range_token(range_start_ptr, range_start_len, range_end_ptr, range_end_len);
    if(*token == NULL)
    {
        err = PARADOX_CSS_LEXER_TOKEN_ALLOC_FAILURE;
        goto reset_tracer;
    }
    else return PARADOX_CSS_LEXER_SUCCESS;

    reset_tracer:
    tracer->index = index;

    null_token:
    *token = NULL;

    return err;
}

PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_cdo(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!tracer) goto null_token;
    size_t index = tracer->index;
    size_t num_bytes;

    // "<"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '<') goto error;
    paradox_css_tracer_pop(tracer);

    // "!"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '!') goto error;
    paradox_css_tracer_pop(tracer);

    // "-"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '-') goto error;
    paradox_css_tracer_pop(tracer);

    // "-"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '-') goto error;
    else
    {
        paradox_css_tracer_pop(tracer);
        if(token) *token = paradox_css_create_cdo_token();
        return PARADOX_CSS_LEXER_SUCCESS;
    }

    error:
    tracer->index = index;

    null_token:
    if(token) *token = NULL;
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_cdc(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!tracer) goto null_token;
    size_t index = tracer->index;
    size_t num_bytes;

    // "-"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '-') goto error;
    paradox_css_tracer_pop(tracer);

    // "-"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '-') goto error;
    paradox_css_tracer_pop(tracer);

    // ">"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '>') goto error;
    else
    {
        paradox_css_tracer_pop(tracer);
        if(token) *token = paradox_css_create_cdc_token();
        return PARADOX_CSS_LEXER_SUCCESS;
    }

    error:
    tracer->index = index;

    null_token:
    if(token) *token = NULL;
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_colon(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!tracer) goto null_token;
    size_t num_bytes;

    // ":"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != ':') goto null_token;
    else
    {
        paradox_css_tracer_pop(tracer);
        if(token) *token = paradox_css_create_colon_token();
        return PARADOX_CSS_LEXER_SUCCESS;
    }

    null_token:
    if(token) *token = NULL;
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_semicolon(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!tracer) goto null_token;
    size_t num_bytes;

    // ";"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != ';') goto null_token;
    else
    {
        paradox_css_tracer_pop(tracer);
        if(token) *token = paradox_css_create_semicolon_token();
        return PARADOX_CSS_LEXER_SUCCESS;
    }

    null_token:
    if(token) *token = NULL;
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_open_brace(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!tracer) goto null_token;
    size_t num_bytes;

    // "{"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '{') goto null_token;
    else
    {
        paradox_css_tracer_pop(tracer);
        if(token) *token = paradox_css_create_open_brace_token();
        return PARADOX_CSS_LEXER_SUCCESS;
    }

    null_token:
    if(token) *token = NULL;
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_close_brace(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!tracer) goto null_token;
    size_t num_bytes;

    // "}"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '}') goto null_token;
    else
    {
        paradox_css_tracer_pop(tracer);
        if(token) *token = paradox_css_create_close_brace_token();
        return PARADOX_CSS_LEXER_SUCCESS;
    }

    null_token:
    if(token) *token = NULL;
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_open_parenthesis(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!tracer) goto null_token;
    size_t num_bytes;

    // "("
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '(') goto null_token;
    else
    {
        paradox_css_tracer_pop(tracer);
        if(token) *token = paradox_css_create_open_paren_token();
        return PARADOX_CSS_LEXER_SUCCESS;
    }

    null_token:
    if(token) *token = NULL;
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_close_parenthesis(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!tracer) goto null_token;
    size_t num_bytes;
    
    // ")"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != ')') goto null_token;
    else
    {
        paradox_css_tracer_pop(tracer);
        if(token) *token = paradox_css_create_close_paren_token();
        return PARADOX_CSS_LEXER_SUCCESS;
    }

    null_token:
    if(token) *token = NULL;
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_open_bracket(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!tracer) goto null_token;
    size_t num_bytes;
    
    // "["
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '[') goto null_token;
    else
    {
        paradox_css_tracer_pop(tracer);
        if(token) *token = paradox_css_create_open_bracket_token();
        return PARADOX_CSS_LEXER_SUCCESS;
    }

    null_token:
    if(token) *token = NULL;
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_close_bracket(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!tracer) goto null_token;
    size_t num_bytes;

    // "]"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != ']') goto null_token;
    else
    {
        paradox_css_tracer_pop(tracer);
        if(token) *token = paradox_css_create_close_bracket_token();
        return PARADOX_CSS_LEXER_SUCCESS;
    }
    
    null_token:
    if(token) *token = NULL;
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_s(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_comment(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_function(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_includes(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!tracer) goto null_token;
    size_t index = tracer->index;
    size_t num_bytes;

    // "~"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '~') goto error;
    paradox_css_tracer_pop(tracer);

    // "="
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '=') goto error;
    else
    {
        paradox_css_tracer_pop(tracer);
        if(token) *token = paradox_css_create_includes_token();
        return PARADOX_CSS_LEXER_SUCCESS;
    }

    error:
    tracer->index = index;

    null_token:
    if(token) *token = NULL;
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_dash_match(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!tracer) goto null_token;
    size_t index = tracer->index;
    size_t num_bytes;

    // "|"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '|') goto error;
    paradox_css_tracer_pop(tracer);

    // "="
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '=') goto error;
    else
    {
        paradox_css_tracer_pop(tracer);
        if(token) *token = paradox_css_create_dashmatch_token();
        return PARADOX_CSS_LEXER_SUCCESS;
    }

    error:
    tracer->index = index;

    null_token:
    if(token) *token = NULL;
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_delim(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}

PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_ident_macro(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_name_macro(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_nmstart_macro(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_nonascii_macro(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_unicode_macro(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_escape_macro(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_nmchar_macro(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_num_macro(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_string_macro(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_string1_macro(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_string2_macro(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_badstring_macro(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_badstring1_macro(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_badstring2_macro(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_badcomment_macro(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_badcomment1_macro(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_badcomment2_macro(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_baduri_macro(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_baduri1_macro(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_baduri2_macro(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_baduri3_macro(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_nl_macro(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_w_macro(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}