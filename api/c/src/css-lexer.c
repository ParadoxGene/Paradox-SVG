#include <paradox-css/lexer.h>
#include <paradox-platform/io.h>
#include <paradox-platform/char.h>
#include <paradox-platform/conv.h>
#include <string.h>
#include <stdlib.h>

PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_string_macro_helper(paradox_css_tracer* tracer, const paradox_char8_t quote);
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_badstring_macro_helper(paradox_css_tracer* tracer, const paradox_char8_t quote);

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
            PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_ident(tracer, &token)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_atkeyword(tracer, &token)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_string(tracer, &token)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_bad_string(tracer, &token)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_bad_uri(tracer, &token)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_bad_comment(tracer, &token)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_hash(tracer, &token)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_number(tracer, &token)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_percentage(tracer, &token)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_dimension(tracer, &token)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_uri(tracer, &token)
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
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_s(tracer, &token)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_comment(tracer, &token)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_function(tracer, &token)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_includes(tracer, &token)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_dash_match(tracer, &token)
            || PARADOX_CSS_LEXER_SUCCESS == paradox_css_tokenize_delim(tracer, &token);
        paradox_css_tracer_pop(tracer);
    }

    paradox_css_destroy_tracer(tracer);
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_ident(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!token) return PARADOX_CSS_LEXER_NO_TOKEN;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_token;
    }

/*
    size_t index = tracer->index;
    size_t num_bytes;
    
    // TODO
    err = PARADOX_CSS_LEXER_INVALID_CONTENT;

    reset_tracer:
    tracer->index = index;
*/

    null_token:
    *token = NULL;
    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_atkeyword(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!token) return PARADOX_CSS_LEXER_NO_TOKEN;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_token;
    }

/*
    size_t index = tracer->index;
    size_t num_bytes;
    
    // TODO
    err = PARADOX_CSS_LEXER_INVALID_CONTENT;

    reset_tracer:
    tracer->index = index;
*/

    null_token:
    *token = NULL;
    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_string(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!token) return PARADOX_CSS_LEXER_NO_TOKEN;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_token;
    }

/*
    size_t index = tracer->index;
    size_t num_bytes;
    
    // TODO
    err = PARADOX_CSS_LEXER_INVALID_CONTENT;

    reset_tracer:
    tracer->index = index;
*/

    null_token:
    *token = NULL;
    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_bad_string(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!token) return PARADOX_CSS_LEXER_NO_TOKEN;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_token;
    }

/*
    size_t index = tracer->index;
    size_t num_bytes;
    
    // TODO
    err = PARADOX_CSS_LEXER_INVALID_CONTENT;

    reset_tracer:
    tracer->index = index;
*/

    null_token:
    *token = NULL;
    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_bad_uri(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!token) return PARADOX_CSS_LEXER_NO_TOKEN;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_token;
    }

/*
    size_t index = tracer->index;
    size_t num_bytes;
    
    // TODO
    err = PARADOX_CSS_LEXER_INVALID_CONTENT;

    reset_tracer:
    tracer->index = index;
*/

    null_token:
    *token = NULL;
    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_bad_comment(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!token) return PARADOX_CSS_LEXER_NO_TOKEN;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_token;
    }

/*
    size_t index = tracer->index;
    size_t num_bytes;
    
    // TODO
    err = PARADOX_CSS_LEXER_INVALID_CONTENT;

    reset_tracer:
    tracer->index = index;
*/

    null_token:
    *token = NULL;
    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_hash(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!token) return PARADOX_CSS_LEXER_NO_TOKEN;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_token;
    }

/*
    size_t index = tracer->index;
    size_t num_bytes;
    
    // TODO
    err = PARADOX_CSS_LEXER_INVALID_CONTENT;

    reset_tracer:
    tracer->index = index;
*/

    null_token:
    *token = NULL;
    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_number(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!token) return PARADOX_CSS_LEXER_NO_TOKEN;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_token;
    }

/*
    size_t index = tracer->index;
    size_t num_bytes;
    
    // TODO
    err = PARADOX_CSS_LEXER_INVALID_CONTENT;

    reset_tracer:
    tracer->index = index;
*/

    null_token:
    *token = NULL;
    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_percentage(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!token) return PARADOX_CSS_LEXER_NO_TOKEN;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_token;
    }

/*
    size_t index = tracer->index;
    size_t num_bytes;
    
    // TODO
    err = PARADOX_CSS_LEXER_INVALID_CONTENT;

    reset_tracer:
    tracer->index = index;
*/

    null_token:
    *token = NULL;
    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_dimension(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!token) return PARADOX_CSS_LEXER_NO_TOKEN;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_token;
    }

/*
    size_t index = tracer->index;
    size_t num_bytes;
    
    // TODO
    err = PARADOX_CSS_LEXER_INVALID_CONTENT;

    reset_tracer:
    tracer->index = index;
*/

    null_token:
    *token = NULL;
    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_uri(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!token) return PARADOX_CSS_LEXER_NO_TOKEN;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_token;
    }

/*
    size_t index = tracer->index;
    size_t num_bytes;
    
    // TODO
    err = PARADOX_CSS_LEXER_INVALID_CONTENT;

    reset_tracer:
    tracer->index = index;
*/

    null_token:
    *token = NULL;
    return err;
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
    if(!token) return PARADOX_CSS_LEXER_NO_TOKEN;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_token;
    }

    size_t index = tracer->index;
    size_t num_bytes;

    // "<"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '<')
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto reset_tracer;
    }
    paradox_css_tracer_pop(tracer);

    // "!"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '!')
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto reset_tracer;
    }
    paradox_css_tracer_pop(tracer);

    // "-"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '-')
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto reset_tracer;
    }
    paradox_css_tracer_pop(tracer);

    // "-"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '-')
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto reset_tracer;
    }
    else
    {
        paradox_css_tracer_pop(tracer);
        *token = paradox_css_create_cdo_token();
        if(*token == NULL)
        {
            err = PARADOX_CSS_LEXER_TOKEN_ALLOC_FAILURE;
            goto reset_tracer;
        }
        else return PARADOX_CSS_LEXER_SUCCESS;
    }

    reset_tracer:
    tracer->index = index;

    null_token:
    *token = NULL;
    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_cdc(paradox_css_tracer* tracer, paradox_css_token** token)
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

    // "-"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '-')
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto reset_tracer;
    }
    paradox_css_tracer_pop(tracer);

    // "-"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '-')
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto reset_tracer;
    }
    paradox_css_tracer_pop(tracer);

    // ">"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '>')
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto reset_tracer;
    }
    else
    {
        paradox_css_tracer_pop(tracer);
        *token = paradox_css_create_cdc_token();
        if(*token == NULL)
        {
            err = PARADOX_CSS_LEXER_TOKEN_ALLOC_FAILURE;
            goto reset_tracer;
        }
        else return PARADOX_CSS_LEXER_SUCCESS;
    }

    reset_tracer:
    tracer->index = index;

    null_token:
    *token = NULL;
    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_colon(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!token) return PARADOX_CSS_LEXER_NO_TOKEN;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_token;
    }

    size_t num_bytes;

    // ":"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != ':')
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto null_token;
    }
    else
    {
        paradox_css_tracer_pop(tracer);
        *token = paradox_css_create_colon_token();
        if(*token == NULL)
        {
            err = PARADOX_CSS_LEXER_TOKEN_ALLOC_FAILURE;
            goto null_token;
        }
        else return PARADOX_CSS_LEXER_SUCCESS;
    }

    null_token:
    *token = NULL;
    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_semicolon(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!token) return PARADOX_CSS_LEXER_NO_TOKEN;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_token;
    }

    size_t num_bytes;

    // ";"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != ';')
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto null_token;
    }
    else
    {
        paradox_css_tracer_pop(tracer);
        *token = paradox_css_create_semicolon_token();
        if(*token == NULL)
        {
            err = PARADOX_CSS_LEXER_TOKEN_ALLOC_FAILURE;
            goto null_token;
        }
        else return PARADOX_CSS_LEXER_SUCCESS;
    }

    null_token:
    *token = NULL;
    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_open_brace(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!token) return PARADOX_CSS_LEXER_NO_TOKEN;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_token;
    }

    size_t num_bytes;

    // "{"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '{')
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto null_token;
    }
    else
    {
        paradox_css_tracer_pop(tracer);
        *token = paradox_css_create_open_brace_token();
        if(*token == NULL)
        {
            err = PARADOX_CSS_LEXER_TOKEN_ALLOC_FAILURE;
            goto null_token;
        }
        else return PARADOX_CSS_LEXER_SUCCESS;
    }

    null_token:
    *token = NULL;
    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_close_brace(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!token) return PARADOX_CSS_LEXER_NO_TOKEN;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_token;
    }

    size_t num_bytes;

    // "}"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '}')
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto null_token;
    }
    else
    {
        paradox_css_tracer_pop(tracer);
        *token = paradox_css_create_close_brace_token();
        if(*token == NULL)
        {
            err = PARADOX_CSS_LEXER_TOKEN_ALLOC_FAILURE;
            goto null_token;
        }
        else return PARADOX_CSS_LEXER_SUCCESS;
    }

    null_token:
    *token = NULL;
    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_open_parenthesis(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!token) return PARADOX_CSS_LEXER_NO_TOKEN;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_token;
    }

    size_t num_bytes;

    // "("
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '(')
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto null_token;
    }
    else
    {
        paradox_css_tracer_pop(tracer);
        *token = paradox_css_create_open_paren_token();
        if(*token == NULL)
        {
            err = PARADOX_CSS_LEXER_TOKEN_ALLOC_FAILURE;
            goto null_token;
        }
        else return PARADOX_CSS_LEXER_SUCCESS;
    }

    null_token:
    *token = NULL;
    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_close_parenthesis(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!token) return PARADOX_CSS_LEXER_NO_TOKEN;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_token;
    }

    size_t num_bytes;
    
    // ")"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != ')')
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto null_token;
    }
    else
    {
        paradox_css_tracer_pop(tracer);
        if(token) *token = paradox_css_create_close_paren_token();
        return PARADOX_CSS_LEXER_SUCCESS;
    }

    null_token:
    *token = NULL;
    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_open_bracket(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!token) return PARADOX_CSS_LEXER_NO_TOKEN;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_token;
    }

    size_t num_bytes;
    
    // "["
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '[')
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto null_token;
    }
    else
    {
        paradox_css_tracer_pop(tracer);
        *token = paradox_css_create_open_bracket_token();
        if(*token == NULL)
        {
            err = PARADOX_CSS_LEXER_TOKEN_ALLOC_FAILURE;
            goto null_token;
        }
        else return PARADOX_CSS_LEXER_SUCCESS;
    }

    null_token:
    *token = NULL;
    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_close_bracket(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!token) return PARADOX_CSS_LEXER_NO_TOKEN;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_token;
    }

    size_t num_bytes;

    // "]"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != ']')
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto null_token;
    }
    else
    {
        paradox_css_tracer_pop(tracer);
        *token = paradox_css_create_close_bracket_token();
        if(*token == NULL)
        {
            err = PARADOX_CSS_LEXER_TOKEN_ALLOC_FAILURE;
            goto null_token;
        }
        else return PARADOX_CSS_LEXER_SUCCESS;
    }
    
    null_token:
    *token = NULL;
    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_s(paradox_css_tracer* tracer, paradox_css_token** token)
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

    // [ \t\r\n\f]+

    paradox_uint32_t c = paradox_css_tracer_peek_code(tracer, &num_bytes);
    paradox_bool8_t found = PARADOX_FALSE;
    paradox_bool8_t done_checking = PARADOX_FALSE;
    while(!done_checking) switch(c)
    {
    case  ' ':
    case '\t':
    case '\r':
    case '\n':
    case '\f':
        paradox_css_tracer_pop(tracer);
        found = PARADOX_TRUE;
        break;

    default:
        done_checking = PARADOX_TRUE;
        break;
    }

    if(!found)
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto reset_tracer;
    }
    else
    {
        paradox_css_tracer_pop(tracer);
        *token = paradox_css_create_space_token();
        if(*token == NULL)
        {
            err = PARADOX_CSS_LEXER_TOKEN_ALLOC_FAILURE;
            goto null_token;
        }
        else return PARADOX_CSS_LEXER_SUCCESS;
    }

    reset_tracer:
    tracer->index = index;

    null_token:
    *token = NULL;
    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_comment(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!token) return PARADOX_CSS_LEXER_NO_TOKEN;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_token;
    }

/*
    size_t index = tracer->index;
    size_t num_bytes;
    
    // TODO
    err = PARADOX_CSS_LEXER_INVALID_CONTENT;

    reset_tracer:
    tracer->index = index;
*/

    null_token:
    *token = NULL;
    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_function(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!token) return PARADOX_CSS_LEXER_NO_TOKEN;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_token;
    }

/*
    size_t index = tracer->index;
    size_t num_bytes;
    
    // TODO
    err = PARADOX_CSS_LEXER_INVALID_CONTENT;

    reset_tracer:
    tracer->index = index;
*/

    null_token:
    *token = NULL;
    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_includes(paradox_css_tracer* tracer, paradox_css_token** token)
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

    // "~"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '~')
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto reset_tracer;
    }
    paradox_css_tracer_pop(tracer);

    // "="
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '=')
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto reset_tracer;
    }
    else
    {
        paradox_css_tracer_pop(tracer);
        *token = paradox_css_create_includes_token();
        if(*token == NULL)
        {
            err = PARADOX_CSS_LEXER_TOKEN_ALLOC_FAILURE;
            goto reset_tracer;
        }
        else return PARADOX_CSS_LEXER_SUCCESS;
    }

    reset_tracer:
    tracer->index = index;

    null_token:
    *token = NULL;
    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_dash_match(paradox_css_tracer* tracer, paradox_css_token** token)
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

    // "|"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '|')
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto reset_tracer;
    }
    paradox_css_tracer_pop(tracer);

    // "="
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '=')
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto reset_tracer;
    }
    else
    {
        paradox_css_tracer_pop(tracer);
        *token = paradox_css_create_dashmatch_token();
        if(*token == NULL)
        {
            err = PARADOX_CSS_LEXER_TOKEN_ALLOC_FAILURE;
            goto reset_tracer;
        }
        else return PARADOX_CSS_LEXER_SUCCESS;
    }

    reset_tracer:
    tracer->index = index;

    null_token:
    *token = NULL;
    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_delim(paradox_css_tracer* tracer, paradox_css_token** token)
{
    if(!token) return PARADOX_CSS_LEXER_NO_TOKEN;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_token;
    }

 /*
    size_t num_bytes;

    // TODO
    err = PARADOX_CSS_LEXER_INVALID_CONTENT;
*/

    null_token:
    *token = NULL;
    return err;
}

PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_ident_macro(paradox_css_tracer* tracer, paradox_str_t* string_val)
{
    if(!string_val) return PARADOX_CSS_LEXER_NO_STRING;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_string;
    }
    
    size_t index = tracer->index;
    size_t num_bytes;
    paradox_uint32_t code;

    // [-]?
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) == '-')
        paradox_css_tracer_pop(tracer);

    // {nmstart}
    if(PARADOX_CSS_LEXER_SUCCESS != (err = paradox_css_consume_nmstart_macro(tracer, &code)))
        goto reset_tracer;

    // {nmchar}*
    while(PARADOX_CSS_LEXER_SUCCESS == paradox_css_consume_nmchar_macro(tracer,&code));

    // allocate string

    size_t len = tracer->index - index;
    *string_val = malloc(sizeof(paradox_char8_t) * (len + 1));
    strncpy(*string_val, tracer->content + index, len);
    (*string_val)[len] = '\0';

    return PARADOX_CSS_LEXER_SUCCESS;

    reset_tracer:
    tracer->index = index;

    null_string:
    *string_val = NULL;
    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_name_macro(paradox_css_tracer* tracer, paradox_str_t* string_val)
{
    if(!string_val) return PARADOX_CSS_LEXER_NO_STRING;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_string;
    }
    
    size_t index = tracer->index;

    // {nmchar}+

    paradox_bool8_t found = PARADOX_FALSE;
    paradox_bool8_t done_checking = PARADOX_FALSE;
    while(!done_checking){
        paradox_uint32_t c;
        if(paradox_css_consume_nmchar_macro(tracer, &c))
            found = PARADOX_TRUE;
        else done_checking = PARADOX_TRUE;
    }

    if(!found)
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto reset_tracer;
    }
    else
    {
        // allocate string

        size_t len = tracer->index - index;
        *string_val = malloc(sizeof(paradox_char8_t) * (len + 1));
        strncpy(*string_val, tracer->content + index, len);
        (*string_val)[len] = '\0';

        return PARADOX_CSS_LEXER_SUCCESS;
    }

    reset_tracer:
    tracer->index = index;

    null_string:
    *string_val = NULL;
    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_nmstart_macro(paradox_css_tracer* tracer, paradox_uint32_t* code)
{
    if(!code) return PARADOX_CSS_LEXER_NO_UTF8_CODE;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_code;
    }
    
    size_t num_bytes;

    // step 1a: {nonascii} | {escape}
    if(PARADOX_CSS_LEXER_SUCCESS == paradox_css_consume_escape_macro(tracer, code)
    || PARADOX_CSS_LEXER_SUCCESS == paradox_css_consume_nonascii_macro(tracer, code))
        return PARADOX_CSS_LEXER_SUCCESS;

    // step 1b: [_a-z]
    *code = paradox_css_tracer_peek_code(tracer, &num_bytes);
    if(!(*code == '_' || ('a' <= *code && *code <= 'z') || ('A' <= *code && *code <= 'Z')))
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto null_code;
    }
    else
    {
        paradox_css_tracer_pop(tracer);
        return PARADOX_CSS_LEXER_SUCCESS;
    }

    null_code:
    code = NULL;

    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_nonascii_macro(paradox_css_tracer* tracer, paradox_uint32_t* code)
{
    if(!code) return PARADOX_CSS_LEXER_NO_UTF8_CODE;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_code;
    }

    size_t num_bytes;

    // [^\0-\237]
    *code = paradox_css_tracer_peek_code(tracer, &num_bytes);
    if(*code <= 0237)
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto null_code;
    }
    else if(*code == PARADOX_UTF8_ERR_CODE)
    {
        err = PARADOX_CSS_LEXER_UNKNOWN_UTF8_CODE;
        goto null_code;
    }
    else
    {
        paradox_css_tracer_pop_seq(tracer, num_bytes);
        return PARADOX_CSS_LEXER_SUCCESS;
    }

    null_code:
    code = NULL;

    return err;
}

PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_unicode_macro(paradox_css_tracer* tracer, paradox_uint32_t* code)
{
    if(!code) return PARADOX_CSS_LEXER_NO_UTF8_CODE;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_code;
    }

    size_t index = tracer->index;
    size_t num_bytes;
    
    // 	\\[0-9a-f]{1,6}(\r\n|[ \n\r\t\f])?

    // "\"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '\\')
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto null_code;
    }
    paradox_css_tracer_pop(tracer);

    // [0-9a-f]{1,6}
    
    paradox_str_t  hex_ptr = NULL;
    size_t         hex_len = 0;
    for(paradox_int8_t i = 0; i < 6; ++i)
    {
        paradox_uint32_t c = paradox_css_tracer_peek_code(tracer, &num_bytes);
        if(paradox_uchar32_ishex(c))
        {
            if(!hex_ptr) hex_ptr = tracer->content + tracer->index;
            hex_len++;
            paradox_css_tracer_pop(tracer);
        }
        else break;
    }
    if(!hex_ptr)
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto reset_tracer;
    }

    if(!paradox_hex_to_uint32(hex_ptr, hex_len, code) || !paradox_uchar32_isunicode(*code))
    {
        err = PARADOX_CSS_LEXER_UNKNOWN_UTF8_CODE;
        goto reset_tracer;
    }

    // (\r\n|[ \n\r\t\f])?
    switch(paradox_css_tracer_peek_code(tracer, &num_bytes))
    {
    case  ' ':
    case '\t':
    case '\n':
    case '\f':
        paradox_css_tracer_pop(tracer);
        break;

    case '\r': {
        paradox_css_tracer_pop(tracer);
        if(paradox_css_tracer_peek_code(tracer, &num_bytes) == '\n')
            paradox_css_tracer_pop(tracer);
        break;
    }
    default:
        break;
    }

    return PARADOX_CSS_LEXER_SUCCESS;

    reset_tracer:
    tracer->index = index;

    null_code:
    code = NULL;

    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_escape_macro(paradox_css_tracer* tracer, paradox_uint32_t* code)
{
    if(!code) return PARADOX_CSS_LEXER_NO_UTF8_CODE;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_code;
    }

    size_t index = tracer->index;
    size_t num_bytes;

    // step 1a: {unicode}
    if(PARADOX_CSS_LEXER_SUCCESS == paradox_css_consume_unicode_macro(tracer, code))
        return PARADOX_CSS_LEXER_SUCCESS;
    
    // step 1b: "\" "[^\n\r\f0-9a-f]"

    // "\"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '\\')
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto null_code;
    }
    paradox_css_tracer_pop(tracer);

    // "[^\n\r\f0-9a-f]"
    switch(*code = paradox_css_tracer_peek_code(tracer, &num_bytes))
    {
    case '\n':
    case '\r':
    case '\f':
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto reset_tracer;
    
    default: {
        if(paradox_uchar32_ishex(*code))
        {
            err = PARADOX_CSS_LEXER_INVALID_CONTENT;
            goto reset_tracer;
        }
        else return PARADOX_CSS_LEXER_SUCCESS;
    }}

    reset_tracer:
    tracer->index = index;

    null_code:
    code = NULL;

    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_nmchar_macro(paradox_css_tracer* tracer, paradox_uint32_t* code)
{
    if(!code) return PARADOX_CSS_LEXER_NO_UTF8_CODE;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_code;
    }
    
    size_t num_bytes;

    // step 1a: {nonascii} | {escape}
    if(PARADOX_CSS_LEXER_SUCCESS == paradox_css_consume_escape_macro(tracer, code)
    || PARADOX_CSS_LEXER_SUCCESS == paradox_css_consume_nonascii_macro(tracer, code))
        return PARADOX_CSS_LEXER_SUCCESS;

    // step 1b: [_a-z0-9-]
    *code = paradox_css_tracer_peek_code(tracer, &num_bytes);
    if(!(*code == '_' || *code == '-' || ('a' <= *code && *code <= 'z') || ('A' <= *code && *code <= 'Z') || ('0' <= *code && *code <= '9')))
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto null_code;
    }
    else
    {
        paradox_css_tracer_pop(tracer);
        return PARADOX_CSS_LEXER_SUCCESS;
    }

    null_code:
    code = NULL;

    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_num_macro(paradox_css_tracer* tracer)
{
    return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_string_macro(paradox_css_tracer* tracer, paradox_str_t* string_val)
{
    if(PARADOX_CSS_LEXER_SUCCESS == paradox_css_consume_string1_macro(tracer, string_val)
    || PARADOX_CSS_LEXER_SUCCESS == paradox_css_consume_string2_macro(tracer, string_val))
        return PARADOX_CSS_LEXER_SUCCESS;
    else
        return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_string1_macro(paradox_css_tracer* tracer, paradox_str_t* string_val)
{
    if(!string_val) return PARADOX_CSS_LEXER_NO_STRING;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_string;
    }

    size_t index = tracer->index;
    if(PARADOX_CSS_LEXER_SUCCESS != (err = paradox_css_consume_string_macro_helper(tracer, '"')))
        goto reset_tracer;
    else
    {
        // allocate string

        size_t len = tracer->index - index;
        *string_val = malloc(sizeof(paradox_char8_t) * (len + 1));
        strncpy(*string_val, tracer->content + index, len);
        (*string_val)[len] = '\0';

        return PARADOX_CSS_LEXER_SUCCESS;
    }
    
    reset_tracer:
    tracer->index = index;

    null_string:
    *string_val = NULL;

    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_string2_macro(paradox_css_tracer* tracer, paradox_str_t* string_val)
{
    if(!string_val) return PARADOX_CSS_LEXER_NO_STRING;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_string;
    }

    size_t index = tracer->index;
    if(PARADOX_CSS_LEXER_SUCCESS != (err = paradox_css_consume_string_macro_helper(tracer, '\'')))
        goto reset_tracer;
    else
    {
        // allocate string

        size_t len = tracer->index - index;
        *string_val = malloc(sizeof(paradox_char8_t) * (len + 1));
        strncpy(*string_val, tracer->content + index, len);
        (*string_val)[len] = '\0';

        return PARADOX_CSS_LEXER_SUCCESS;
    }
    
    reset_tracer:
    tracer->index = index;

    null_string:
    *string_val = NULL;

    return err;
}
/** Helper Reads Macro:
 * \ " ( [ ^ \ n \ r \ f \ \ " ] | \ \ { n l } | { e s c a p e } ) * \ "
 * or
 * \ ' ( [ ^ \ n \ r \ f \ \ ' ] | \ \ { n l } | { e s c a p e } ) * \ ' */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_string_macro_helper(paradox_css_tracer* tracer, const paradox_char8_t quote)
{
    size_t num_bytes;
    paradox_uint32_t code;

    // "
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != quote)
        return PARADOX_CSS_LEXER_INVALID_CONTENT;
    paradox_css_tracer_pop(tracer);

    size_t index = tracer->index;
    // ([^\n\r\f\\"]|\\{nl}|{escape})*
    while(PARADOX_TRUE)
    {
        paradox_bool8_t found = PARADOX_FALSE;
        

        // [^\n\r\f\\']
        if(!found) switch(code = paradox_css_tracer_peek_code(tracer, &num_bytes))
        {
        case '\n':
        case '\r':
        case '\f':
        case '\\':
            break;

        default: {
            if(code != quote && code != PARADOX_UTF8_ERR_CODE)
            {
                paradox_css_tracer_pop_seq(tracer, num_bytes);
                found = PARADOX_TRUE;
            }
            break;
        }}

        // \\{nl}
        if(!found)
        {
            if(paradox_css_tracer_peek_code(tracer, &num_bytes) == '\\')
            {
                paradox_css_tracer_pop(tracer);
                if(PARADOX_CSS_LEXER_SUCCESS != paradox_css_consume_nl_macro(tracer))
                    index = tracer->index;
                else found = PARADOX_TRUE;
            }
        }

        // {escape}
        if(!found) found = (PARADOX_CSS_LEXER_SUCCESS == paradox_css_consume_escape_macro(tracer, &code)) ? PARADOX_TRUE : PARADOX_FALSE;
        if(!found) break;
    }
   
    // "
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != quote)
    {
        tracer->index = index;
        return PARADOX_CSS_LEXER_INVALID_CONTENT;
    }
    paradox_css_tracer_pop(tracer);

    return PARADOX_CSS_LEXER_SUCCESS;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_badstring_macro(paradox_css_tracer* tracer, paradox_str_t* string_val)
{
    if(PARADOX_CSS_LEXER_SUCCESS == paradox_css_consume_badstring1_macro(tracer, string_val)
    || PARADOX_CSS_LEXER_SUCCESS == paradox_css_consume_badstring2_macro(tracer, string_val))
        return PARADOX_CSS_LEXER_SUCCESS;
    else
        return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_badstring1_macro(paradox_css_tracer* tracer, paradox_str_t* string_val)
{
    if(!string_val) return PARADOX_CSS_LEXER_NO_STRING;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_string;
    }

    size_t index = tracer->index;
    if(PARADOX_CSS_LEXER_SUCCESS != (err = paradox_css_consume_badstring_macro_helper(tracer, '"')))
        goto reset_tracer;
    else
    {
        // allocate string

        size_t len = tracer->index - index;
        *string_val = malloc(sizeof(paradox_char8_t) * (len + 1));
        strncpy(*string_val, tracer->content + index, len);
        (*string_val)[len] = '\0';

        return PARADOX_CSS_LEXER_SUCCESS;
    }
    
    reset_tracer:
    tracer->index = index;

    null_string:
    *string_val = NULL;

    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_badstring2_macro(paradox_css_tracer* tracer, paradox_str_t* string_val)
{
    if(!string_val) return PARADOX_CSS_LEXER_NO_STRING;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_string;
    }

    size_t index = tracer->index;
    if(PARADOX_CSS_LEXER_SUCCESS != (err = paradox_css_consume_badstring_macro_helper(tracer, '\'')))
        goto reset_tracer;
    else
    {
        // allocate string

        size_t len = tracer->index - index;
        *string_val = malloc(sizeof(paradox_char8_t) * (len + 1));
        strncpy(*string_val, tracer->content + index, len);
        (*string_val)[len] = '\0';

        return PARADOX_CSS_LEXER_SUCCESS;
    }
    
    reset_tracer:
    tracer->index = index;

    null_string:
    *string_val = NULL;

    return err;
}

/** Helper Reads Macro:
 * \ " ( [ ^ \ n \ r \ f \ \ " ] | \ \ { n l } | { e s c a p e } ) * \ \ ?
 * or
 * \ ' ( [ ^ \ n \ r \ f \ \ ' ] | \ \ { n l } | { e s c a p e } ) * \ \ ? */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_badstring_macro_helper(paradox_css_tracer* tracer, const paradox_char8_t quote)
{
    size_t num_bytes;
    paradox_uint32_t code;

    // "
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != quote)
        return PARADOX_CSS_LEXER_INVALID_CONTENT;
    paradox_css_tracer_pop(tracer);

    size_t index = tracer->index;
    // ([^\n\r\f\\"]|\\{nl}|{escape})*
    while(PARADOX_TRUE)
    {
        paradox_bool8_t found = PARADOX_FALSE;
        

        // [^\n\r\f\\']
        if(!found) switch(code = paradox_css_tracer_peek_code(tracer, &num_bytes))
        {
        case '\n':
        case '\r':
        case '\f':
        case '\\':
            break;

        default: {
            if(code != quote && code != PARADOX_UTF8_ERR_CODE)
            {
                paradox_css_tracer_pop_seq(tracer, num_bytes);
                found = PARADOX_TRUE;
            }
            break;
        }}

        // \\{nl}
        if(!found)
        {
            if(paradox_css_tracer_peek_code(tracer, &num_bytes) == '\\')
            {
                paradox_css_tracer_pop(tracer);
                if(PARADOX_CSS_LEXER_SUCCESS != paradox_css_consume_nl_macro(tracer))
                    index = tracer->index;
                else found = PARADOX_TRUE;
            }
        }

        // {escape}
        if(!found) found = (PARADOX_CSS_LEXER_SUCCESS == paradox_css_consume_escape_macro(tracer, &code)) ? PARADOX_TRUE : PARADOX_FALSE;
        if(!found) break;
    }
   
    // \\?
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) == '\\')
        paradox_css_tracer_pop(tracer);

    return PARADOX_CSS_LEXER_SUCCESS;
}

PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_badcomment_macro(paradox_css_tracer* tracer, paradox_str_t* comment)
{
    if(PARADOX_CSS_LEXER_SUCCESS == paradox_css_consume_badcomment1_macro(tracer, comment)
    || PARADOX_CSS_LEXER_SUCCESS == paradox_css_consume_badcomment2_macro(tracer, comment))
        return PARADOX_CSS_LEXER_SUCCESS;
    else
        return PARADOX_CSS_LEXER_INVALID_CONTENT;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_badcomment1_macro(paradox_css_tracer* tracer, paradox_str_t* comment)
{
    if(!comment) return PARADOX_CSS_LEXER_NO_STRING;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_comment;
    }

    size_t index = tracer->index;
    size_t num_bytes;

    // "/"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '/')
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto null_comment;
    }
    paradox_css_tracer_pop(tracer);

    // "*"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '*')
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto null_comment;
    }
    paradox_css_tracer_pop(tracer);
    
    paradox_uint32_t code;

    // [^*]*
    while((code = paradox_css_tracer_peek_code(tracer, &num_bytes)) != '*')
    {
        if(code == PARADOX_UTF8_ERR_CODE)
        {
            err = PARADOX_CSS_LEXER_UNKNOWN_UTF8_CODE;
            goto reset_tracer;
        }
        else paradox_css_tracer_pop_seq(tracer, num_bytes);
    }

    // \*+
    paradox_bool8_t found_asterisk = PARADOX_FALSE;
    while((code = paradox_css_tracer_peek_code(tracer, &num_bytes)) == '*')
    {
        paradox_css_tracer_pop(tracer);
        found_asterisk = PARADOX_TRUE;
    }
    if(!found_asterisk)
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto reset_tracer;
    }

    // ([^/*][^*]*\*+)*
    code = paradox_css_tracer_peek_code(tracer, &num_bytes);
    while(code != '/' && code != '*')
    {
        if(code == PARADOX_UTF8_ERR_CODE)
        {
            err = PARADOX_CSS_LEXER_UNKNOWN_UTF8_CODE;
            goto reset_tracer;
        }
        paradox_css_tracer_pop_seq(tracer, num_bytes);

        while((code = paradox_css_tracer_peek_code(tracer, &num_bytes)) != '*')
        {
            if(code == PARADOX_UTF8_ERR_CODE)
            {
                err = PARADOX_CSS_LEXER_UNKNOWN_UTF8_CODE;
                goto reset_tracer;
            }
            else paradox_css_tracer_pop_seq(tracer, num_bytes);
        }

        // remove asterisk
        paradox_css_tracer_pop(tracer);
        while((code = paradox_css_tracer_peek_code(tracer, &num_bytes)) == '*') paradox_css_tracer_pop(tracer);
        code = paradox_css_tracer_peek_code(tracer, &num_bytes);
    }

    // allocate comment string

    size_t len = tracer->index - index;
    *comment = malloc(sizeof(paradox_char8_t) * (len + 1));
    strncpy(*comment, tracer->content + index, len);
    (*comment)[len] = '\0';

    return PARADOX_CSS_LEXER_SUCCESS;
    
    reset_tracer:
    tracer->index = index;

    null_comment:
    *comment = NULL;

    return err;
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_badcomment2_macro(paradox_css_tracer* tracer, paradox_str_t* comment)
{
    if(!comment) return PARADOX_CSS_LEXER_NO_STRING;

    paradox_css_lexer_errno_t err;
    if(!tracer)
    {
        err = PARADOX_CSS_LEXER_NO_TRACER;
        goto null_comment;
    }

    size_t index = tracer->index;
    size_t num_bytes;

    // "/"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '/')
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto null_comment;
    }
    paradox_css_tracer_pop(tracer);

    // "*"
    if(paradox_css_tracer_peek_code(tracer, &num_bytes) != '*')
    {
        err = PARADOX_CSS_LEXER_INVALID_CONTENT;
        goto null_comment;
    }
    paradox_css_tracer_pop(tracer);

    paradox_uint32_t code;
    // [^*]*
    while((code = paradox_css_tracer_peek_code(tracer, &num_bytes)) != '*')
    {
        if(code == PARADOX_UTF8_ERR_CODE)
        {
            err = PARADOX_CSS_LEXER_UNKNOWN_UTF8_CODE;
            goto reset_tracer;
        }
        else paradox_css_tracer_pop_seq(tracer, num_bytes);
    }

    // (\*+[^/*][^*]*)*
    while((code = paradox_css_tracer_peek_code(tracer, &num_bytes)) == '*')
    {
        paradox_css_tracer_pop(tracer);
        while((code = paradox_css_tracer_peek_code(tracer, &num_bytes)) == '*') paradox_css_tracer_pop(tracer);
        
        if((code = paradox_css_tracer_peek_code(tracer, &num_bytes)) == '/')
        {
            err = PARADOX_CSS_LEXER_INVALID_CONTENT;
            goto reset_tracer;
        }
        paradox_css_tracer_pop_seq(tracer, num_bytes);

        while((code = paradox_css_tracer_peek_code(tracer, &num_bytes)) != '*') paradox_css_tracer_pop_seq(tracer, num_bytes);
    }

    // allocate comment string

    size_t len = tracer->index - index;
    *comment = malloc(sizeof(paradox_char8_t) * (len + 1));
    strncpy(*comment, tracer->content + index, len);
    (*comment)[len] = '\0';

    return PARADOX_CSS_LEXER_SUCCESS;
    
    reset_tracer:
    tracer->index = index;

    null_comment:
    *comment = NULL;

    return err;
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
    if(!tracer) return PARADOX_CSS_LEXER_NO_TRACER;

    size_t num_bytes;

    // \ n | \ r \ n | \ r | \ f
    switch(paradox_css_tracer_peek_code(tracer, &num_bytes))
    {
    case '\n':
    case '\f':
        paradox_css_tracer_pop(tracer);
        return PARADOX_CSS_LEXER_SUCCESS;

    case '\r': {
        paradox_css_tracer_pop(tracer);
        if(paradox_css_tracer_peek_code(tracer, &num_bytes) == '\n')
            paradox_css_tracer_pop(tracer);
        return PARADOX_CSS_LEXER_SUCCESS;
    }
    default:
        return PARADOX_CSS_LEXER_INVALID_CONTENT;
    }
}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_w_macro(paradox_css_tracer* tracer)
{
    if(!tracer) return PARADOX_CSS_LEXER_NO_TRACER;
 
    size_t num_bytes;

    // [ \ s \ t \ r \ n \ f ] *

    paradox_uint32_t c = paradox_css_tracer_peek_code(tracer, &num_bytes);
    paradox_bool8_t found = PARADOX_FALSE;
    paradox_bool8_t done_checking = PARADOX_FALSE;
    while(!done_checking) switch(c)
    {
    case  ' ':
    case '\t':
    case '\r':
    case '\n':
    case '\f':
        paradox_css_tracer_pop(tracer);
        break;

    default:
        done_checking = PARADOX_TRUE;
        break;
    }

    return PARADOX_CSS_LEXER_SUCCESS;
}