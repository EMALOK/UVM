#include <uvm/div_types/div_header.h>

namespace uvm
{

div_header::div_header(uint8_t* _div_start) : div(_div_start), file_dependencies(div_content_ptr)
{
    printf("div_header\n");

}

void div_header::print(int depth){
    _print_open_div("div_header",depth);

    //print all file deps note: this is a div_list
    file_dependencies.print(depth + 1);

    _print_close_div("div_header",depth);
}

};