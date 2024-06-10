#include <paradox-svg/parser.h>
#include <paradox-platform/console.h>

PARADOX_SVG_API const paradox_errno_t paradox_svg_parse_file(paradox_cstr_t path)
{
    FILE* svg_file = NULL;
    paradox_errno_t err;
    if(err = ((svg_file = paradox_bin_dir_fopen(path, "r")) == NULL))
        goto file_open_failed;
        
    fclose(svg_file);
    
    file_open_failed:
    return err;
}