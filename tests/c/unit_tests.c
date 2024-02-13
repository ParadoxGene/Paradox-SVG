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
    TEST_FAIL_MESSAGE("Failed to open example1.css");
    if(paradox_css_tokenize_file("example1.css") != 0)
        TEST_FAIL_MESSAGE("Failed to open example1.css");
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_paradox_svg_parse_file);
    RUN_TEST(test_paradox_css_parse_file);
    return UNITY_END();
}