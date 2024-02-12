#ifndef PARADOX_WORKS_CPP_CSS_PARSER_HPP
#define PARADOX_WORKS_CPP_CSS_PARSER_HPP

#include <paradox-css/tracer.hpp>

namespace Paradox { namespace CSS {
    PARADOX_SVG_API const DataType::B8 ParseFileContents(const DataType::String_t& filename);
}}
#endif