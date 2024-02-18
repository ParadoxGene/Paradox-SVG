#include <unity.h>

#include <paradox-svg/parser.h>
#include <paradox-css/lexer.h>
#include <string.h>

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
    paradox_css_tracer* tracer = paradox_css_create_tracer();
    paradox_css_token* token;
    paradox_str_t content = NULL;
    paradox_str_t range_start = NULL;
    paradox_str_t range_end = NULL;

    paradox_bool8_t err_found = PARADOX_FALSE;
    paradox_char8_t err_buf[2048];

    for(paradox_int8_t i = 0; i < 4; ++i)
    {
        switch(i) {
        case 0: /* <unicode-range> values */
            content = "U+26";
            range_start = "26";
            break;
        case 1: /* code point range */
            content = "u+0-7F";
            range_start = "0";
            range_end = "7F";
            break;
        case 2:
            content = "U+0025-00FF";
            range_start = "0025";
            range_end = "00FF";
            break;
        case 3: /* wildcard range */
            content = "U+4??";
            range_start = "4??";
            break;
        default:
            return;
        }

        paradox_css_tracer_load_str(tracer, content);
        paradox_css_lexer_errno_t err = paradox_css_tokenize_unicode_range(tracer, &token);
        
        switch(err) {
        case PARADOX_CSS_LEXER_INVALID_CONTENT: {
            err_found = PARADOX_TRUE;
            sprintf(err_buf, "css lexer failed: invalid content while tokenizing \"%s\"", content);
            TEST_MESSAGE(err_buf);
            break;
        }
        case PARADOX_CSS_LEXER_TOKEN_ALLOC_FAILURE: {
            err_found = PARADOX_TRUE;
            sprintf(err_buf, "css lexer failed: could not allocate a token while tokenizing \"%s\"", content);
            TEST_MESSAGE(err_buf);
            break;
        }
        case PARADOX_CSS_LEXER_SUCCESS: {
            if(tracer->index != tracer->length)
            {
                err_found = PARADOX_TRUE;
                sprintf(err_buf, "css lexer failed: entire content was no tokenized  \"%s\"", content);
                TEST_MESSAGE(err_buf);
            }
            if(range_start)
            {
                if(!token->value.unicode_range->start)
                {
                    err_found = PARADOX_TRUE;
                    sprintf(err_buf, "css lexer failed: unicode range start point does not match with \"%s\", range start point: \"\"", range_start);
                    TEST_MESSAGE(err_buf);
                }
                else if(strcmp(range_start, token->value.unicode_range->start))
                {
                    err_found = PARADOX_TRUE;
                    sprintf(err_buf, "css lexer failed: unicode range start point does not match with \"%s\", range start point: \"%s\"", range_start, token->value.unicode_range->start);
                    TEST_MESSAGE(err_buf);
                }
            }
            if(range_end)
            {
                if(!token->value.unicode_range->end)
                {
                    err_found = PARADOX_TRUE;
                    sprintf(err_buf, "css lexer failed: unicode range end point does not match with \"%s\", range end point: \"\"", range_end);
                    TEST_MESSAGE(err_buf);
                }
                else if(strcmp(range_end, token->value.unicode_range->end))
                {
                    err_found = PARADOX_TRUE;
                    sprintf(err_buf, "css lexer failed: unicode range end point does not match with \"%s\", range end point: \"%s\"", range_end, token->value.unicode_range->end);
                    TEST_MESSAGE(err_buf);
                }
            }
            break;
        }

        default: {
            break;
        }}

        if(token)
        {
            paradox_css_destroy_token(token);
            token = NULL;
        }

        content = NULL;
        range_start = NULL;
        range_end = NULL;
    }
    paradox_css_destroy_tracer(tracer);

    if(err_found) TEST_FAIL_MESSAGE("1 or more css lexer error occurred");
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