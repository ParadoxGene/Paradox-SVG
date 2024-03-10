#ifndef PARADOX_WORKS_CPP_XML_TRACER_HPP
#define PARADOX_WORKS_CPP_XML_TRACER_HPP

#include <paradox-xml/defines.hpp>

namespace Paradox { namespace XML {
    class PARADOX_XML_API Tracer
    {
    public:
    private:
        DataType::Str_t content;
        size_t index, length;
    };
}}
#endif