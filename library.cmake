paradox_add_git_library(PARADOX_PLATFORM paradox-platform "main")

paradox_append_git_include(PARADOX_CSS "paradox-platform")
paradox_append_src_include(PARADOX_CSS "paradox-css")
paradox_append_link_lib(PARADOX_CSS "paradox-platform")
paradox_add_library(PARADOX_CSS paradox-css ${PARADOX_SVG_DIR})

paradox_append_git_include(PARADOX_XML "paradox-platform")
paradox_append_src_include(PARADOX_XML "paradox-xml")
paradox_append_link_lib(PARADOX_XML "paradox-platform")
paradox_add_library(PARADOX_XML paradox-xml ${PARADOX_SVG_DIR})

paradox_append_git_include(PARADOX_SVG "paradox-platform")
paradox_append_src_include(PARADOX_SVG "paradox-svg;paradox-xml;paradox-css;")
paradox_append_link_lib(PARADOX_SVG "paradox-xml;paradox-css;paradox-platform;")
paradox_add_library(PARADOX_SVG paradox-svg ${PARADOX_SVG_DIR})