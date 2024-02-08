#ifndef PARADOX_WORKS_CPP_SVG_PARSER_HPP
#define PARADOX_WORKS_CPP_SVG_PARSER_HPP

#include <paradox-svg/defines.hpp>

namespace Paradox { namespace SVG {
    PARADOX_SVG_API constexpr DataType::B8 ParseFileContents(const DataType::String_t& filename);
}}
#endif