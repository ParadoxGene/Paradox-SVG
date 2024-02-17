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
    TEST_MESSAGE("CSS Lexer Unicode-Range Tests");
    /* <unicode-range> values */
    paradox_css_tracer* tracer = paradox_css_create_tracer();
    
    /* single code point */
    paradox_css_tracer_load_str(tracer, "U+26");
    TEST_ASSERT_TRUE_MESSAGE(paradox_css_tokenize_unicode_range(tracer), "CSS Lexer failed to tokenize \"U+26\"");

    /* code point range */
    paradox_css_tracer_load_str(tracer, "u+0-7F");
    TEST_ASSERT_TRUE_MESSAGE(paradox_css_tokenize_unicode_range(tracer), "CSS Lexer failed to tokenize \"u+0-7F\"");

    paradox_css_tracer_load_str(tracer, "U+0025-00FF");
    TEST_ASSERT_TRUE_MESSAGE(paradox_css_tokenize_unicode_range(tracer), "CSS Lexer failed to tokenize \"u+0025-00FF\"");

    /* wildcard range */
    paradox_css_tracer_load_str(tracer, "U+4??");
    TEST_ASSERT_TRUE_MESSAGE(paradox_css_tokenize_unicode_range(tracer), "CSS Lexer failed to tokenize \"u+4??\"");

    paradox_css_destroy_tracer(tracer);

}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_paradox_svg_parse_file);
    RUN_TEST(test_paradox_css_parse_file);
    RUN_TEST(test_paradox_css_tokenize_unicode_range);
    return UNITY_END();
}