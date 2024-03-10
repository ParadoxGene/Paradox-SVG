#include <paradox-css/parser.h>
#include <paradox-platform/io.h>

PARADOX_CSS_API const paradox_errno_t paradox_css_parse_file(paradox_cstr_t path)
{
    FILE* css_file = NULL;
    paradox_errno_t err;
    if(err = ((css_file = paradox_bin_dir_fopen(path, "r")) == NULL))
        goto file_open_failed;
        
    fclose(css_file);
    
    file_open_failed:
    return err;
}

PARADOX_CSS_API const paradox_errno_t paradox_css_parse_stylesheet(paradox_css_tracer* tracer)
{
    return 1;
}
PARADOX_CSS_API const paradox_errno_t paradox_css_parse_statement(paradox_css_tracer* tracer)
{
    return 1;
}
PARADOX_CSS_API const paradox_errno_t paradox_css_parse_at_rule(paradox_css_tracer* tracer)
{
    return 1;
}
PARADOX_CSS_API const paradox_errno_t paradox_css_parse_block(paradox_css_tracer* tracer)
{
    return 1;
}
PARADOX_CSS_API const paradox_errno_t paradox_css_parse_ruleset(paradox_css_tracer* tracer)
{
    return 1;
}
PARADOX_CSS_API const paradox_errno_t paradox_css_parse_selector(paradox_css_tracer* tracer)
{
    return 1;
}
PARADOX_CSS_API const paradox_errno_t paradox_css_parse_declaration(paradox_css_tracer* tracer)
{
    return 1;
}
PARADOX_CSS_API const paradox_errno_t paradox_css_parse_property(paradox_css_tracer* tracer)
{
    return 1;
}
PARADOX_CSS_API const paradox_errno_t paradox_css_parse_value(paradox_css_tracer* tracer)
{
    return 1;
}
PARADOX_CSS_API const paradox_errno_t paradox_css_parse_any(paradox_css_tracer* tracer)
{
    return 1;
}
PARADOX_CSS_API const paradox_errno_t paradox_css_parse_unused(paradox_css_tracer* tracer)
{
    return 1;
}
