#include <paradox-svg/parser.h>
#include <paradox-platform/io.h>
#include <stdio.h>

const errno_t paradox_svg_parse_from_file(paradox_cstr_t path)
{
    FILE* svg_file = NULL;
    errno_t err;
    
    if((err = paradox_bin_dir_fopen(&svg_file, path, "r")) != 0)
        goto file_open_failed;
        
    fclose(svg_file);
    
    file_open_failed:
    return err;
}