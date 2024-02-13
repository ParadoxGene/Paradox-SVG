#ifndef PARADOX_WORKS_C_CSS_LEXER_HPP
#define PARADOX_WORKS_C_CSS_LEXER_HPP

#include <paradox-css/tracer.hpp>

namespace Paradox { namespace CSS {
    class PARADOX_SVG_API Lexer
    {
    public:
        const DataType::B8 TokenizeFile(const DataType::String_t& filename);

        // Definition: {ident}
        const DataType::B8 TokenizeIdent();

        // Definition: @{ident}
        const DataType::B8 TokenizeATKeyword();

        // Definition: {string}
        const DataType::B8 TokenizeString();

        // Definition: {badstring}
        const DataType::B8 TokenizeBadString();

        // Definition: {baduri}
        const DataType::B8 TokenizeBadURI();

        // Definition: {badcomment}
        const DataType::B8 TokenizeBadComment();

        // Definition: #{name}
        const DataType::B8 TokenizeHash();

        // Definition: {num}
        const DataType::B8 TokenizeNumber();

        // Definition: {num}%
        const DataType::B8 TokenizePercentage();

        // Definition: {num}{ident}
        const DataType::B8 TokenizeDimension();

        /**
         * Definition1: {U}{R}{L}\\({w}{string}{w}\\)
         * Definition2: {U}{R}{L}\\({w}([!#$%&*-\\[\\]-~]|{nonascii}|{escape})*{w}\\)
         */
        const DataType::B8 TokenizeURI();

        /**
         * Definition1: u\\+[?]{1,6}
         * Definition2: u\\+[0-9a-f]{1}[?]{0,5}
         * Definition3: u\\+[0-9a-f]{2}[?]{0,4}
         * Definition4: u\\+[0-9a-f]{3}[?]{0,3}
         * Definition5: u\\+[0-9a-f]{4}[?]{0,2}
         * Definition6: u\\+[0-9a-f]{5}[?]{0,1}
         * Definition7: u\\+[0-9a-f]{6}
         * Definition8: u\\+[0-9a-f]{1,6}-[0-9a-f]{1,6}
         */
        const DataType::B8 TokenizeUnicodeRange();

        // Definition: <!--
        const DataType::B8 TokenizeCDO();

        // Definition: -->
        const DataType::B8 TokenizeCDC();

        // Definition: :
        const DataType::B8 TokenizeColon();

        // Definition: ;
        const DataType::B8 TokenizeSemicolon();

        // Definition: \\{
        const DataType::B8 TokenizeOpenBrace();

        // Definition: \\}
        const DataType::B8 TokenizeCloseBrace();

        // Definition: \\(
        const DataType::B8 TokenizeOpenParenthesis();

        // Definition: \\)
        const DataType::B8 TokenizeCloseParenthesis();

        // Definition: \\[
        const DataType::B8 TokenizeOpenBracket();

        // Definition: \\]
        const DataType::B8 TokenizeCloseBracket();

        // Definition: [ \\t\\r\\n\\f]+
        const DataType::B8 TokenizeS();

        // Definition: \\/\\*[^*]*\\*+([^/*][^*]*\\*+)*\\/
        const DataType::B8 TokenizeComment();

        // Definition: {ident}\\(
        const DataType::B8 TokenizeFunction();

        // Definition: ~=
        const DataType::B8 TokenizeIncludes();

        // Definition: |=
        const DataType::B8 TokenizeDashMatch();

        // Definition: Any other character not matched by the above rules, and neither a single nor a double quote
        const DataType::B8 TokenizeDelim();

        // Macro: [-]?{nmstart}{nmchar}*
        const DataType::B8 ConsumeIdentMacro();

        // Macro: {nmchar}+
        const DataType::B8 ConsumeNameMacro();

        // Macro: [_a-z]|{nonascii}|{escape}
        const DataType::B8 ConsumeNMStartMacro();

        // Macro: [^\0-\177]
        const DataType::B8 ConsumeNonASCIIMacro();

        // Macro: \\\\[0-9a-f]{1,6}(\\r\\n|[ \\n\\r\\t\\f])?
        const DataType::B8 ConsumeUnicodeMacro();

        // Macro: {unicode}|\\\\[^\\n\\r\\f0-9a-f]
        const DataType::B8 ConsumeEscapeMacro();

        // Macro: [_a-z0-9-]|{nonascii}|{escape}
        const DataType::B8 ConsumeNMCharMacro();

        // Macro: [+-]?([0-9]+|[0-9]*\\.[0-9]+)(e[+-]?[0-9]+)?
        const DataType::B8 ConsumeNumMacro();

        // Macro: {string1}|{string2}
        const DataType::B8 ConsumeStringMacro();

        // Macro: \"([^\n\r\f\\"]|\\{nl}|{escape})*\"
        const DataType::B8 ConsumeString1Macro();

        // Macro: \'([^\n\r\f\\']|\\{nl}|{escape})*\'
        const DataType::B8 ConsumeString2Macro();

        // Macro: {badstring1}|{badstring2}
        const DataType::B8 ConsumeBadStringMacro();

        // Macro: \"([^\n\r\f\\"]|\\{nl}|{escape})*\\?
        const DataType::B8 ConsumeBadString1Macro();

        // Macro: \'([^\n\r\f\\']|\\{nl}|{escape})*\\?
        const DataType::B8 ConsumeBadString2Macro();

        // Macro: {badcomment1}|{badcomment2}
        const DataType::B8 ConsumeBadCommentMacro();

        // Macro: \\/\\*[^*]*\\*+([^/*][^*]*\\*+)*
        const DataType::B8 ConsumeBadComment1Macro();

        // Macro: \\/\\*[^*]*(\\*+[^/*][^*]*)*
        const DataType::B8 ConsumeBadComment2Macro();

        // Macro: {baduri1}|{baduri2}|{baduri3}
        const DataType::B8 ConsumeBadURIMacro();

        // Macro:url\\({w}([!#$%&*-~]|{nonascii}|{escape})*{w}
        const DataType::B8 ConsumeBadURI1Macro();

        // Macro: url\\({w}{string}{w}
        const DataType::B8 ConsumeBadURI2Macro();

        // Macro: url\\({w}{badstring}
        const DataType::B8 ConsumeBadURI3Macro();

        // Macro: \\n|\\r\\n|\\r|\\f
        const DataType::B8 ConsumeNlMacro();

        // Macro: [ \\t\\r\\n\\f]*
        const DataType::B8 ConsumeWMacro();

    public:
        // Definition: {ident}
        static const DataType::B8 TokenizeIdent(const DataType::String_t& content);

        // Definition: @{ident}
        static const DataType::B8 TokenizeATKeyword(const DataType::String_t& content);

        // Definition: {string}
        static const DataType::B8 TokenizeString(const DataType::String_t& content);

        // Definition: {badstring}
        static const DataType::B8 TokenizeBadString(const DataType::String_t& content);

        // Definition: {baduri}
        static const DataType::B8 TokenizeBadURI(const DataType::String_t& content);

        // Definition: {badcomment}
        static const DataType::B8 TokenizeBadComment(const DataType::String_t& content);

        // Definition: #{name}
        static const DataType::B8 TokenizeHash(const DataType::String_t& content);

        // Definition: {num}
        static const DataType::B8 TokenizeNumber(const DataType::String_t& content);

        // Definition: {num}%
        static const DataType::B8 TokenizePercentage(const DataType::String_t& content);

        // Definition: {num}{ident}
        static const DataType::B8 TokenizeDimension(const DataType::String_t& content);

        /**
         * Definition1: {U}{R}{L}\\({w}{string}{w}\\)
         * Definition2: {U}{R}{L}\\({w}([!#$%&*-\\[\\]-~]|{nonascii}|{escape})*{w}\\)
         */
        static const DataType::B8 TokenizeURI(const DataType::String_t& content);

        /**
         * Definition1: u\\+[?]{1,6}
         * Definition2: u\\+[0-9a-f]{1}[?]{0,5}
         * Definition3: u\\+[0-9a-f]{2}[?]{0,4}
         * Definition4: u\\+[0-9a-f]{3}[?]{0,3}
         * Definition5: u\\+[0-9a-f]{4}[?]{0,2}
         * Definition6: u\\+[0-9a-f]{5}[?]{0,1}
         * Definition7: u\\+[0-9a-f]{6}
         * Definition8: u\\+[0-9a-f]{1,6}-[0-9a-f]{1,6}
         */
        static const DataType::B8 TokenizeUnicodeRange(const DataType::String_t& content);

        // Definition: <!--
        static const DataType::B8 TokenizeCDO(const DataType::String_t& content);

        // Definition: -->
        static const DataType::B8 TokenizeCDC(const DataType::String_t& content);

        // Definition: :
        static const DataType::B8 TokenizeColon(const DataType::String_t& content);

        // Definition: ;
        static const DataType::B8 TokenizeSemicolon(const DataType::String_t& content);

        // Definition: \\{
        static const DataType::B8 TokenizeOpenBrace(const DataType::String_t& content);

        // Definition: \\}
        static const DataType::B8 TokenizeCloseBrace(const DataType::String_t& content);

        // Definition: \\(
        static const DataType::B8 TokenizeOpenParenthesis(const DataType::String_t& content);

        // Definition: \\)
        static const DataType::B8 TokenizeCloseParenthesis(const DataType::String_t& content);

        // Definition: \\[
        static const DataType::B8 TokenizeOpenBracket(const DataType::String_t& content);

        // Definition: \\]
        static const DataType::B8 TokenizeCloseBracket(const DataType::String_t& content);

        // Definition: [ \\t\\r\\n\\f]+
        static const DataType::B8 TokenizeS(const DataType::String_t& content);

        // Definition: \\/\\*[^*]*\\*+([^/*][^*]*\\*+)*\\/
        static const DataType::B8 TokenizeComment(const DataType::String_t& content);

        // Definition: {ident}\\(
        static const DataType::B8 TokenizeFunction(const DataType::String_t& content);

        // Definition: ~=
        static const DataType::B8 TokenizeIncludes(const DataType::String_t& content);

        // Definition: |=
        static const DataType::B8 TokenizeDashMatch(const DataType::String_t& content);

        // Definition: Any other character not matched by the above rules, and neither a single nor a double quote
        static const DataType::B8 TokenizeDelim(const DataType::String_t& content);

        // Macro: [-]?{nmstart}{nmchar}*
        static const DataType::B8 ConsumeIdentMacro(const DataType::String_t& content);

        // Macro: {nmchar}+
        static const DataType::B8 ConsumeNameMacro(const DataType::String_t& content);

        // Macro: [_a-z]|{nonascii}|{escape}
        static const DataType::B8 ConsumeNMStartMacro(const DataType::String_t& content);

        // Macro: [^\0-\177]
        static const DataType::B8 ConsumeNonASCIIMacro(const DataType::String_t& content);

        // Macro: \\\\[0-9a-f]{1,6}(\\r\\n|[ \\n\\r\\t\\f])?
        static const DataType::B8 ConsumeUnicodeMacro(const DataType::String_t& content);

        // Macro: {unicode}|\\\\[^\\n\\r\\f0-9a-f]
        static const DataType::B8 ConsumeEscapeMacro(const DataType::String_t& content);

        // Macro: [_a-z0-9-]|{nonascii}|{escape}
        static const DataType::B8 ConsumeNMCharMacro(const DataType::String_t& content);

        // Macro: [+-]?([0-9]+|[0-9]*\\.[0-9]+)(e[+-]?[0-9]+)?
        static const DataType::B8 ConsumeNumMacro(const DataType::String_t& content);

        // Macro: {string1}|{string2}
        static const DataType::B8 ConsumeStringMacro(const DataType::String_t& content);

        // Macro: \"([^\n\r\f\\"]|\\{nl}|{escape})*\"
        static const DataType::B8 ConsumeString1Macro(const DataType::String_t& content);

        // Macro: \'([^\n\r\f\\']|\\{nl}|{escape})*\'
        static const DataType::B8 ConsumeString2Macro(const DataType::String_t& content);

        // Macro: {badstring1}|{badstring2}
        static const DataType::B8 ConsumeBadStringMacro(const DataType::String_t& content);

        // Macro: \"([^\n\r\f\\"]|\\{nl}|{escape})*\\?
        static const DataType::B8 ConsumeBadString1Macro(const DataType::String_t& content);

        // Macro: \'([^\n\r\f\\']|\\{nl}|{escape})*\\?
        static const DataType::B8 ConsumeBadString2Macro(const DataType::String_t& content);

        // Macro: {badcomment1}|{badcomment2}
        static const DataType::B8 ConsumeBadCommentMacro(const DataType::String_t& content);

        // Macro: \\/\\*[^*]*\\*+([^/*][^*]*\\*+)*
        static const DataType::B8 ConsumeBadComment1Macro(const DataType::String_t& content);

        // Macro: \\/\\*[^*]*(\\*+[^/*][^*]*)*
        static const DataType::B8 ConsumeBadComment2Macro(const DataType::String_t& content);

        // Macro: {baduri1}|{baduri2}|{baduri3}
        static const DataType::B8 ConsumeBadURIMacro(const DataType::String_t& content);

        // Macro: url\\({w}([!#$%&*-~]|{nonascii}|{escape})*{w}
        static const DataType::B8 ConsumeBadURI1Macro(const DataType::String_t& content);

        // Macro: url\\({w}{string}{w}
        static const DataType::B8 ConsumeBadURI2Macro(const DataType::String_t& content);

        // Macro: url\\({w}{badstring}
        static const DataType::B8 ConsumeBadURI3Macro(const DataType::String_t& content);

        // Macro: \\n|\\r\\n|\\r|\\f
        static const DataType::B8 ConsumeNlMacro(const DataType::String_t& content);

        // Macro: [ \\t\\r\\n\\f]*
        static const DataType::B8 ConsumeWMacro(const DataType::String_t& content);

    private:
        Tracer tracer;
    };
}}

#endif