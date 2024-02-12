#ifndef PARADOX_WORKS_C_XML_PARSER_H
#define PARADOX_WORKS_C_XML_PARSER_H

#include <paradox-xml/tracer.h>

PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_file(paradox_cstr_t path);

// [1] document ::= ( prolog element Misc* ) - ( Char* RestrictedChar Char* )
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_document(paradox_xml_tracer* tracer);

// [2] Char ::= [#x1-#xD7FF] | [#xE000-#xFFFD] | [#x10000-#x10FFFF]
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_char(paradox_xml_tracer* tracer);

// [2a] RestrictedChar ::= [#x1-#x8] | [#xB-#xC] | [#xE-#x1F] | [#x7F-#x84] | [#x86-#x9F]
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_restricted_char(paradox_xml_tracer* tracer);

// [3] S ::= (#x20 | #x9 | #xD | #xA)+
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_whitespace(paradox_xml_tracer* tracer);

// [4] NameStartChar ::= ":" | [A-Z] | "_" | [a-z] | [#xC0-#xD6] | [#xD8-#xF6] | [#xF8-#x2FF] | [#x370-#x37D] | [#x37F-#x1FFF] | [#x200C-#x200D] | [#x2070-#x218F] | [#x2C00-#x2FEF] | [#x3001-#xD7FF] | [#xF900-#xFDCF] | [#xFDF0-#xFFFD] | [#x10000-#xEFFFF]
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_name_start_char(paradox_xml_tracer* tracer);

// [4a] NameChar ::= NameStartChar | "-" | "." | [0-9] | #xB7 | [#x0300-#x036F] | [#x203F-#x2040]
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_name_char(paradox_xml_tracer* tracer);

// [5] Name ::= NameStartChar (NameChar)*
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_name(paradox_xml_tracer* tracer);

// [6] Names ::= Name (#x20 Name)*
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_names(paradox_xml_tracer* tracer);

// [7] Nmtoken ::= (NameChar)+
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_nm_token(paradox_xml_tracer* tracer);

// [8] Nmtokens ::= Nmtoken (#x20 Nmtoken)*
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_nm_tokens(paradox_xml_tracer* tracer);

// [9] EntityValue ::= '"' ([^%&"] | PEReference | Reference)* '"' | "'" ([^%&'] | PEReference | Reference)* "'"
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_entity_value(paradox_xml_tracer* tracer);

// [10] AttValue ::=  '"' ([^<&"] | Reference)* '"' | "'" ([^<&'] | Reference)* "'"
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_att_value(paradox_xml_tracer* tracer);

// [11] SystemLiteral ::= ('"' [^"]* '"') | ("'" [^']* "'")
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_system_literal(paradox_xml_tracer* tracer);

// [12] PubidLiteral ::= '"' PubidChar* '"' | "'" (PubidChar - "'")* "'"
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_pubid_literal(paradox_xml_tracer* tracer);

// [13] PubidChar ::= #x20 | #xD | #xA | [a-zA-Z0-9] | [-'()+,./:=?;!*#@$_%]
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_pubid_char(paradox_xml_tracer* tracer);

// [14] CharData ::= [^<&]* - ([^<&]* ']]>' [^<&]*)
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_char_data(paradox_xml_tracer* tracer);

// [15] Comment ::= '<!--' ((Char - '-') | ('-' (Char - '-')))* '-->'
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_comment(paradox_xml_tracer* tracer);

// [16] PI ::= '<?' PITarget (S (Char* - (Char* '?>' Char*)))? '?>'
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_pi(paradox_xml_tracer* tracer);

// [17] PITarget ::= Name - (('X' | 'x') ('M' | 'm') ('L' | 'l'))
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_pi_target(paradox_xml_tracer* tracer);

// [18] CDSect ::= CDStart CData CDEnd
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_cd_sect(paradox_xml_tracer* tracer);

// [19] CDStart ::= '<![CDATA['
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_cd_start(paradox_xml_tracer* tracer);

// [20] CData ::= (Char* - (Char* ']]>' Char*))
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_cdata(paradox_xml_tracer* tracer);

// [21] CDEnd ::= ']]>'
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_cd_data(paradox_xml_tracer* tracer);

// [22] prolog ::= XMLDecl Misc* (doctypedecl Misc*)?
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_prolog(paradox_xml_tracer* tracer);

// [23] XMLDecl ::= '<?xml' VersionInfo EncodingDecl? SDDecl? S? '?>'
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_xml_decl(paradox_xml_tracer* tracer);

// [24] VersionInfo ::= S 'version' Eq ("'" VersionNum "'" | '"' VersionNum '"')
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_version_info(paradox_xml_tracer* tracer);

// [25] Eq ::= S? '=' S?
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_eq(paradox_xml_tracer* tracer);

// [26] VersionNum ::=  '1.1'
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_version_num(paradox_xml_tracer* tracer);

// [27] Misc ::= Comment | PI | S
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_misc(paradox_xml_tracer* tracer);

// [28] doctypedecl ::= '<!DOCTYPE' S Name (S ExternalID)? S? ('[' intSubset ']' S?)? '>'
// [VC: Root Element Type] [WFC: External Subset]
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_doctype_decl(paradox_xml_tracer* tracer);

// [28a] DeclSep ::= PEReference | S
// [WFC: PE Between Declarations]
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_decl_sep(paradox_xml_tracer* tracer);

// [28b] intSubset ::= (markupdecl | DeclSep)*
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_int_subset(paradox_xml_tracer* tracer);

// [29] markupdecl ::= elementdecl | AttlistDecl | EntityDecl | NotationDecl | PI | Comment
// [VC: Proper Declaration/PE Nesting] [WFC: PEs in Internal Subset]
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_markup_decl(paradox_xml_tracer* tracer);

// [30] extSubset ::= TextDecl? extSubsetDecl
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_ext_subset(paradox_xml_tracer* tracer);

// [31] extSubsetDecl ::= ( markupdecl | conditionalSect | DeclSep)*
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_ext_subset_decl(paradox_xml_tracer* tracer);

// [32] SDDecl ::= S 'standalone' Eq (("'" ('yes' | 'no') "'") | ('"' ('yes' | 'no') '"'))
// [VC: Standalone Document Declaration]
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_sd_decl(paradox_xml_tracer* tracer);

// [39] element ::= EmptyElemTag | STag content ETag
// [WFC: Element Type Match] [VC: Element Valid]
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_element(paradox_xml_tracer* tracer);

// [40] STag ::= '<' Name (S Attribute)* S? '>'
// [WFC: Unique Att Spec]
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_stag(paradox_xml_tracer* tracer);

// [41] Attribute ::= Name Eq AttValue
// [VC: Attribute Value Type] [WFC: No External Entity References] [WFC: No < in Attribute Values]
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_attribute(paradox_xml_tracer* tracer);

// [42] ETag ::= '</' Name S? '>'
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_etag(paradox_xml_tracer* tracer);

// [43] content ::= CharData? ((element | Reference | CDSect | PI | Comment) CharData?)*
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_content(paradox_xml_tracer* tracer);

// [44] EmptyElemTag ::= '<' Name (S Attribute)* S? '/>'
// [WFC: Unique Att Spec]
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_empty_elem_tag(paradox_xml_tracer* tracer);

// [45] elementdecl ::= '<!ELEMENT' S Name S contentspec S? '>'
// [VC: Unique Element Type Declaration]
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_element_decl(paradox_xml_tracer* tracer);

// [46] contentspec ::= 'EMPTY' | 'ANY' | Mixed | children
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_content_spec(paradox_xml_tracer* tracer);

// [47] children ::= (choice | seq) ('?' | '*' | '+')?
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_children(paradox_xml_tracer* tracer);

// [48] cp ::= (Name | choice | seq) ('?' | '*' | '+')?
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_cp(paradox_xml_tracer* tracer);

// [49] choice ::= '(' S? cp ( S? '|' S? cp )+ S? ')'
// [VC: Proper Group/PE Nesting]
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_choice(paradox_xml_tracer* tracer);

// [50] seq ::= '(' S? cp ( S? ',' S? cp )* S? ')'
// [VC: Proper Group/PE Nesting]
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_seq(paradox_xml_tracer* tracer);

// [51] Mixed ::= '(' S? '#PCDATA' (S? '|' S? Name)* S? ')*' | '(' S? '#PCDATA' S? ')'
// [VC: Proper Group/PE Nesting] [VC: No Duplicate Types]
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_mixed(paradox_xml_tracer* tracer);

// [52] AttlistDecl ::= '<!ATTLIST' S Name AttDef* S? '>'
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_attlist_decl(paradox_xml_tracer* tracer);

// [53] AttDef ::= S Name S AttType S DefaultDecl
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_att_def(paradox_xml_tracer* tracer);

// [54] AttType ::= StringType | TokenizedType | EnumeratedType
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_att_type(paradox_xml_tracer* tracer);

// [55] StringType ::= 'CDATA'
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_string_type(paradox_xml_tracer* tracer);

// [56] TokenizedType ::=
// 'ID' [VC: ID] [VC: One ID per Element Type] [VC: ID Attribute Default]
// | 'IDREF' [VC: IDREF]
// | 'IDREFS' [VC: IDREF]
// | 'ENTITY' [VC: Entity Name]
// | 'ENTITIES' [VC: Entity Name]
// | 'NMTOKEN' [VC: Name Token]
// | 'NMTOKENS' [VC: Name Token]
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_tokenized_type(paradox_xml_tracer* tracer);

// [57] EnumeratedType ::= NotationType | Enumeration
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_enumerated_type(paradox_xml_tracer* tracer);

// [58] NotationType ::= 'NOTATION' S '(' S? Name (S? '|' S? Name)* S? ')'
// [VC: Notation Attributes] [VC: One Notation Per Element Type] [VC: No Notation on Empty Element] [VC: No Duplicate Tokens]
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_notation_type(paradox_xml_tracer* tracer);

// [59] Enumeration ::= '(' S? Nmtoken (S? '|' S? Nmtoken)* S? ')'
// [VC: Enumeration] [VC: No Duplicate Tokens]
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_enumeration(paradox_xml_tracer* tracer);

// [60] DefaultDecl ::= '#REQUIRED' | '#IMPLIED' | (('#FIXED' S)? AttValue)
// [VC: Required Attribute] [VC: Attribute Default Value Syntactically Correct] [WFC: No < in Attribute Values] [VC: Fixed Attribute Default] [WFC: No External Entity References]
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_default_decl(paradox_xml_tracer* tracer);

// [61] conditionalSect ::= includeSect | ignoreSect
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_conditional_sect(paradox_xml_tracer* tracer);

// [62] includeSect ::= '<![' S? 'INCLUDE' S? '[' extSubsetDecl ']]>'
// [VC: Proper Conditional Section/PE Nesting]
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_include_sect(paradox_xml_tracer* tracer);

// [63] ignoreSect ::=  '<![' S? 'IGNORE' S? '[' ignoreSectContents* ']]>'
// [VC: Proper Conditional Section/PE Nesting]
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_ignore_sect(paradox_xml_tracer* tracer);

// [64] ignoreSectContents ::= Ignore ('<![' ignoreSectContents ']]>' Ignore)*
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_ignore_sect_contents(paradox_xml_tracer* tracer);

// [65] Ignore ::= Char* - (Char* ('<![' | ']]>') Char*)
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_ignore(paradox_xml_tracer* tracer);

// [66] CharRef ::= '&#' [0-9]+ ';' | '&#x' [0-9a-fA-F]+ ';'
// [WFC: Legal Character]
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_char_ref(paradox_xml_tracer* tracer);

// [67] Reference ::= EntityRef | CharRef
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_reference(paradox_xml_tracer* tracer);

// [68] EntityRef ::=  '&' Name ';'
// [WFC: Entity Declared] [VC: Entity Declared] [WFC: Parsed Entity] [WFC: No Recursion]
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_entity_ref(paradox_xml_tracer* tracer);

// [69] PEReference ::= '%' Name ';'
// [VC: Entity Declared] [WFC: No Recursion] [WFC: In DTD]
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_pe_reference(paradox_xml_tracer* tracer);

// [70] EntityDecl ::= GEDecl | PEDecl
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_entity_decl(paradox_xml_tracer* tracer);

// [71] GEDecl ::= '<!ENTITY' S Name S EntityDef S? '>'
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_ge_decl(paradox_xml_tracer* tracer);

// [72] PEDecl ::= '<!ENTITY' S '%' S Name S PEDef S? '>'
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_pe_decl(paradox_xml_tracer* tracer);

// [73] EntityDef ::= EntityValue | (ExternalID NDataDecl?)
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_entity_def(paradox_xml_tracer* tracer);

// [74] PEDef ::= EntityValue | ExternalID
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_pe_def(paradox_xml_tracer* tracer);

// [75] ExternalID ::= 'SYSTEM' S SystemLiteral | 'PUBLIC' S PubidLiteral S SystemLiteral
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_external_id(paradox_xml_tracer* tracer);

// [76] NDataDecl ::= S 'NDATA' S Name
// [VC: Notation Declared]
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_ndata_decl(paradox_xml_tracer* tracer);

// [77] TextDecl ::= '<?xml' VersionInfo? EncodingDecl S? '?>'
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_text_decl(paradox_xml_tracer* tracer);

// [78] extParsedEnt ::= ( TextDecl? content ) - ( Char* RestrictedChar Char* )
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_ext_parsed_ent(paradox_xml_tracer* tracer);

// [80] EncodingDecl ::= S 'encoding' Eq ('"' EncName '"' | "'" EncName "'" )
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_encoding_decl(paradox_xml_tracer* tracer);

// [81] EncName ::= [A-Za-z] ([A-Za-z0-9._] | '-')*	/* Encoding name contains only Latin characters */
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_enc_name(paradox_xml_tracer* tracer);

// [82] NotationDecl ::= '<!NOTATION' S Name S (ExternalID | PublicID) S? '>'
// [VC: Unique Notation Name]
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_notation_decl(paradox_xml_tracer* tracer);

// [83] PublicID ::= 'PUBLIC' S PubidLiteral
PARADOX_SVG_API const paradox_errno_t paradox_xml_parse_public_id(paradox_xml_tracer* tracer);

#endif