#include <paradox-css/token.h>
#include <stdlib.h>

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

    switch(token->type) {
    case PARADOX_CSS_UNICODERANGE_TOK:
        free(token->value.unicode_range->start);
        free(token->value.unicode_range->end);
        break;
    default: break; }

    free(token);
	return;
}