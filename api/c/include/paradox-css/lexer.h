#ifndef PARADOX_WORKS_C_CSS_LEXER_H
#define PARADOX_WORKS_C_CSS_LEXER_H

#include <paradox-css/tracer.h>

PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_file(paradox_cstr_t path);

// Definition: {ident}
PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_ident(paradox_css_tracer* tracer);

// Definition: @{ident}
PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_atkeyword(paradox_css_tracer* tracer);

// Definition: {string}
PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_string(paradox_css_tracer* tracer);

// Definition: {badstring}
PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_bad_string(paradox_css_tracer* tracer);

// Definition: {baduri}
PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_bad_uri(paradox_css_tracer* tracer);

// Definition: {badcomment}
PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_bad_comment(paradox_css_tracer* tracer);

// Definition: #{name}
PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_hash(paradox_css_tracer* tracer);

// Definition: {num}
PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_number(paradox_css_tracer* tracer);

// Definition: {num}%
PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_percentage(paradox_css_tracer* tracer);

// Definition: {num}{ident}
PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_dimension(paradox_css_tracer* tracer);

/**
 * Definition1: {U}{R}{L}\\({w}{string}{w}\\)
 * Definition2: {U}{R}{L}\\({w}([!#$%&*-\\[\\]-~]|{nonascii}|{escape})*{w}\\)
 */
PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_uri(paradox_css_tracer* tracer);

/**
 * Definition1: u\\+[?]{1,6}
 * Definition2: u\\+[0-9a-f]{1}[?]{0,5}
 * Definition3: u\\+[0-9a-f]{2}[?]{0,4}
 * Definition4: u\\+[0-9a-f]{3}[?]{0,3}
 * Definition5: u\\+[0-9a-f]{4}[?]{0,2}
 * Definition6: u\\+[0-9a-f]{5}[?]{0,1}
 * Definition7: u\\+[0-9a-f]{6}
 * Definition8: u\\+[0-9a-f]{1,6}-[0-9a-f]{1,6}
 */
PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_unicode_range(paradox_css_tracer* tracer);

// Definition: <!--
PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_cdo(paradox_css_tracer* tracer);

// Definition: -->
PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_cdc(paradox_css_tracer* tracer);

// Definition: :
PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_colon(paradox_css_tracer* tracer);

// Definition: ;
PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_semicolon(paradox_css_tracer* tracer);

// Definition: \\{
PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_open_brace(paradox_css_tracer* tracer);

// Definition: \\}
PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_close_brace(paradox_css_tracer* tracer);

// Definition: \\(
PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_open_parenthesis(paradox_css_tracer* tracer);

// Definition: \\)
PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_close_parenthesis(paradox_css_tracer* tracer);

// Definition: \\[
PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_open_bracket(paradox_css_tracer* tracer);

// Definition: \\]
PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_close_bracket(paradox_css_tracer* tracer);

// Definition: [ \\t\\r\\n\\f]+
PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_s(paradox_css_tracer* tracer);

// Definition: \\/\\*[^*]*\\*+([^/*][^*]*\\*+)*\\/
PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_comment(paradox_css_tracer* tracer);

// Definition: {ident}\\(
PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_function(paradox_css_tracer* tracer);

// Definition: ~=
PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_includes(paradox_css_tracer* tracer);

// Definition: |=
PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_dash_match(paradox_css_tracer* tracer);

// Definition: Any other character not matched by the above rules, and neither a single nor a double quote
PARADOX_SVG_API const paradox_errno_t paradox_css_tokenize_delim(paradox_css_tracer* tracer);

// Macro: [-]?{nmstart}{nmchar}*
PARADOX_SVG_API const paradox_errno_t paradox_css_consume_ident_macro(paradox_css_tracer* tracer);

// Macro: {nmchar}+
PARADOX_SVG_API const paradox_errno_t paradox_css_consume_name_macro(paradox_css_tracer* tracer);

// Macro: [_a-z]|{nonascii}|{escape}
PARADOX_SVG_API const paradox_errno_t paradox_css_consume_nmstart_macro(paradox_css_tracer* tracer);

// Macro: [^\0-\177]
PARADOX_SVG_API const paradox_errno_t paradox_css_consume_nonascii_macro(paradox_css_tracer* tracer);

// Macro: \\\\[0-9a-f]{1,6}(\\r\\n|[ \\n\\r\\t\\f])?
PARADOX_SVG_API const paradox_errno_t paradox_css_consume_unicode_macro(paradox_css_tracer* tracer);

// Macro: {unicode}|\\\\[^\\n\\r\\f0-9a-f]
PARADOX_SVG_API const paradox_errno_t paradox_css_consume_escape_macro(paradox_css_tracer* tracer);

// Macro: [_a-z0-9-]|{nonascii}|{escape}
PARADOX_SVG_API const paradox_errno_t paradox_css_consume_nmchar_macro(paradox_css_tracer* tracer);

// Macro: [+-]?([0-9]+|[0-9]*\\.[0-9]+)(e[+-]?[0-9]+)?
PARADOX_SVG_API const paradox_errno_t paradox_css_consume_num_macro(paradox_css_tracer* tracer);

// Macro: {string1}|{string2}
PARADOX_SVG_API const paradox_errno_t paradox_css_consume_string_macro(paradox_css_tracer* tracer);

// Macro: \"([^\n\r\f\\"]|\\{nl}|{escape})*\"
PARADOX_SVG_API const paradox_errno_t paradox_css_consume_string1_macro(paradox_css_tracer* tracer);

// Macro: \'([^\n\r\f\\']|\\{nl}|{escape})*\'
PARADOX_SVG_API const paradox_errno_t paradox_css_consume_string2_macro(paradox_css_tracer* tracer);

// Macro: {badstring1}|{badstring2}
PARADOX_SVG_API const paradox_errno_t paradox_css_consume_badstring_macro(paradox_css_tracer* tracer);

// Macro: \"([^\n\r\f\\"]|\\{nl}|{escape})*\\?
PARADOX_SVG_API const paradox_errno_t paradox_css_consume_badstring1_macro(paradox_css_tracer* tracer);

// Macro: \'([^\n\r\f\\']|\\{nl}|{escape})*\\?
PARADOX_SVG_API const paradox_errno_t paradox_css_consume_badstring2_macro(paradox_css_tracer* tracer);

// Macro: {badcomment1}|{badcomment2}
PARADOX_SVG_API const paradox_errno_t paradox_css_consume_badcomment_macro(paradox_css_tracer* tracer);

// Macro: \\/\\*[^*]*\\*+([^/*][^*]*\\*+)*
PARADOX_SVG_API const paradox_errno_t paradox_css_consume_badcomment1_macro(paradox_css_tracer* tracer);

// Macro: \\/\\*[^*]*(\\*+[^/*][^*]*)*
PARADOX_SVG_API const paradox_errno_t paradox_css_consume_badcomment2_macro(paradox_css_tracer* tracer);

// Macro: {baduri1}|{baduri2}|{baduri3}
PARADOX_SVG_API const paradox_errno_t paradox_css_consume_baduri_macro(paradox_css_tracer* tracer);

// Macro: {U}{R}{L}\\({w}([!#$%&*-~]|{nonascii}|{escape})*{w}
PARADOX_SVG_API const paradox_errno_t paradox_css_consume_baduri1_macro(paradox_css_tracer* tracer);

// Macro: {U}{R}{L}\\({w}{string}{w}
PARADOX_SVG_API const paradox_errno_t paradox_css_consume_baduri2_macro(paradox_css_tracer* tracer);

// Macro: {U}{R}{L}\\({w}{badstring}
PARADOX_SVG_API const paradox_errno_t paradox_css_consume_baduri3_macro(paradox_css_tracer* tracer);

// Macro: \\n|\\r\\n|\\r|\\f
PARADOX_SVG_API const paradox_errno_t paradox_css_consume_n1_macro(paradox_css_tracer* tracer);

// Macro: [ \\t\\r\\n\\f]*
PARADOX_SVG_API const paradox_errno_t paradox_css_consume_w_macro(paradox_css_tracer* tracer);

// Macro: l|\\\\0{0,4}(4c|6c)(\\r\\n|[ \\t\\r\\n\\f])?|\\\\l
PARADOX_SVG_API const paradox_errno_t paradox_css_consume_l_macro(paradox_css_tracer* tracer);

// Macro: r|\\\\0{0,4}(52|72)(\\r\\n|[ \\t\\r\\n\\f])?|\\\\r
PARADOX_SVG_API const paradox_errno_t paradox_css_consume_r_macro(paradox_css_tracer* tracer);

// Macro: u|\\\\0{0,4}(55|75)(\\r\\n|[ \\t\\r\\n\\f])?|\\\\u
PARADOX_SVG_API const paradox_errno_t paradox_css_consume_u_macro(paradox_css_tracer* tracer);

#endif