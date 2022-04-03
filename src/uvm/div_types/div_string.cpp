#include <uvm/div_types/div_string.h>

namespace uvm {
    
div_string::div_string(uint8_t* _div_start) : div(_div_start){

    printf("div_string\n");

    content_string = std::string((char*)div_content_ptr);

}

void div_string::print(int depth){
    _print_open_div("div_string",depth);

    _print_indent(depth + 1);
    printf("\"%s\"\n",content_string.c_str());

    _print_close_div("div_string",depth);
}

} // namespace uvm
