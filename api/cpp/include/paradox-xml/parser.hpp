#ifndef PARADOX_WORKS_CPP_XML_PARSER_HPP
#define PARADOX_WORKS_CPP_XML_PARSER_HPP

#include <paradox-xml/tracer.hpp>

namespace Paradox { namespace XML {
    class PARADOX_SVG_API Parser
    {
    public:
        const DataType::B8 ParseFileContents(const DataType::String_t& filename);

        // [1] document ::= ( prolog element Misc* ) - ( Char* RestrictedChar Char* )
        const DataType::B8 ParseDocument();

        // [2] Char ::= [#x1-#xD7FF] | [#xE000-#xFFFD] | [#x10000-#x10FFFF]
        const DataType::B8 ParseChar();

        // [2a] RestrictedChar ::= [#x1-#x8] | [#xB-#xC] | [#xE-#x1F] | [#x7F-#x84] | [#x86-#x9F]
        const DataType::B8 ParseRestrictedChar();

        // [3] S ::= (#x20 | #x9 | #xD | #xA)+
        const DataType::B8 ParseWhitespace();

        // [4] NameStartChar ::= ":" | [A-Z] | "_" | [a-z] | [#xC0-#xD6] | [#xD8-#xF6] | [#xF8-#x2FF] | [#x370-#x37D] | [#x37F-#x1FFF] | [#x200C-#x200D] | [#x2070-#x218F] | [#x2C00-#x2FEF] | [#x3001-#xD7FF] | [#xF900-#xFDCF] | [#xFDF0-#xFFFD] | [#x10000-#xEFFFF]
        const DataType::B8 ParseNameStartChar();

        // [4a] NameChar ::= NameStartChar | "-" | "." | [0-9] | #xB7 | [#x0300-#x036F] | [#x203F-#x2040]
        const DataType::B8 ParseNameChar();

        // [5] Name ::= NameStartChar (NameChar)*
        const DataType::B8 ParseName();

        // [6] Names ::= Name (#x20 Name)*
        const DataType::B8 ParseNames();

        // [7] Nmtoken ::= (NameChar)+
        const DataType::B8 ParseNMToken();

        // [8] Nmtokens ::= Nmtoken (#x20 Nmtoken)*
        const DataType::B8 ParseNMTokens();

        // [9] EntityValue ::= '"' ([^%&"] | PEReference | Reference)* '"' | "'" ([^%&'] | PEReference | Reference)* "'"
        const DataType::B8 ParseEntityValue();

        // [10] AttValue ::=  '"' ([^<&"] | Reference)* '"' | "'" ([^<&'] | Reference)* "'"
        const DataType::B8 ParseAttValue();

        // [11] SystemLiteral ::= ('"' [^"]* '"') | ("'" [^']* "'")
        const DataType::B8 ParseSystemLiteral();

        // [12] PubidLiteral ::= '"' PubidChar* '"' | "'" (PubidChar - "'")* "'"
        const DataType::B8 ParsePubidLiteral();

        // [13] PubidChar ::= #x20 | #xD | #xA | [a-zA-Z0-9] | [-'()+,./:=?;!*#@$_%]
        const DataType::B8 ParsePubidChar();

        // [14] CharData ::= [^<&]* - ([^<&]* ']]>' [^<&]*)
        const DataType::B8 ParseCharData();

        // [15] Comment ::= '<!--' ((Char - '-') | ('-' (Char - '-')))* '-->'
        const DataType::B8 ParseComment();

        // [16] PI ::= '<?' PITarget (S (Char* - (Char* '?>' Char*)))? '?>'
        const DataType::B8 ParsePI();

        // [17] PITarget ::= Name - (('X' | 'x') ('M' | 'm') ('L' | 'l'))
        const DataType::B8 ParsePITarget();

        // [18] CDSect ::= CDStart CData CDEnd
        const DataType::B8 ParseCDSect();

        // [19] CDStart ::= '<![CDATA['
        const DataType::B8 ParseCDStart();

        // [20] CData ::= (Char* - (Char* ']]>' Char*))
        const DataType::B8 ParseCData();

        // [21] CDEnd ::= ']]>'
        const DataType::B8 ParseCDData();

        // [22] prolog ::= XMLDecl Misc* (doctypedecl Misc*)?
        const DataType::B8 ParseProlog();

        // [23] XMLDecl ::= '<?xml' VersionInfo EncodingDecl? SDDecl? S? '?>'
        const DataType::B8 ParseXMLDecl();

        // [24] VersionInfo ::= S 'version' Eq ("'" VersionNum "'" | '"' VersionNum '"')
        const DataType::B8 ParseVersionInfo();

        // [25] Eq ::= S? '=' S?
        const DataType::B8 ParseEq();

        // [26] VersionNum ::=  '1.1'
        const DataType::B8 ParseVersionNum();

        // [27] Misc ::= Comment | PI | S
        const DataType::B8 ParseMisc();

        // [28] doctypedecl ::= '<!DOCTYPE' S Name (S ExternalID)? S? ('[' intSubset ']' S?)? '>'
        // [VC: Root Element Type] [WFC: External Subset]
        const DataType::B8 ParseDoctypeDecl();

        // [28a] DeclSep ::= PEReference | S
        // [WFC: PE Between Declarations]
        const DataType::B8 ParseDeclSep();

        // [28b] intSubset ::= (markupdecl | DeclSep)*
        const DataType::B8 ParseIntSubset();

        // [29] markupdecl ::= elementdecl | AttlistDecl | EntityDecl | NotationDecl | PI | Comment
        // [VC: Proper Declaration/PE Nesting] [WFC: PEs in Internal Subset]
        const DataType::B8 ParseMarkupDecl();

        // [30] extSubset ::= TextDecl? extSubsetDecl
        const DataType::B8 ParseExtSubset();

        // [31] extSubsetDecl ::= ( markupdecl | conditionalSect | DeclSep)*
        const DataType::B8 ParseExtSubsetDecl();

        // [32] SDDecl ::= S 'standalone' Eq (("'" ('yes' | 'no') "'") | ('"' ('yes' | 'no') '"'))
        // [VC: Standalone Document Declaration]
        const DataType::B8 ParseSDDecl();

        // [39] element ::= EmptyElemTag | STag content ETag
        // [WFC: Element Type Match] [VC: Element Valid]
        const DataType::B8 ParseElement();

        // [40] STag ::= '<' Name (S Attribute)* S? '>'
        // [WFC: Unique Att Spec]
        const DataType::B8 ParseSTag();

        // [41] Attribute ::= Name Eq AttValue
        // [VC: Attribute Value Type] [WFC: No External Entity References] [WFC: No < in Attribute Values]
        const DataType::B8 ParseAttribute();

        // [42] ETag ::= '</' Name S? '>'
        const DataType::B8 ParseETag();

        // [43] content ::= CharData? ((element | Reference | CDSect | PI | Comment) CharData?)*
        const DataType::B8 ParseContent();

        // [44] EmptyElemTag ::= '<' Name (S Attribute)* S? '/>'
        // [WFC: Unique Att Spec]
        const DataType::B8 ParseEmptyElemTag();

        // [45] elementdecl ::= '<!ELEMENT' S Name S contentspec S? '>'
        // [VC: Unique Element Type Declaration]
        const DataType::B8 ParseElementDecl();

        // [46] contentspec ::= 'EMPTY' | 'ANY' | Mixed | children
        const DataType::B8 ParseContentSpec();

        // [47] children ::= (choice | seq) ('?' | '*' | '+')?
        const DataType::B8 ParseChildren();

        // [48] cp ::= (Name | choice | seq) ('?' | '*' | '+')?
        const DataType::B8 ParseCP();

        // [49] choice ::= '(' S? cp ( S? '|' S? cp )+ S? ')'
        // [VC: Proper Group/PE Nesting]
        const DataType::B8 ParseChoice();

        // [50] seq ::= '(' S? cp ( S? ',' S? cp )* S? ')'
        // [VC: Proper Group/PE Nesting]
        const DataType::B8 ParseSeq();

        // [51] Mixed ::= '(' S? '#PCDATA' (S? '|' S? Name)* S? ')*' | '(' S? '#PCDATA' S? ')'
        // [VC: Proper Group/PE Nesting] [VC: No Duplicate Types]
        const DataType::B8 ParseMixed();

        // [52] AttlistDecl ::= '<!ATTLIST' S Name AttDef* S? '>'
        const DataType::B8 ParseAttlistDecl();

        // [53] AttDef ::= S Name S AttType S DefaultDecl
        const DataType::B8 ParseAttDef();

        // [54] AttType ::= StringType | TokenizedType | EnumeratedType
        const DataType::B8 ParseAttType();

        // [55] StringType ::= 'CDATA'
        const DataType::B8 ParseStringType();

        // [56] TokenizedType ::=
        // 'ID' [VC: ID] [VC: One ID per Element Type] [VC: ID Attribute Default]
        // | 'IDREF' [VC: IDREF]
        // | 'IDREFS' [VC: IDREF]
        // | 'ENTITY' [VC: Entity Name]
        // | 'ENTITIES' [VC: Entity Name]
        // | 'NMTOKEN' [VC: Name Token]
        // | 'NMTOKENS' [VC: Name Token]
        const DataType::B8 ParseTokenizedType();

        // [57] EnumeratedType ::= NotationType | Enumeration
        const DataType::B8 ParseEnumeratedType();

        // [58] NotationType ::= 'NOTATION' S '(' S? Name (S? '|' S? Name)* S? ')'
        // [VC: Notation Attributes] [VC: One Notation Per Element Type] [VC: No Notation on Empty Element] [VC: No Duplicate Tokens]
        const DataType::B8 ParseNotationType();

        // [59] Enumeration ::= '(' S? Nmtoken (S? '|' S? Nmtoken)* S? ')'
        // [VC: Enumeration] [VC: No Duplicate Tokens]
        const DataType::B8 ParseEnumeration();

        // [60] DefaultDecl ::= '#REQUIRED' | '#IMPLIED' | (('#FIXED' S)? AttValue)
        // [VC: Required Attribute] [VC: Attribute Default Value Syntactically Correct] [WFC: No < in Attribute Values] [VC: Fixed Attribute Default] [WFC: No External Entity References]
        const DataType::B8 ParseDefaultDecl();

        // [61] conditionalSect ::= includeSect | ignoreSect
        const DataType::B8 ParseConditionalSect();

        // [62] includeSect ::= '<![' S? 'INCLUDE' S? '[' extSubsetDecl ']]>'
        // [VC: Proper Conditional Section/PE Nesting]
        const DataType::B8 ParseIncludeSect();

        // [63] ignoreSect ::=  '<![' S? 'IGNORE' S? '[' ignoreSectContents* ']]>'
        // [VC: Proper Conditional Section/PE Nesting]
        const DataType::B8 ParseIgnoreSect();

        // [64] ignoreSectContents ::= Ignore ('<![' ignoreSectContents ']]>' Ignore)*
        const DataType::B8 ParseIgnoreSectContents();

        // [65] Ignore ::= Char* - (Char* ('<![' | ']]>') Char*)
        const DataType::B8 ParseIgnore();

        // [66] CharRef ::= '&#' [0-9]+ ';' | '&#x' [0-9a-fA-F]+ ';'
        // [WFC: Legal Character]
        const DataType::B8 ParseCharRef();

        // [67] Reference ::= EntityRef | CharRef
        const DataType::B8 ParseReference();

        // [68] EntityRef ::=  '&' Name ';'
        // [WFC: Entity Declared] [VC: Entity Declared] [WFC: Parsed Entity] [WFC: No Recursion]
        const DataType::B8 ParseEntityRef();

        // [69] PEReference ::= '%' Name ';'
        // [VC: Entity Declared] [WFC: No Recursion] [WFC: In DTD]
        const DataType::B8 ParsePEReference();

        // [70] EntityDecl ::= GEDecl | PEDecl
        const DataType::B8 ParseEntityDecl();

        // [71] GEDecl ::= '<!ENTITY' S Name S EntityDef S? '>'
        const DataType::B8 ParseGEDecl();

        // [72] PEDecl ::= '<!ENTITY' S '%' S Name S PEDef S? '>'
        const DataType::B8 ParsePEDecl();

        // [73] EntityDef ::= EntityValue | (ExternalID NDataDecl?)
        const DataType::B8 ParseEntityDef();

        // [74] PEDef ::= EntityValue | ExternalID
        const DataType::B8 ParsePEDef();

        // [75] ExternalID ::= 'SYSTEM' S SystemLiteral | 'PUBLIC' S PubidLiteral S SystemLiteral
        const DataType::B8 ParseExternalID();

        // [76] NDataDecl ::= S 'NDATA' S Name
        // [VC: Notation Declared]
        const DataType::B8 ParseNDataDecl();

        // [77] TextDecl ::= '<?xml' VersionInfo? EncodingDecl S? '?>'
        const DataType::B8 ParseTextDecl();

        // [78] extParsedEnt ::= ( TextDecl? content ) - ( Char* RestrictedChar Char* )
        const DataType::B8 ParseExtParsedEnt();

        // [80] EncodingDecl ::= S 'encoding' Eq ('"' EncName '"' | "'" EncName "'" )
        const DataType::B8 ParseEncodingDecl();

        // [81] EncName ::= [A-Za-z] ([A-Za-z0-9._] | '-')*	/* Encoding name contains only Latin characters */
        const DataType::B8 ParseEncName();

        // [82] NotationDecl ::= '<!NOTATION' S Name S (ExternalID | PublicID) S? '>'
        // [VC: Unique Notation Name]
        const DataType::B8 ParseNotationDecl();

        // [83] PublicID ::= 'PUBLIC' S PubidLiteral
        const DataType::B8 ParsePublicID();

    public:
        // [1] document ::= ( prolog element Misc* ) - ( Char* RestrictedChar Char* )
        static const DataType::B8 ParseDocument(const DataType::String_t& content);

        // [2] Char ::= [#x1-#xD7FF] | [#xE000-#xFFFD] | [#x10000-#x10FFFF]
        static const DataType::B8 ParseChar(const DataType::String_t& content);

        // [2a] RestrictedChar ::= [#x1-#x8] | [#xB-#xC] | [#xE-#x1F] | [#x7F-#x84] | [#x86-#x9F]
        static const DataType::B8 ParseRestrictedChar(const DataType::String_t& content);

        // [3] S ::= (#x20 | #x9 | #xD | #xA)+
        static const DataType::B8 ParseWhitespace(const DataType::String_t& content);

        // [4] NameStartChar ::= ":" | [A-Z] | "_" | [a-z] | [#xC0-#xD6] | [#xD8-#xF6] | [#xF8-#x2FF] | [#x370-#x37D] | [#x37F-#x1FFF] | [#x200C-#x200D] | [#x2070-#x218F] | [#x2C00-#x2FEF] | [#x3001-#xD7FF] | [#xF900-#xFDCF] | [#xFDF0-#xFFFD] | [#x10000-#xEFFFF]
        static const DataType::B8 ParseNameStartChar(const DataType::String_t& content);

        // [4a] NameChar ::= NameStartChar | "-" | "." | [0-9] | #xB7 | [#x0300-#x036F] | [#x203F-#x2040]
        static const DataType::B8 ParseNameChar(const DataType::String_t& content);

        // [5] Name ::= NameStartChar (NameChar)*
        static const DataType::B8 ParseName(const DataType::String_t& content);

        // [6] Names ::= Name (#x20 Name)*
        static const DataType::B8 ParseNames(const DataType::String_t& content);

        // [7] Nmtoken ::= (NameChar)+
        static const DataType::B8 ParseNMToken(const DataType::String_t& content);

        // [8] Nmtokens ::= Nmtoken (#x20 Nmtoken)*
        static const DataType::B8 ParseNMTokens(const DataType::String_t& content);

        // [9] EntityValue ::= '"' ([^%&"] | PEReference | Reference)* '"' | "'" ([^%&'] | PEReference | Reference)* "'"
        static const DataType::B8 ParseEntityValue(const DataType::String_t& content);

        // [10] AttValue ::=  '"' ([^<&"] | Reference)* '"' | "'" ([^<&'] | Reference)* "'"
        static const DataType::B8 ParseAttValue(const DataType::String_t& content);

        // [11] SystemLiteral ::= ('"' [^"]* '"') | ("'" [^']* "'")
        static const DataType::B8 ParseSystemLiteral(const DataType::String_t& content);

        // [12] PubidLiteral ::= '"' PubidChar* '"' | "'" (PubidChar - "'")* "'"
        static const DataType::B8 ParsePubidLiteral(const DataType::String_t& content);

        // [13] PubidChar ::= #x20 | #xD | #xA | [a-zA-Z0-9] | [-'()+,./:=?;!*#@$_%]
        static const DataType::B8 ParsePubidChar(const DataType::String_t& content);

        // [14] CharData ::= [^<&]* - ([^<&]* ']]>' [^<&]*)
        static const DataType::B8 ParseCharData(const DataType::String_t& content);

        // [15] Comment ::= '<!--' ((Char - '-') | ('-' (Char - '-')))* '-->'
        static const DataType::B8 ParseComment(const DataType::String_t& content);

        // [16] PI ::= '<?' PITarget (S (Char* - (Char* '?>' Char*)))? '?>'
        static const DataType::B8 ParsePI(const DataType::String_t& content);

        // [17] PITarget ::= Name - (('X' | 'x') ('M' | 'm') ('L' | 'l'))
        static const DataType::B8 ParsePITarget(const DataType::String_t& content);

        // [18] CDSect ::= CDStart CData CDEnd
        static const DataType::B8 ParseCDSect(const DataType::String_t& content);

        // [19] CDStart ::= '<![CDATA['
        static const DataType::B8 ParseCDStart(const DataType::String_t& content);

        // [20] CData ::= (Char* - (Char* ']]>' Char*))
        static const DataType::B8 ParseCData(const DataType::String_t& content);

        // [21] CDEnd ::= ']]>'
        static const DataType::B8 ParseCDData(const DataType::String_t& content);

        // [22] prolog ::= XMLDecl Misc* (doctypedecl Misc*)?
        static const DataType::B8 ParseProlog(const DataType::String_t& content);

        // [23] XMLDecl ::= '<?xml' VersionInfo EncodingDecl? SDDecl? S? '?>'
        static const DataType::B8 ParseXMLDecl(const DataType::String_t& content);

        // [24] VersionInfo ::= S 'version' Eq ("'" VersionNum "'" | '"' VersionNum '"')
        static const DataType::B8 ParseVersionInfo(const DataType::String_t& content);

        // [25] Eq ::= S? '=' S?
        static const DataType::B8 ParseEq(const DataType::String_t& content);

        // [26] VersionNum ::=  '1.1'
        static const DataType::B8 ParseVersionNum(const DataType::String_t& content);

        // [27] Misc ::= Comment | PI | S
        static const DataType::B8 ParseMisc(const DataType::String_t& content);

        // [28] doctypedecl ::= '<!DOCTYPE' S Name (S ExternalID)? S? ('[' intSubset ']' S?)? '>'
        // [VC: Root Element Type] [WFC: External Subset]
        static const DataType::B8 ParseDoctypeDecl(const DataType::String_t& content);

        // [28a] DeclSep ::= PEReference | S
        // [WFC: PE Between Declarations]
        static const DataType::B8 ParseDeclSep(const DataType::String_t& content);

        // [28b] intSubset ::= (markupdecl | DeclSep)*
        static const DataType::B8 ParseIntSubset(const DataType::String_t& content);

        // [29] markupdecl ::= elementdecl | AttlistDecl | EntityDecl | NotationDecl | PI | Comment
        // [VC: Proper Declaration/PE Nesting] [WFC: PEs in Internal Subset]
        static const DataType::B8 ParseMarkupDecl(const DataType::String_t& content);

        // [30] extSubset ::= TextDecl? extSubsetDecl
        static const DataType::B8 ParseExtSubset(const DataType::String_t& content);

        // [31] extSubsetDecl ::= ( markupdecl | conditionalSect | DeclSep)*
        static const DataType::B8 ParseExtSubsetDecl(const DataType::String_t& content);

        // [32] SDDecl ::= S 'standalone' Eq (("'" ('yes' | 'no') "'") | ('"' ('yes' | 'no') '"'))
        // [VC: Standalone Document Declaration]
        static const DataType::B8 ParseSDDecl(const DataType::String_t& content);

        // [39] element ::= EmptyElemTag | STag content ETag
        // [WFC: Element Type Match] [VC: Element Valid]
        static const DataType::B8 ParseElement(const DataType::String_t& content);

        // [40] STag ::= '<' Name (S Attribute)* S? '>'
        // [WFC: Unique Att Spec]
        static const DataType::B8 ParseSTag(const DataType::String_t& content);

        // [41] Attribute ::= Name Eq AttValue
        // [VC: Attribute Value Type] [WFC: No External Entity References] [WFC: No < in Attribute Values]
        static const DataType::B8 ParseAttribute(const DataType::String_t& content);

        // [42] ETag ::= '</' Name S? '>'
        static const DataType::B8 ParseETag(const DataType::String_t& content);

        // [43] content ::= CharData? ((element | Reference | CDSect | PI | Comment) CharData?)*
        static const DataType::B8 ParseContent(const DataType::String_t& content);

        // [44] EmptyElemTag ::= '<' Name (S Attribute)* S? '/>'
        // [WFC: Unique Att Spec]
        static const DataType::B8 ParseEmptyElemTag(const DataType::String_t& content);

        // [45] elementdecl ::= '<!ELEMENT' S Name S contentspec S? '>'
        // [VC: Unique Element Type Declaration]
        static const DataType::B8 ParseElementDecl(const DataType::String_t& content);

        // [46] contentspec ::= 'EMPTY' | 'ANY' | Mixed | children
        static const DataType::B8 ParseContentSpec(const DataType::String_t& content);

        // [47] children ::= (choice | seq) ('?' | '*' | '+')?
        static const DataType::B8 ParseChildren(const DataType::String_t& content);

        // [48] cp ::= (Name | choice | seq) ('?' | '*' | '+')?
        static const DataType::B8 ParseCP(const DataType::String_t& content);

        // [49] choice ::= '(' S? cp ( S? '|' S? cp )+ S? ')'
        // [VC: Proper Group/PE Nesting]
        static const DataType::B8 ParseChoice(const DataType::String_t& content);

        // [50] seq ::= '(' S? cp ( S? ',' S? cp )* S? ')'
        // [VC: Proper Group/PE Nesting]
        static const DataType::B8 ParseSeq(const DataType::String_t& content);

        // [51] Mixed ::= '(' S? '#PCDATA' (S? '|' S? Name)* S? ')*' | '(' S? '#PCDATA' S? ')'
        // [VC: Proper Group/PE Nesting] [VC: No Duplicate Types]
        static const DataType::B8 ParseMixed(const DataType::String_t& content);

        // [52] AttlistDecl ::= '<!ATTLIST' S Name AttDef* S? '>'
        static const DataType::B8 ParseAttlistDecl(const DataType::String_t& content);

        // [53] AttDef ::= S Name S AttType S DefaultDecl
        static const DataType::B8 ParseAttDef(const DataType::String_t& content);

        // [54] AttType ::= StringType | TokenizedType | EnumeratedType
        static const DataType::B8 ParseAttType(const DataType::String_t& content);

        // [55] StringType ::= 'CDATA'
        static const DataType::B8 ParseStringType(const DataType::String_t& content);

        // [56] TokenizedType ::=
        // 'ID' [VC: ID] [VC: One ID per Element Type] [VC: ID Attribute Default]
        // | 'IDREF' [VC: IDREF]
        // | 'IDREFS' [VC: IDREF]
        // | 'ENTITY' [VC: Entity Name]
        // | 'ENTITIES' [VC: Entity Name]
        // | 'NMTOKEN' [VC: Name Token]
        // | 'NMTOKENS' [VC: Name Token]
        static const DataType::B8 ParseTokenizedType(const DataType::String_t& content);

        // [57] EnumeratedType ::= NotationType | Enumeration
        static const DataType::B8 ParseEnumeratedType(const DataType::String_t& content);

        // [58] NotationType ::= 'NOTATION' S '(' S? Name (S? '|' S? Name)* S? ')'
        // [VC: Notation Attributes] [VC: One Notation Per Element Type] [VC: No Notation on Empty Element] [VC: No Duplicate Tokens]
        static const DataType::B8 ParseNotationType(const DataType::String_t& content);

        // [59] Enumeration ::= '(' S? Nmtoken (S? '|' S? Nmtoken)* S? ')'
        // [VC: Enumeration] [VC: No Duplicate Tokens]
        static const DataType::B8 ParseEnumeration(const DataType::String_t& content);

        // [60] DefaultDecl ::= '#REQUIRED' | '#IMPLIED' | (('#FIXED' S)? AttValue)
        // [VC: Required Attribute] [VC: Attribute Default Value Syntactically Correct] [WFC: No < in Attribute Values] [VC: Fixed Attribute Default] [WFC: No External Entity References]
        static const DataType::B8 ParseDefaultDecl(const DataType::String_t& content);

        // [61] conditionalSect ::= includeSect | ignoreSect
        static const DataType::B8 ParseConditionalSect(const DataType::String_t& content);

        // [62] includeSect ::= '<![' S? 'INCLUDE' S? '[' extSubsetDecl ']]>'
        // [VC: Proper Conditional Section/PE Nesting]
        static const DataType::B8 ParseIncludeSect(const DataType::String_t& content);

        // [63] ignoreSect ::=  '<![' S? 'IGNORE' S? '[' ignoreSectContents* ']]>'
        // [VC: Proper Conditional Section/PE Nesting]
        static const DataType::B8 ParseIgnoreSect(const DataType::String_t& content);

        // [64] ignoreSectContents ::= Ignore ('<![' ignoreSectContents ']]>' Ignore)*
        static const DataType::B8 ParseIgnoreSectContents(const DataType::String_t& content);

        // [65] Ignore ::= Char* - (Char* ('<![' | ']]>') Char*)
        static const DataType::B8 ParseIgnore(const DataType::String_t& content);

        // [66] CharRef ::= '&#' [0-9]+ ';' | '&#x' [0-9a-fA-F]+ ';'
        // [WFC: Legal Character]
        static const DataType::B8 ParseCharRef(const DataType::String_t& content);

        // [67] Reference ::= EntityRef | CharRef
        static const DataType::B8 ParseReference(const DataType::String_t& content);

        // [68] EntityRef ::=  '&' Name ';'
        // [WFC: Entity Declared] [VC: Entity Declared] [WFC: Parsed Entity] [WFC: No Recursion]
        static const DataType::B8 ParseEntityRef(const DataType::String_t& content);

        // [69] PEReference ::= '%' Name ';'
        // [VC: Entity Declared] [WFC: No Recursion] [WFC: In DTD]
        static const DataType::B8 ParsePEReference(const DataType::String_t& content);

        // [70] EntityDecl ::= GEDecl | PEDecl
        static const DataType::B8 ParseEntityDecl(const DataType::String_t& content);

        // [71] GEDecl ::= '<!ENTITY' S Name S EntityDef S? '>'
        static const DataType::B8 ParseGEDecl(const DataType::String_t& content);

        // [72] PEDecl ::= '<!ENTITY' S '%' S Name S PEDef S? '>'
        static const DataType::B8 ParsePEDecl(const DataType::String_t& content);

        // [73] EntityDef ::= EntityValue | (ExternalID NDataDecl?)
        static const DataType::B8 ParseEntityDef(const DataType::String_t& content);

        // [74] PEDef ::= EntityValue | ExternalID
        static const DataType::B8 ParsePEDef(const DataType::String_t& content);

        // [75] ExternalID ::= 'SYSTEM' S SystemLiteral | 'PUBLIC' S PubidLiteral S SystemLiteral
        static const DataType::B8 ParseExternalID(const DataType::String_t& content);

        // [76] NDataDecl ::= S 'NDATA' S Name
        // [VC: Notation Declared]
        static const DataType::B8 ParseNDataDecl(const DataType::String_t& content);

        // [77] TextDecl ::= '<?xml' VersionInfo? EncodingDecl S? '?>'
        static const DataType::B8 ParseTextDecl(const DataType::String_t& content);

        // [78] extParsedEnt ::= ( TextDecl? content ) - ( Char* RestrictedChar Char* )
        static const DataType::B8 ParseExtParsedEnt(const DataType::String_t& content);

        // [80] EncodingDecl ::= S 'encoding' Eq ('"' EncName '"' | "'" EncName "'" )
        static const DataType::B8 ParseEncodingDecl(const DataType::String_t& content);

        // [81] EncName ::= [A-Za-z] ([A-Za-z0-9._] | '-')*	/* Encoding name contains only Latin characters */
        static const DataType::B8 ParseEncName(const DataType::String_t& content);

        // [82] NotationDecl ::= '<!NOTATION' S Name S (ExternalID | PublicID) S? '>'
        // [VC: Unique Notation Name]
        static const DataType::B8 ParseNotationDecl(const DataType::String_t& content);

        // [83] PublicID ::= 'PUBLIC' S PubidLiteral
        static const DataType::B8 ParsePublicID(const DataType::String_t& content);

    private:
        Tracer tracer;
    };
    

}}
#endif