#include <unity.h>

#include <paradox-svg/parser.h>
#include <paradox-css/lexer.h>

void setUp(void)
{
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
}

void test_paradox_svg_parse_file(void)
{
    // test stuff

    if(paradox_svg_parse_file("example1.svg") != 0)
        TEST_FAIL_MESSAGE("Failed to open example1.svg");
}

void test_paradox_css_parse_file(void)
{
    if(!paradox_css_tokenize_file("example1.css"))
        TEST_FAIL_MESSAGE("Failed to open example1.css");
}

void test_paradox_css_tokenize_unicode_range(void)
{
    /* <unicode-range> values */
    paradox_css_tracer* tracer = paradox_css_create_tracer();
    
    /* single code point */
    paradox_css_tracer_load_str(tracer, "U+26");
    TEST_ASSERT_TRUE_MESSAGE(paradox_css_tokenize_unicode_range(tracer), "CSS Lexer failed to tokenize \"U+26\"");
    TEST_ASSERT_TRUE_MESSAGE(tracer->index == tracer->length, "CSS Lexer failed to tokenize all of \"U+26\"");

    /* code point range */
    paradox_css_tracer_load_str(tracer, "u+0-7F");
    TEST_ASSERT_TRUE_MESSAGE(paradox_css_tokenize_unicode_range(tracer), "CSS Lexer failed to tokenize \"u+0-7F\"");
    TEST_ASSERT_TRUE_MESSAGE(tracer->index == tracer->length, "CSS Lexer failed to tokenize all of \"u+0-7F\"");

    paradox_css_tracer_load_str(tracer, "U+0025-00FF");
    TEST_ASSERT_TRUE_MESSAGE(paradox_css_tokenize_unicode_range(tracer), "CSS Lexer failed to tokenize \"u+0025-00FF\"");
    TEST_ASSERT_TRUE_MESSAGE(tracer->index == tracer->length, "CSS Lexer failed to tokenize all of \"u+0025-00FF\"");

    /* wildcard range */
    paradox_css_tracer_load_str(tracer, "U+4??");
    TEST_ASSERT_TRUE_MESSAGE(paradox_css_tokenize_unicode_range(tracer), "CSS Lexer failed to tokenize \"u+4??\"");
    TEST_ASSERT_TRUE_MESSAGE(tracer->index == tracer->length, "CSS Lexer failed to tokenize all of \"u+4??\"");

    paradox_css_destroy_tracer(tracer);
}
void test_paradox_css_tokenize_cdo(void)
{
    paradox_css_tracer* tracer = paradox_css_create_tracer();
    paradox_css_token* token;

    paradox_css_tracer_load_str(tracer, "<!--");
    TEST_ASSERT_TRUE_MESSAGE(paradox_css_tokenize_cdo(tracer, &token), "CSS Lexer failed to tokenize \"<!--\"");
    TEST_ASSERT_TRUE_MESSAGE(tracer->index == tracer->length, "CSS Lexer failed to tokenize all of \"<!--\"");
    TEST_ASSERT_TRUE_MESSAGE(token && token->type == PARADOX_CSS_CDO_TOK, "incorrect token type");
    paradox_css_destroy_token(token);
    paradox_css_destroy_tracer(tracer);
}
void test_paradox_css_tokenize_cdc(void)
{
    paradox_css_tracer* tracer = paradox_css_create_tracer();
    paradox_css_token* token;

    paradox_css_tracer_load_str(tracer, "-->");
    TEST_ASSERT_TRUE_MESSAGE(paradox_css_tokenize_cdc(tracer, &token), "CSS Lexer failed to tokenize \"-->\"");
    TEST_ASSERT_TRUE_MESSAGE(tracer->index == tracer->length, "CSS Lexer failed to tokenize all of \"-->\"");
    TEST_ASSERT_TRUE_MESSAGE(token && token->type == PARADOX_CSS_CDC_TOK, "incorrect token type");
    paradox_css_destroy_token(token);
    paradox_css_destroy_tracer(tracer);
}
void test_paradox_css_tokenize_colon(void)
{
    paradox_css_tracer* tracer = paradox_css_create_tracer();
    paradox_css_token* token;

    paradox_css_tracer_load_str(tracer, ":");
    TEST_ASSERT_TRUE_MESSAGE(paradox_css_tokenize_colon(tracer, &token), "CSS Lexer failed to tokenize \":\"");
    TEST_ASSERT_TRUE_MESSAGE(tracer->index == tracer->length, "CSS Lexer failed to tokenize all of \":\"");
    TEST_ASSERT_TRUE_MESSAGE(token && token->type == PARADOX_CSS_COLON_TOK, "incorrect token type");
    paradox_css_destroy_token(token);
    paradox_css_destroy_tracer(tracer);
}
void test_paradox_css_tokenize_semicolon(void)
{
    paradox_css_tracer* tracer = paradox_css_create_tracer();
    paradox_css_token* token;

    paradox_css_tracer_load_str(tracer, ";");
    TEST_ASSERT_TRUE_MESSAGE(paradox_css_tokenize_semicolon(tracer, &token), "CSS Lexer failed to tokenize \";\"");
    TEST_ASSERT_TRUE_MESSAGE(tracer->index == tracer->length, "CSS Lexer failed to tokenize all of \";\"");
    TEST_ASSERT_TRUE_MESSAGE(token && token->type == PARADOX_CSS_SEMICOLON_TOK, "incorrect token type");
    paradox_css_destroy_token(token);
    paradox_css_destroy_tracer(tracer);
}
void test_paradox_css_tokenize_open_brace(void)
{
    paradox_css_tracer* tracer = paradox_css_create_tracer();
    paradox_css_token* token;

    paradox_css_tracer_load_str(tracer, "{");
    TEST_ASSERT_TRUE_MESSAGE(paradox_css_tokenize_open_brace(tracer, &token), "CSS Lexer failed to tokenize \"{\"");
    TEST_ASSERT_TRUE_MESSAGE(tracer->index == tracer->length, "CSS Lexer failed to tokenize all of \"{\"");
    TEST_ASSERT_TRUE_MESSAGE(token && token->type == PARADOX_CSS_OPEN_BRACE_TOK, "incorrect token type");
    paradox_css_destroy_token(token);
    paradox_css_destroy_tracer(tracer);
}
void test_paradox_css_tokenize_close_brace(void)
{
    paradox_css_tracer* tracer = paradox_css_create_tracer();
    paradox_css_token* token;

    paradox_css_tracer_load_str(tracer, "}");
    TEST_ASSERT_TRUE_MESSAGE(paradox_css_tokenize_close_brace(tracer, &token), "CSS Lexer failed to tokenize \"}\"");
    TEST_ASSERT_TRUE_MESSAGE(tracer->index == tracer->length, "CSS Lexer failed to tokenize all of \"}\"");
    TEST_ASSERT_TRUE_MESSAGE(token && token->type == PARADOX_CSS_CLOSE_BRACE_TOK, "incorrect token type");
    paradox_css_destroy_token(token);
    paradox_css_destroy_tracer(tracer);
}
void test_paradox_css_tokenize_open_parenthesis(void)
{
    paradox_css_tracer* tracer = paradox_css_create_tracer();
    paradox_css_token* token;

    paradox_css_tracer_load_str(tracer, "(");
    TEST_ASSERT_TRUE_MESSAGE(paradox_css_tokenize_open_parenthesis(tracer, &token), "CSS Lexer failed to tokenize \"(\"");
    TEST_ASSERT_TRUE_MESSAGE(tracer->index == tracer->length, "CSS Lexer failed to tokenize all of \"(\"");
    TEST_ASSERT_TRUE_MESSAGE(token && token->type == PARADOX_CSS_OPEN_PAREN_TOK, "incorrect token type");
    paradox_css_destroy_token(token);
    paradox_css_destroy_tracer(tracer);
}
void test_paradox_css_tokenize_close_parenthesis(void)
{
    paradox_css_tracer* tracer = paradox_css_create_tracer();
    paradox_css_token* token;

    paradox_css_tracer_load_str(tracer, ")");
    TEST_ASSERT_TRUE_MESSAGE(paradox_css_tokenize_close_parenthesis(tracer, &token), "CSS Lexer failed to tokenize \")\"");
    TEST_ASSERT_TRUE_MESSAGE(tracer->index == tracer->length, "CSS Lexer failed to tokenize all of \")\"");
    TEST_ASSERT_TRUE_MESSAGE(token && token->type == PARADOX_CSS_CLOSE_PAREN_TOK, "incorrect token type");
    paradox_css_destroy_token(token);
    paradox_css_destroy_tracer(tracer);
}
void test_paradox_css_tokenize_open_bracket(void)
{
    paradox_css_tracer* tracer = paradox_css_create_tracer();
    paradox_css_token* token;

    paradox_css_tracer_load_str(tracer, "[");
    TEST_ASSERT_TRUE_MESSAGE(paradox_css_tokenize_open_bracket(tracer, &token), "CSS Lexer failed to tokenize \"[\"");
    TEST_ASSERT_TRUE_MESSAGE(tracer->index == tracer->length, "CSS Lexer failed to tokenize all of \"[\"");
    TEST_ASSERT_TRUE_MESSAGE(token && token->type == PARADOX_CSS_OPEN_BRACKET_TOK, "incorrect token type");
    paradox_css_destroy_token(token);
    paradox_css_destroy_tracer(tracer);
}
void test_paradox_css_tokenize_close_bracket(void)
{
    paradox_css_tracer* tracer = paradox_css_create_tracer();
    paradox_css_token* token;

    paradox_css_tracer_load_str(tracer, "]");
    TEST_ASSERT_TRUE_MESSAGE(paradox_css_tokenize_close_bracket(tracer, &token), "CSS Lexer failed to tokenize \"]\"");
    TEST_ASSERT_TRUE_MESSAGE(tracer->index == tracer->length, "CSS Lexer failed to tokenize all of \"]\"");
    TEST_ASSERT_TRUE_MESSAGE(token && token->type == PARADOX_CSS_CLOSE_BRACKET_TOK, "incorrect token type");
    paradox_css_destroy_token(token);
    paradox_css_destroy_tracer(tracer);
}
void test_paradox_css_tokenize_includes(void)
{
    paradox_css_tracer* tracer = paradox_css_create_tracer();
    paradox_css_token* token;

    paradox_css_tracer_load_str(tracer, "~=");
    TEST_ASSERT_TRUE_MESSAGE(paradox_css_tokenize_includes(tracer, &token), "CSS Lexer failed to tokenize \"~=\"");
    TEST_ASSERT_TRUE_MESSAGE(tracer->index == tracer->length, "CSS Lexer failed to tokenize all of \"~=\"");
    TEST_ASSERT_TRUE_MESSAGE(token && token->type == PARADOX_CSS_INCLUDES_TOK, "incorrect token type");
    paradox_css_destroy_token(token);
    paradox_css_destroy_tracer(tracer);
}
void test_paradox_css_tokenize_dash_match(void)
{
    paradox_css_tracer* tracer = paradox_css_create_tracer();
    paradox_css_token* token;

    paradox_css_tracer_load_str(tracer, "|=");
    TEST_ASSERT_TRUE_MESSAGE(paradox_css_tokenize_dash_match(tracer, &token), "CSS Lexer failed to tokenize \"|=\"");
    TEST_ASSERT_TRUE_MESSAGE(tracer->index == tracer->length, "CSS Lexer failed to tokenize all of \"|=\"");
    TEST_ASSERT_TRUE_MESSAGE(token && token->type == PARADOX_CSS_DASHMATCH_TOK, "incorrect token type");
    paradox_css_destroy_token(token);
    paradox_css_destroy_tracer(tracer);
}


// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    //RUN_TEST(test_paradox_svg_parse_file);
    //RUN_TEST(test_paradox_css_parse_file);

    TEST_MESSAGE("Running CSS Lexer Tests");
    RUN_TEST(test_paradox_css_tokenize_unicode_range);
    RUN_TEST(test_paradox_css_tokenize_cdo);
    RUN_TEST(test_paradox_css_tokenize_cdc);
    RUN_TEST(test_paradox_css_tokenize_colon);
    RUN_TEST(test_paradox_css_tokenize_semicolon);
    RUN_TEST(test_paradox_css_tokenize_open_brace);
    RUN_TEST(test_paradox_css_tokenize_close_brace);
    RUN_TEST(test_paradox_css_tokenize_open_parenthesis);
    RUN_TEST(test_paradox_css_tokenize_close_parenthesis);
    RUN_TEST(test_paradox_css_tokenize_open_bracket);
    RUN_TEST(test_paradox_css_tokenize_close_bracket);
    RUN_TEST(test_paradox_css_tokenize_includes);
    RUN_TEST(test_paradox_css_tokenize_dash_match);
    return UNITY_END();
}