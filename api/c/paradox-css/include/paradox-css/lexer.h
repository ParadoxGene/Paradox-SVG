#ifndef PARADOX_WORKS_C_CSS_LEXER_H
#define PARADOX_WORKS_C_CSS_LEXER_H

#include <paradox-css/tracer.h>
#include <paradox-css/token.h>

typedef enum paradox_css_lexer_errno_t
{
    /** Lexer successfully tokenized a step. */
    PARADOX_CSS_LEXER_OK,

    /** Lexer function was not passed a reference. */
    PARADOX_CSS_LEXER_BAD_PTR,

    /** Lexer function failed to allocate. */
    PARADOX_CSS_LEXER_BAD_ALLOC,

    /** String content of the tracer is invalid for the lexer function. */
    PARADOX_CSS_LEXER_BAD_CONTENT,

    /** String content of the tracer contained an invalid utf8 character sequence. */
    PARADOX_CSS_LEXER_BAD_UTF8_CODE,
} paradox_css_lexer_errno_t;

PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_file(paradox_cstr_t path);

/** Token: {ident} */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_ident(paradox_css_tracer* tracer, paradox_css_token** token);

/** Token: @ {ident} */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_atkeyword(paradox_css_tracer* tracer, paradox_css_token** token);

/** Token: {string} */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_string(paradox_css_tracer* tracer, paradox_css_token** token);

/** Token: {badstring} */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_bad_string(paradox_css_tracer* tracer, paradox_css_token** token);

/** Token: {baduri} */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_bad_uri(paradox_css_tracer* tracer, paradox_css_token** token);

/** Token: {badcomment} */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_bad_comment(paradox_css_tracer* tracer, paradox_css_token** token);

/** Token: # {name} */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_hash(paradox_css_tracer* tracer, paradox_css_token** token);

/** Token: {num} */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_number(paradox_css_tracer* tracer, paradox_css_token** token);

/** Token: {num} % */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_percentage(paradox_css_tracer* tracer, paradox_css_token** token);

/** Token: {num} {ident} */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_dimension(paradox_css_tracer* tracer, paradox_css_token** token);

/**
 * Token 1: u r l \ ( {w} {string} {w} \ )
 * Token 2: u r l \ ( {w} ( [ ! # $ % & * - \ [ \ ] - ~ ] | {nonascii} | {escape} ) * {w} \ )
 */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_uri(paradox_css_tracer* tracer, paradox_css_token** token);

/** Token: u \ + [ 0 - 9 a - f ? ] { 1 , 6 } ( - [ 0 - 9 a - f ] { 1 , 6 } ) ? */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_unicode_range(paradox_css_tracer* tracer, paradox_css_token** token);

/** Token: < ! - - */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_cdo(paradox_css_tracer* tracer, paradox_css_token** token);

/** Token: - - > */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_cdc(paradox_css_tracer* tracer, paradox_css_token** token);

/** Token: : */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_colon(paradox_css_tracer* tracer, paradox_css_token** token);

/** Token: ; */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_semicolon(paradox_css_tracer* tracer, paradox_css_token** token);

/** Token: \ { */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_open_brace(paradox_css_tracer* tracer, paradox_css_token** token);

/** Token: \ } */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_close_brace(paradox_css_tracer* tracer, paradox_css_token** token);

/** Token: \ ( */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_open_parenthesis(paradox_css_tracer* tracer, paradox_css_token** token);

/** Token: \ ) */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_close_parenthesis(paradox_css_tracer* tracer, paradox_css_token** token);

/** Token: \ [ */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_open_bracket(paradox_css_tracer* tracer, paradox_css_token** token);

/** Token: \ ] */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_close_bracket(paradox_css_tracer* tracer, paradox_css_token** token);

/** Token: [ \ s \ t \ r \ n \ f ] + */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_s(paradox_css_tracer* tracer, paradox_css_token** token);

/** Token: \ / \ * [ ^ * ] * \ * + ( [ ^ / * ] [ ^ * ] * \ * + ) * \ / */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_comment(paradox_css_tracer* tracer, paradox_css_token** token);

/** Token: {ident} \ ( */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_function(paradox_css_tracer* tracer, paradox_css_token** token);

/** Token: ~ = */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_includes(paradox_css_tracer* tracer, paradox_css_token** token);

/** Token: | = */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_dash_match(paradox_css_tracer* tracer, paradox_css_token** token);

/** Token: Any other character not matched by the above rules, and neither a single nor a double quote */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_tokenize_delim(paradox_css_tracer* tracer, paradox_css_token** token);

/** Macro: [ - ] ? {nmstart} {nmchar} * */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_consume_ident_macro(paradox_css_tracer* tracer, paradox_str_t* string_val);

/** Macro: {nmchar} + */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_consume_name_macro(paradox_css_tracer* tracer, paradox_str_t* string_val);

/** Macro: [ _ a - z ] | {nonascii} | {escape} */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_consume_nmstart_macro(paradox_css_tracer* tracer, paradox_uint32_t* code);

/** Macro: [ ^ \ 0 - \ 2 3 7 ] */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_consume_nonascii_macro(paradox_css_tracer* tracer, paradox_uint32_t* code);

/** Macro: \ \ [ 0 - 9 a - f ] { 1 , 6 } ( \ r \ n | [ \ s \ n \ r \ t \ f ] ) ? */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_consume_unicode_macro(paradox_css_tracer* tracer, paradox_uint32_t* code);

/** Macro: {unicode} | \ \ [ ^ \ n \ r \ f 0 - 9 a - f ] */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_consume_escape_macro(paradox_css_tracer* tracer, paradox_uint32_t* code);

/** Macro: [ _ a - z 0 - 9 - ] | {nonascii} | {escape} */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_consume_nmchar_macro(paradox_css_tracer* tracer, paradox_uint32_t* code);

/** Macro: [ + - ] ? ( [ 0 - 9 ] + | [ 0 - 9 ] * \ . [ 0 - 9 ] + ) ( e [ + - ] ? [ 0 - 9] + ) ? */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_consume_num_macro(paradox_css_tracer* tracer, paradox_float32_t* num);

/** Macro: {string1} | {string2} */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_consume_string_macro(paradox_css_tracer* tracer, paradox_str_t* string_val);

/** Macro: \ " ( [ ^ \ n \ r \ f \ \ " ] | \ \ {nl} | {escape} ) * \ " */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_consume_string1_macro(paradox_css_tracer* tracer, paradox_str_t* string_val);

/** Macro: \ ' ( [ ^ \ n \ r \ f \ \ ' ] | \ \ {nl} | {escape} ) * \ ' */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_consume_string2_macro(paradox_css_tracer* tracer, paradox_str_t* string_val);

/** Macro: {badstring1} | {badstring2} */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_consume_badstring_macro(paradox_css_tracer* tracer, paradox_str_t* string_val);

/** Macro: \ " ( [ ^ \ n \ r \ f \ \ " ] | \ \ {nl} | {escape} ) * \ \ ? */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_consume_badstring1_macro(paradox_css_tracer* tracer, paradox_str_t* string_val);

/** Macro: \ ' ( [ ^ \ n \ r \ f \ \ ' ] | \ \ {nl} | {escape} ) * \ \ ? */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_consume_badstring2_macro(paradox_css_tracer* tracer, paradox_str_t* string_val);

/** Macro: {badcomment1} | {badcomment2} */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_consume_badcomment_macro(paradox_css_tracer* tracer, paradox_str_t* comment);

/** Macro: \ / \ * [ ^ * ] * \ * + ( [ ^ / * ] [ ^ * ] * \ * + ) * */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_consume_badcomment1_macro(paradox_css_tracer* tracer, paradox_str_t* comment);

/** Macro: \ / \ * [ ^ * ] * ( \ * + [ ^ / * ] [ ^ * ] * ) * */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_consume_badcomment2_macro(paradox_css_tracer* tracer, paradox_str_t* comment);

/** Macro: {baduri1} | {baduri2} | {baduri3} */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_consume_baduri_macro(paradox_css_tracer* tracer, paradox_str_t* url);

/** Macro: u r l \ ( {w} ( [ ! # $ % & * - ~ ] | {nonascii} | {escape} ) * {w} */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_consume_baduri1_macro(paradox_css_tracer* tracer, paradox_str_t* url);

/** Macro: u r l \ ( {w} {string} {w} */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_consume_baduri2_macro(paradox_css_tracer* tracer, paradox_str_t* url);

/** Macro: u r l \ ( {w} {badstring} */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_consume_baduri3_macro(paradox_css_tracer* tracer, paradox_str_t* url);

/** Macro: \ n | \ r \ n | \ r | \ f */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_consume_nl_macro(paradox_css_tracer* tracer);

/** Macro: [ \ s \ t \ r \ n \ f ] * */
PARADOX_CSS_API const paradox_css_lexer_errno_t paradox_css_consume_w_macro(paradox_css_tracer* tracer);
#endif