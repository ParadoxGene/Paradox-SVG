#ifndef PARADOX_WORKS_CPP_CSS_PARSER_HPP
#define PARADOX_WORKS_CPP_CSS_PARSER_HPP

#include <paradox-css/lexer.hpp>

namespace Paradox { namespace CSS {
    class PARADOX_SVG_API Parser 
    {
    public:
        const DataType::B8 ParseFile(const DataType::String_t& filename);

        // Syntax: [ CDO | CDC | S | statement ]*;
        const DataType::B8 ParseStyleSheet();

        // Syntax: ruleset | at-rule;
        const DataType::B8 ParseStatement();

        // Syntax: ATKEYWORD S* any* [ block | ';' S* ];
        const DataType::B8 ParseAtRule();

        // Syntax: '{' S* [ any | block | ATKEYWORD S* | ';' S* ]* '}' S*;
        const DataType::B8 ParseBlock();

        // Syntax: selector? '{' S* declaration? [ ';' S* declaration? ]* '}' S*;
        const DataType::B8 ParseRuleset();

        // Syntax: any+;
        const DataType::B8 ParseSelector();

        // Syntax: property S* ':' S* value;
        const DataType::B8 ParseDeclaration();

        // Syntax: IDENT;
        const DataType::B8 ParseProperty();


        // Syntax: [ any | block | ATKEYWORD S* ]+;
        const DataType::B8 ParseValue();

        /** Syntax:
         * [ IDENT | NUMBER | PERCENTAGE | DIMENSION | STRING
         * | DELIM | URI | HASH | UNICODE-RANGE | INCLUDES
         * | DASHMATCH | ':' | FUNCTION S* [any|unused]* ')'
         * | '(' S* [any|unused]* ')' | '[' S* [any|unused]* ']'
         * ] S*;
         */
        const DataType::B8 ParseAny();

        // Syntax: block | ATKEYWORD S* | ';' S* | CDO S* | CDC S*;
        const DataType::B8 ParseUnused();

    public:
        // Syntax: [ CDO | CDC | S | statement ]*;
        static const DataType::B8 ParseStyleSheet(const DataType::String_t& content);

        // Syntax: ruleset | at-rule;
        static const DataType::B8 ParseStatement(const DataType::String_t& content);

        // Syntax: ATKEYWORD S* any* [ block | ';' S* ];
        static const DataType::B8 ParseAtRule(const DataType::String_t& content);

        // Syntax: '{' S* [ any | block | ATKEYWORD S* | ';' S* ]* '}' S*;
        static const DataType::B8 ParseBlock(const DataType::String_t& content);

        // Syntax: selector? '{' S* declaration? [ ';' S* declaration? ]* '}' S*;
        static const DataType::B8 ParseRuleset(const DataType::String_t& content);

        // Syntax: any+;
        static const DataType::B8 ParseSelector(const DataType::String_t& content);

        // Syntax: property S* ':' S* value;
        static const DataType::B8 ParseDeclaration(const DataType::String_t& content);

        // Syntax: IDENT;
        static const DataType::B8 ParseProperty(const DataType::String_t& content);

        // Syntax: [ any | block | ATKEYWORD S* ]+;
        static const DataType::B8 ParseValue(const DataType::String_t& content);

        /** Syntax:
         * [ IDENT | NUMBER | PERCENTAGE | DIMENSION | STRING
         * | DELIM | URI | HASH | UNICODE-RANGE | INCLUDES
         * | DASHMATCH | ':' | FUNCTION S* [any|unused]* ')'
         * | '(' S* [any|unused]* ')' | '[' S* [any|unused]* ']'
         * ] S*;
         */
        static const DataType::B8 ParseAny(const DataType::String_t& content);

        // Syntax: block | ATKEYWORD S* | ';' S* | CDO S* | CDC S*;
        static const DataType::B8 ParseUnused(const DataType::String_t& content);

    private:
        Lexer lexer;
    };
}}

#endif