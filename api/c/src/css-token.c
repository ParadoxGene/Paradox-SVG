#include <paradox-css/token.h>
#include <stdlib.h>
#include <string.h>

PARADOX_SVG_API paradox_css_token* paradox_css_create_ident_token()
{
	return NULL;
}
PARADOX_SVG_API paradox_css_token* paradox_css_create_atkeyword_token()
{
	return NULL;
}
PARADOX_SVG_API paradox_css_token* paradox_css_create_string_token()
{
	return NULL;
}
PARADOX_SVG_API paradox_css_token* paradox_css_create_bad_string_token()
{
	return NULL;
}
PARADOX_SVG_API paradox_css_token* paradox_css_create_bad_uri_token()
{
	return NULL;
}
PARADOX_SVG_API paradox_css_token* paradox_css_create_bad_comment_token()
{
	return NULL;
}
PARADOX_SVG_API paradox_css_token* paradox_css_create_hash_token()
{
	return NULL;
}
PARADOX_SVG_API paradox_css_token* paradox_css_create_number_token()
{
	return NULL;
}
PARADOX_SVG_API paradox_css_token* paradox_css_create_percentage_token()
{
	return NULL;
}
PARADOX_SVG_API paradox_css_token* paradox_css_create_dimension_token()
{
	return NULL;
}
PARADOX_SVG_API paradox_css_token* paradox_css_create_uri_token()
{
	return NULL;
}
PARADOX_SVG_API paradox_css_token* paradox_css_create_unicode_range_token(paradox_cstr_t start, size_t start_len, paradox_cstr_t end, size_t end_len)
{
    paradox_css_token* token = malloc(sizeof(paradox_css_token));
    if(!token || !start) return NULL;
    token->type = PARADOX_CSS_UNICODERANGE_TOK;
    token->next_token = NULL;

    token->value.unicode_range = malloc(sizeof(paradox_css_unicode_range));
    if(!token->value.unicode_range) goto free_token;

    token->value.unicode_range->start = malloc(sizeof(paradox_char8_t)*(start_len + 1));
    if(!token->value.unicode_range->start) goto free_unicode_range;

    strncpy(token->value.unicode_range->start, start, start_len);
    token->value.unicode_range->start[start_len] = '\0';

    if(!end)
    {
        token->value.unicode_range->end = NULL;
        return token;
    }

    token->value.unicode_range->end = malloc(sizeof(paradox_char8_t)*(end_len + 1));
    if(!token->value.unicode_range->end) goto free_range_start;

    strncpy(token->value.unicode_range->end, end, end_len);
    token->value.unicode_range->end[end_len] = '\0';
    
    return token;

    free_range_start:
    free(token->value.unicode_range->start);

    free_unicode_range:
    free(token->value.unicode_range);

    free_token:
    free(token);
    
	return NULL;
}
PARADOX_SVG_API paradox_css_token* paradox_css_create_cdo_token()
{
	paradox_css_token* token = malloc(sizeof(paradox_css_token));
    token->type = PARADOX_CSS_CDO_TOK;
    token->next_token = NULL;
	return token;
}
PARADOX_SVG_API paradox_css_token* paradox_css_create_cdc_token()
{
	paradox_css_token* token = malloc(sizeof(paradox_css_token));
    token->type = PARADOX_CSS_CDC_TOK;
    token->next_token = NULL;
	return token;
}
PARADOX_SVG_API paradox_css_token* paradox_css_create_colon_token()
{
	paradox_css_token* token = malloc(sizeof(paradox_css_token));
    token->type = PARADOX_CSS_COLON_TOK;
    token->next_token = NULL;
	return token;
}
PARADOX_SVG_API paradox_css_token* paradox_css_create_semicolon_token()
{
	paradox_css_token* token = malloc(sizeof(paradox_css_token));
    token->type = PARADOX_CSS_SEMICOLON_TOK;
    token->next_token = NULL;
	return token;
}
PARADOX_SVG_API paradox_css_token* paradox_css_create_open_brace_token()
{
	paradox_css_token* token = malloc(sizeof(paradox_css_token));
    token->type = PARADOX_CSS_OPEN_BRACE_TOK;
    token->next_token = NULL;
	return token;
}
PARADOX_SVG_API paradox_css_token* paradox_css_create_close_brace_token()
{
	paradox_css_token* token = malloc(sizeof(paradox_css_token));
    token->type = PARADOX_CSS_CLOSE_BRACE_TOK;
    token->next_token = NULL;
	return token;
}
PARADOX_SVG_API paradox_css_token* paradox_css_create_open_paren_token()
{
	paradox_css_token* token = malloc(sizeof(paradox_css_token));
    token->type = PARADOX_CSS_OPEN_PAREN_TOK;
    token->next_token = NULL;
	return token;
}
PARADOX_SVG_API paradox_css_token* paradox_css_create_close_paren_token()
{
	paradox_css_token* token = malloc(sizeof(paradox_css_token));
    token->type = PARADOX_CSS_CLOSE_PAREN_TOK;
    token->next_token = NULL;
	return token;
}
PARADOX_SVG_API paradox_css_token* paradox_css_create_open_bracket_token()
{
	paradox_css_token* token = malloc(sizeof(paradox_css_token));
    token->type = PARADOX_CSS_OPEN_BRACKET_TOK;
    token->next_token = NULL;
	return token;
}
PARADOX_SVG_API paradox_css_token* paradox_css_create_close_bracket_token()
{
	paradox_css_token* token = malloc(sizeof(paradox_css_token));
    token->type = PARADOX_CSS_CLOSE_BRACKET_TOK;
    token->next_token = NULL;
	return token;
}
PARADOX_SVG_API paradox_css_token* paradox_css_create_space_token()
{
	paradox_css_token* token = malloc(sizeof(paradox_css_token));
    token->type = PARADOX_CSS_S_TOK;
    token->next_token = NULL;
	return token;
}
PARADOX_SVG_API paradox_css_token* paradox_css_create_comment_token()
{
	return NULL;
}
PARADOX_SVG_API paradox_css_token* paradox_css_create_function_token()
{
	return NULL;
}
PARADOX_SVG_API paradox_css_token* paradox_css_create_includes_token()
{
	paradox_css_token* token = malloc(sizeof(paradox_css_token));
    token->type = PARADOX_CSS_INCLUDES_TOK;
    token->next_token = NULL;
	return token;
}
PARADOX_SVG_API paradox_css_token* paradox_css_create_dashmatch_token()
{
    paradox_css_token* token = malloc(sizeof(paradox_css_token));
    token->type = PARADOX_CSS_DASHMATCH_TOK;
    token->next_token = NULL;
	return token;
}
PARADOX_SVG_API paradox_css_token* paradox_css_create_delim_token()
{
	return NULL;
}
PARADOX_SVG_API void paradox_css_destroy_token(paradox_css_token* token)
{
    if(!token) return;
    paradox_css_destroy_token(token->next_token);

    switch(token->type)
    {
    case PARADOX_CSS_UNICODERANGE_TOK: {
        if(token->value.unicode_range)
        {
            if(token->value.unicode_range->start) free(token->value.unicode_range->start);
            if(token->value.unicode_range->end) free(token->value.unicode_range->end);
            free(token->value.unicode_range);
        }
        break;
    }
    default: {
        break; 
    }}

    free(token);
}