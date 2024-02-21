#ifndef PARADOX_WORKS_C_CSS_LEXER_H
#define PARADOX_WORKS_C_CSS_LEXER_H

#include <paradox-css/tracer.h>
#include <paradox-css/token.h>

typedef enum paradox_css_lexer_errno_t
{
    /** Lexer successfully tokenized a step. */
    PARADOX_CSS_LEXER_SUCCESS,

    /** Lexer function was not passed a tracer reference. */
    PARADOX_CSS_LEXER_NO_TRACER,

    /** Lexer function was not passed a token reference. */
    PARADOX_CSS_LEXER_NO_TOKEN,

    /** String content of the tracer is invalid for the lexer function. */
    PARADOX_CSS_LEXER_INVALID_CONTENT,

    /** Lexer function failed to allocate the token. */
    PARADOX_CSS_LEXER_TOKEN_ALLOC_FAILURE,

    /** Lexer function was not passed a string (paradox_str_t) reference. */
    PARADOX_CSS_LEXER_NO_STRING,

    /** Lexer function was not passed a utf8 code (paradox_uint32_t) reference. */
    PARADOX_CSS_LEXER_NO_UTF8_CODE,

    /** String content of the tracer contained an invalid utf8 character sequence. */
    PARADOX_CSS_LEXER_UNKNOWN_UTF8_CODE,
} paradox_css_lexer_errno_t;

PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_file(paradox_cstr_t path);

// Definition: {ident}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_ident(paradox_css_tracer* tracer, paradox_css_token** token);

// Definition: \@{ident}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_atkeyword(paradox_css_tracer* tracer, paradox_css_token** token);

// Definition: {string}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_string(paradox_css_tracer* tracer, paradox_css_token** token);

// Definition: {badstring}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_bad_string(paradox_css_tracer* tracer, paradox_css_token** token);

// Definition: {baduri}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_bad_uri(paradox_css_tracer* tracer, paradox_css_token** token);

// Definition: {badcomment}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_bad_comment(paradox_css_tracer* tracer, paradox_css_token** token);

// Definition: #{name}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_hash(paradox_css_tracer* tracer, paradox_css_token** token);

// Definition: {num}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_number(paradox_css_tracer* tracer, paradox_css_token** token);

// Definition: {num}%
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_percentage(paradox_css_tracer* tracer, paradox_css_token** token);

// Definition: {num}{ident}
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_dimension(paradox_css_tracer* tracer, paradox_css_token** token);

/**
 * Definition1: {U}{R}{L}\\({w}{string}{w}\\)
 * Definition2: {U}{R}{L}\\({w}([!#$%&*-\\[\\]-~]|{nonascii}|{escape})*{w}\\)
 */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_uri(paradox_css_tracer* tracer, paradox_css_token** token);

// u\\+[0-9a-f?]{1,6}(-[0-9a-f]{1,6})?
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_unicode_range(paradox_css_tracer* tracer, paradox_css_token** token);

/* Definition: <!-- */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_cdo(paradox_css_tracer* tracer, paradox_css_token** token);

/* Definition: --> */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_cdc(paradox_css_tracer* tracer, paradox_css_token** token);

/* Definition: : */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_colon(paradox_css_tracer* tracer, paradox_css_token** token);

/* Definition: ; */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_semicolon(paradox_css_tracer* tracer, paradox_css_token** token);

/* Definition: \\{ */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_open_brace(paradox_css_tracer* tracer, paradox_css_token** token);

/* Definition: \\} */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_close_brace(paradox_css_tracer* tracer, paradox_css_token** token);

/* Definition: \\( */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_open_parenthesis(paradox_css_tracer* tracer, paradox_css_token** token);

/* Definition: \\) */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_close_parenthesis(paradox_css_tracer* tracer, paradox_css_token** token);

/* Definition: \\[ */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_open_bracket(paradox_css_tracer* tracer, paradox_css_token** token);

/* Definition: \\] */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_close_bracket(paradox_css_tracer* tracer, paradox_css_token** token);

/* Definition: [ \\t\\r\\n\\f]+ */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_s(paradox_css_tracer* tracer, paradox_css_token** token);

// Definition: \\/\\*[^*]*\\*+([^/*][^*]*\\*+)*\\/
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_comment(paradox_css_tracer* tracer, paradox_css_token** token);

// Definition: {ident}\\(
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_function(paradox_css_tracer* tracer, paradox_css_token** token);

/* Definition: ~= */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_includes(paradox_css_tracer* tracer, paradox_css_token** token);

/* Definition: |= */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_dash_match(paradox_css_tracer* tracer, paradox_css_token** token);

// Definition: Any other character not matched by the above rules, and neither a single nor a double quote
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_tokenize_delim(paradox_css_tracer* tracer, paradox_css_token** token);

/** Macro: [ - ] ? { n m s t a r t } { n m c h a r } * */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_ident_macro(paradox_css_tracer* tracer, paradox_str_t* string_val);

/** Macro: { n m c h a r } + */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_name_macro(paradox_css_tracer* tracer, paradox_str_t* string_val);

/** Macro: [ _ a - z ] | { n o n a s c i i } | { e s c a p e } */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_nmstart_macro(paradox_css_tracer* tracer, paradox_uint32_t* code);

/** Macro: [ ^ \ 0 - \ 2 3 7 ] */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_nonascii_macro(paradox_css_tracer* tracer, paradox_uint32_t* code);

/** Macro: \ \ [ 0 - 9 a - f ] { 1 , 6 } ( \ r \ n | [ \ s \ n \ r \ t \ f ] ) ? */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_unicode_macro(paradox_css_tracer* tracer, paradox_uint32_t* code);

/** Macro: { u n i c o d e } | \ \ [ ^ \ n \ r \ f 0 - 9 a - f ] */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_escape_macro(paradox_css_tracer* tracer, paradox_uint32_t* code);

/** Macro: [ _ a - z 0 - 9 - ] | { n o n a s c i i } | { e s c a p e } */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_nmchar_macro(paradox_css_tracer* tracer, paradox_uint32_t* code);

/** Macro: [ + - ] ? ( [ 0 - 9 ] + | [ 0 - 9 ] * \ . [ 0 - 9 ] + ) ( e [ + - ] ? [ 0 - 9] + ) ? */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_num_macro(paradox_css_tracer* tracer);

/** Macro: { s t r i n g 1 } | { s t r i n g 2 } */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_string_macro(paradox_css_tracer* tracer, paradox_str_t* string_val);

/** Macro: \ " ( [ ^ \ n \ r \ f \ \ " ] | \ \ { n l } | { e s c a p e } ) * \ " */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_string1_macro(paradox_css_tracer* tracer, paradox_str_t* string_val);

/** Macro: \ ' ( [ ^ \ n \ r \ f \ \ ' ] | \ \ { n l } | { e s c a p e } ) * \ ' */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_string2_macro(paradox_css_tracer* tracer, paradox_str_t* string_val);

/** Macro: { b a d s t r i n g 1 } | { b a d s t r i n g 2 } */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_badstring_macro(paradox_css_tracer* tracer, paradox_str_t* string_val);

/** Macro: \ " ( [ ^ \ n \ r \ f \ \ " ] | \ \ { n l } | { e s c a p e } ) * \ \ ? */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_badstring1_macro(paradox_css_tracer* tracer, paradox_str_t* string_val);

/** Macro: \ ' ( [ ^ \ n \ r \ f \ \ ' ] | \ \ { n l } | { e s c a p e } ) * \ \ ? */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_badstring2_macro(paradox_css_tracer* tracer, paradox_str_t* string_val);

/** Macro: { b a d c o m m e n t 1 } | { b a d c o m m e n t 2 } */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_badcomment_macro(paradox_css_tracer* tracer, paradox_str_t* comment);

/** Macro: \ / \ * [ ^ * ] * \ * + ( [ ^ / * ] [ ^ * ] * \ * + ) * */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_badcomment1_macro(paradox_css_tracer* tracer, paradox_str_t* comment);

/** Macro: \ / \ * [^ *] * ( \ *+[^/ * ][^ * ] * ) * */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_badcomment2_macro(paradox_css_tracer* tracer, paradox_str_t* comment);

/** Macro: { b a d u r i 1 } | { b a d u r i 2 } | { b a d u r i 3 } */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_baduri_macro(paradox_css_tracer* tracer);

/** Macro: url \ ( { w } ( [ ! # $ % & * - ~ ] | { n o n a s c i i } | { e s c a p e } ) * { w } */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_baduri1_macro(paradox_css_tracer* tracer);

/** Macro: u r l \ ( { w } { s t r i n g } { w } */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_baduri2_macro(paradox_css_tracer* tracer);

/** Macro: u r l \ ( { w } { b a d s t r i n g } */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_baduri3_macro(paradox_css_tracer* tracer);

/** Macro: \ n | \ r \ n | \ r | \ f */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_nl_macro(paradox_css_tracer* tracer);

/** Macro: [ \ s \ t \ r \ n \ f ] * */
PARADOX_SVG_API const paradox_css_lexer_errno_t paradox_css_consume_w_macro(paradox_css_tracer* tracer);
#endif