#include <paradox-css/parser.hpp>

namespace Paradox { namespace CSS {
    PARADOX_SVG_API const DataType::B8 Parser::ParseFile(const DataType::String_t& filename)
	{
		return lexer.TokenizeFile(filename);
	}
	PARADOX_SVG_API const DataType::B8 Parser::ParseStyleSheet()
	{
		return false;
	}
	PARADOX_SVG_API const DataType::B8 Parser::ParseStatement()
	{
		return false;
	}
	PARADOX_SVG_API const DataType::B8 Parser::ParseAtRule()
	{
		return false;
	}
	PARADOX_SVG_API const DataType::B8 Parser::ParseBlock()
	{
		return false;
	}
	PARADOX_SVG_API const DataType::B8 Parser::ParseRuleset()
	{
		return false;
	}
	PARADOX_SVG_API const DataType::B8 Parser::ParseSelector()
	{
		return false;
	}
	PARADOX_SVG_API const DataType::B8 Parser::ParseDeclaration()
	{
		return false;
	}
	PARADOX_SVG_API const DataType::B8 Parser::ParseProperty()
	{
		return false;
	}
	PARADOX_SVG_API const DataType::B8 Parser::ParseValue()
	{
		return false;
	}
	PARADOX_SVG_API const DataType::B8 Parser::ParseAny()
	{
		return false;
	}
	PARADOX_SVG_API const DataType::B8 Parser::ParseUnused()
    {
        return false;
    }
}}

namespace Paradox { namespace CSS {
    PARADOX_SVG_API const DataType::B8 Parser::ParseStyleSheet(const DataType::String_t& content)
	{
		return false;
	}
	PARADOX_SVG_API const DataType::B8 Parser::ParseStatement(const DataType::String_t& content)
	{
		return false;
	}
	PARADOX_SVG_API const DataType::B8 Parser::ParseAtRule(const DataType::String_t& content)
	{
		return false;
	}
	PARADOX_SVG_API const DataType::B8 Parser::ParseBlock(const DataType::String_t& content)
	{
		return false;
	}
	PARADOX_SVG_API const DataType::B8 Parser::ParseRuleset(const DataType::String_t& content)
	{
		return false;
	}
	PARADOX_SVG_API const DataType::B8 Parser::ParseSelector(const DataType::String_t& content)
	{
		return false;
	}
	PARADOX_SVG_API const DataType::B8 Parser::ParseDeclaration(const DataType::String_t& content)
	{
		return false;
	}
	PARADOX_SVG_API const DataType::B8 Parser::ParseProperty(const DataType::String_t& content)
	{
		return false;
	}
	PARADOX_SVG_API const DataType::B8 Parser::ParseValue(const DataType::String_t& content)
	{
		return false;
	}
	PARADOX_SVG_API const DataType::B8 Parser::ParseAny(const DataType::String_t& content)
	{
		return false;
	}
	PARADOX_SVG_API const DataType::B8 Parser::ParseUnused(const DataType::String_t& content)
    {
        return false;
    }
}}
