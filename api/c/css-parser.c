#include <paradox-css/parser.h>
#include <paradox-platform/io.h>

PARADOX_SVG_API const paradox_errno_t paradox_css_parse_file(paradox_cstr_t path)
{
    FILE* css_file = NULL;
    paradox_errno_t err;
    if(err = ((css_file = paradox_bin_dir_fopen(path, "r")) == NULL))
        goto file_open_failed;
        
    fclose(css_file);
    
    file_open_failed:
    return err;
}