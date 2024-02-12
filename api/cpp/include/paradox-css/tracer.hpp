#ifndef PARADOX_WORKS_CPP_CSS_TRACER_HPP
#define PARADOX_WORKS_CPP_CSS_TRACER_HPP

#include <paradox-svg/defines.hpp>

namespace Paradox { namespace CSS {
    class PARADOX_SVG_API Tracer
    {
    public:
    private:
        DataType::Str_t content;
        size_t index, length;
    };
}}
#endif