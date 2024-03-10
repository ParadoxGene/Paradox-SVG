#ifndef PARADOX_WORKS_CPP_CSS_TRACER_HPP
#define PARADOX_WORKS_CPP_CSS_TRACER_HPP

#include <paradox-css/defines.hpp>

namespace Paradox { namespace CSS {
    class PARADOX_CSS_API Tracer
    {
    public:
    private:
        DataType::Str_t content;
        size_t index, length;
    };
}}
#endif