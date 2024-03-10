#ifndef PARADOX_WORKS_CPP_SVG_PARSER_HPP
#define PARADOX_WORKS_CPP_SVG_PARSER_HPP

#include <paradox-svg/tracer.hpp>

namespace Paradox { namespace SVG {
    PARADOX_SVG_API DataType::B8 ParseFileContents(const DataType::String_t& filename);
}}
#endif