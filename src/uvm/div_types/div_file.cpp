#include <uvm/div_types/div_file.h>

namespace uvm
{

div_file::div_file(uint8_t* _div_start) : 
div(_div_start),
header(div_content_ptr), body(header.div_next_ptr), footer(body.div_next_ptr)
{
    printf("div_file\n");
}

void div_file::print(int depth){
    _print_open_div("div_file",depth);

    header.print(depth + 1);

    body.print(depth + 1);

    footer.print(depth + 1);

    _print_close_div("div_file",depth);
}

};