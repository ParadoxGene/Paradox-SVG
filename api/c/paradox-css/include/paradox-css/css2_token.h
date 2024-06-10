#ifndef PARADOX_WORKS_C_CSS2_TOKEN_H
#define PARADOX_WORKS_C_CSS2_TOKEN_H

#include <paradox-css/defines.h>

typedef enum paradox_css2_token_type
{
    PARADOX_CSS2_IDENT_TOK,
    PARADOX_CSS2_ATKEYWORD_TOK,
    PARADOX_CSS2_STRING_TOK,
    PARADOX_CSS2_BAD_STRING_TOK,
    PARADOX_CSS2_BAD_URI_TOK,
    PARADOX_CSS2_BAD_COMMENT_TOK,
    PARADOX_CSS2_HASH_TOK,
    PARADOX_CSS2_NUMBER_TOK,
    PARADOX_CSS2_PERCENTAGE_TOK,
    PARADOX_CSS2_DIMENSION_TOK,
    PARADOX_CSS2_URI_TOK,
    PARADOX_CSS2_UNICODERANGE_TOK,
    PARADOX_CSS2_CDO_TOK,
    PARADOX_CSS2_CDC_TOK,
    PARADOX_CSS2_COLON_TOK,
    PARADOX_CSS2_SEMICOLON_TOK,
    PARADOX_CSS2_OPEN_BRACE_TOK,
    PARADOX_CSS2_CLOSE_BRACE_TOK,
    PARADOX_CSS2_OPEN_PAREN_TOK,
    PARADOX_CSS2_CLOSE_PAREN_TOK,
    PARADOX_CSS2_OPEN_BRACKET_TOK,
    PARADOX_CSS2_CLOSE_BRACKET_TOK,
    PARADOX_CSS2_S_TOK,
    PARADOX_CSS2_COMMENT_TOK,
    PARADOX_CSS2_FUNCTION_TOK,
    PARADOX_CSS2_INCLUDES_TOK,
    PARADOX_CSS2_DASHMATCH_TOK,
    PARADOX_CSS2_DELIM_TOK
} paradox_css2_token_type;

typedef struct paradox_css2_unicode_range
{
    paradox_str_t start, end;
} paradox_css2_unicode_range;

typedef union paradox_css2_token_value
{
    paradox_css2_unicode_range* unicode_range;
} paradox_css2_token_value;

typedef struct paradox_css2_token {
    paradox_css2_token_type type;
    paradox_css2_token_value value;
    struct paradox_css2_token* next_token;
} paradox_css2_token;

PARADOX_CSS_API paradox_css2_token* paradox_css2_create_ident_token();
PARADOX_CSS_API paradox_css2_token* paradox_css2_create_atkeyword_token();
PARADOX_CSS_API paradox_css2_token* paradox_css2_create_string_token();
PARADOX_CSS_API paradox_css2_token* paradox_css2_create_bad_string_token();
PARADOX_CSS_API paradox_css2_token* paradox_css2_create_bad_uri_token();
PARADOX_CSS_API paradox_css2_token* paradox_css2_create_bad_comment_token();
PARADOX_CSS_API paradox_css2_token* paradox_css2_create_hash_token();
PARADOX_CSS_API paradox_css2_token* paradox_css2_create_number_token();
PARADOX_CSS_API paradox_css2_token* paradox_css2_create_percentage_token();
PARADOX_CSS_API paradox_css2_token* paradox_css2_create_dimension_token();
PARADOX_CSS_API paradox_css2_token* paradox_css2_create_uri_token();
PARADOX_CSS_API paradox_css2_token* paradox_css2_create_unicode_range_token(paradox_cstr_t start, size_t start_len, paradox_cstr_t end, size_t end_len);
PARADOX_CSS_API paradox_css2_token* paradox_css2_create_cdo_token();
PARADOX_CSS_API paradox_css2_token* paradox_css2_create_cdc_token();
PARADOX_CSS_API paradox_css2_token* paradox_css2_create_colon_token();
PARADOX_CSS_API paradox_css2_token* paradox_css2_create_semicolon_token();
PARADOX_CSS_API paradox_css2_token* paradox_css2_create_open_brace_token();
PARADOX_CSS_API paradox_css2_token* paradox_css2_create_close_brace_token();
PARADOX_CSS_API paradox_css2_token* paradox_css2_create_open_paren_token();
PARADOX_CSS_API paradox_css2_token* paradox_css2_create_close_paren_token();
PARADOX_CSS_API paradox_css2_token* paradox_css2_create_open_bracket_token();
PARADOX_CSS_API paradox_css2_token* paradox_css2_create_close_bracket_token();
PARADOX_CSS_API paradox_css2_token* paradox_css2_create_space_token();
PARADOX_CSS_API paradox_css2_token* paradox_css2_create_comment_token();
PARADOX_CSS_API paradox_css2_token* paradox_css2_create_function_token();
PARADOX_CSS_API paradox_css2_token* paradox_css2_create_includes_token();
PARADOX_CSS_API paradox_css2_token* paradox_css2_create_dashmatch_token();
PARADOX_CSS_API paradox_css2_token* paradox_css2_create_delim_token();
PARADOX_CSS_API void paradox_css2_destroy_token(paradox_css2_token* token);

#endif