#ifndef PARADOX_WORKS_CPP_CSS_PARSER_HPP
#define PARADOX_WORKS_CPP_CSS_PARSER_HPP

#include <paradox-css/lexer.hpp>

namespace Paradox { namespace CSS {
    class PARADOX_CSS_API Parser 
    {
    public:
        DataType::B8 ParseFile(const DataType::String_t& filename);

        // Syntax: [ CDO | CDC | S | statement ]*;
        DataType::B8 ParseStyleSheet();

        // Syntax: ruleset | at-rule;
        DataType::B8 ParseStatement();

        // Syntax: ATKEYWORD S* any* [ block | ';' S* ];
        DataType::B8 ParseAtRule();

        // Syntax: '{' S* [ any | block | ATKEYWORD S* | ';' S* ]* '}' S*;
        DataType::B8 ParseBlock();

        // Syntax: selector? '{' S* declaration? [ ';' S* declaration? ]* '}' S*;
        DataType::B8 ParseRuleset();

        // Syntax: any+;
        DataType::B8 ParseSelector();

        // Syntax: property S* ':' S* value;
        DataType::B8 ParseDeclaration();

        // Syntax: IDENT;
        DataType::B8 ParseProperty();


        // Syntax: [ any | block | ATKEYWORD S* ]+;
        DataType::B8 ParseValue();

        /** Syntax:
         * [ IDENT | NUMBER | PERCENTAGE | DIMENSION | STRING
         * | DELIM | URI | HASH | UNICODE-RANGE | INCLUDES
         * | DASHMATCH | ':' | FUNCTION S* [any|unused]* ')'
         * | '(' S* [any|unused]* ')' | '[' S* [any|unused]* ']'
         * ] S*;
         */
        DataType::B8 ParseAny();

        // Syntax: block | ATKEYWORD S* | ';' S* | CDO S* | CDC S*;
        DataType::B8 ParseUnused();

    public:
        // Syntax: [ CDO | CDC | S | statement ]*;
        static DataType::B8 ParseStyleSheet(const DataType::String_t& content);

        // Syntax: ruleset | at-rule;
        static DataType::B8 ParseStatement(const DataType::String_t& content);

        // Syntax: ATKEYWORD S* any* [ block | ';' S* ];
        static DataType::B8 ParseAtRule(const DataType::String_t& content);

        // Syntax: '{' S* [ any | block | ATKEYWORD S* | ';' S* ]* '}' S*;
        static DataType::B8 ParseBlock(const DataType::String_t& content);

        // Syntax: selector? '{' S* declaration? [ ';' S* declaration? ]* '}' S*;
        static DataType::B8 ParseRuleset(const DataType::String_t& content);

        // Syntax: any+;
        static DataType::B8 ParseSelector(const DataType::String_t& content);

        // Syntax: property S* ':' S* value;
        static DataType::B8 ParseDeclaration(const DataType::String_t& content);

        // Syntax: IDENT;
        static DataType::B8 ParseProperty(const DataType::String_t& content);

        // Syntax: [ any | block | ATKEYWORD S* ]+;
        static DataType::B8 ParseValue(const DataType::String_t& content);

        /** Syntax:
         * [ IDENT | NUMBER | PERCENTAGE | DIMENSION | STRING
         * | DELIM | URI | HASH | UNICODE-RANGE | INCLUDES
         * | DASHMATCH | ':' | FUNCTION S* [any|unused]* ')'
         * | '(' S* [any|unused]* ')' | '[' S* [any|unused]* ']'
         * ] S*;
         */
        static DataType::B8 ParseAny(const DataType::String_t& content);

        // Syntax: block | ATKEYWORD S* | ';' S* | CDO S* | CDC S*;
        static DataType::B8 ParseUnused(const DataType::String_t& content);

    private:
        Lexer lexer;
    };
}}

#endif