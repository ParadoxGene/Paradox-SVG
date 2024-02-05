#ifndef PARADOX_WORKS_C_SVG_PARSER_H
#define PARADOX_WORKS_C_SVG_PARSER_H

#include <paradox-platform/defines.h>
#include <errno.h>

const errno_t paradox_svg_parse_from_file(paradox_cstr_t path);

#endif