#ifndef PARADOX_WORKS_C_CSS2_PARSER_H
#define PARADOX_WORKS_C_CSS2_PARSER_H

#include <paradox-css/css2_lexer.h>

PARADOX_CSS_API paradox_errno_t paradox_css2_parse_file(paradox_cstr_t path);

// Syntax: [ CDO | CDC | S | statement ]*;
PARADOX_CSS_API paradox_errno_t paradox_css2_parse_stylesheet(paradox_css2_tracer* tracer);

// Syntax: ruleset | at-rule;
PARADOX_CSS_API paradox_errno_t paradox_css2_parse_statement(paradox_css2_tracer* tracer);

// Syntax: ATKEYWORD S* any* [ block | ';' S* ];
PARADOX_CSS_API paradox_errno_t paradox_css2_parse_at_rule(paradox_css2_tracer* tracer);

// Syntax: '{' S* [ any | block | ATKEYWORD S* | ';' S* ]* '}' S*;
PARADOX_CSS_API paradox_errno_t paradox_css2_parse_block(paradox_css2_tracer* tracer);

// Syntax: selector? '{' S* declaration? [ ';' S* declaration? ]* '}' S*;
PARADOX_CSS_API paradox_errno_t paradox_css2_parse_ruleset(paradox_css2_tracer* tracer);

// Syntax: any+;
PARADOX_CSS_API paradox_errno_t paradox_css2_parse_selector(paradox_css2_tracer* tracer);

// Syntax: property S* ':' S* value;
PARADOX_CSS_API paradox_errno_t paradox_css2_parse_declaration(paradox_css2_tracer* tracer);

// Syntax: IDENT;
PARADOX_CSS_API paradox_errno_t paradox_css2_parse_property(paradox_css2_tracer* tracer);

// Syntax: [ any | block | ATKEYWORD S* ]+;
PARADOX_CSS_API paradox_errno_t paradox_css2_parse_value(paradox_css2_tracer* tracer);

/** Syntax:
 * [ IDENT | NUMBER | PERCENTAGE | DIMENSION | STRING
 * | DELIM | URI | HASH | UNICODE-RANGE | INCLUDES
 * | DASHMATCH | ':' | FUNCTION S* [any|unused]* ')'
 * | '(' S* [any|unused]* ')' | '[' S* [any|unused]* ']'
 * ] S*;
 */
PARADOX_CSS_API paradox_errno_t paradox_css2_parse_any(paradox_css2_tracer* tracer);

// Syntax: block | ATKEYWORD S* | ';' S* | CDO S* | CDC S*;
PARADOX_CSS_API paradox_errno_t paradox_css2_parse_unused(paradox_css2_tracer* tracer);

#endif