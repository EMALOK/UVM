#include <uvm/div_types/div_file.h>

namespace uvm
{

div_file::div_file(uint8_t* _div_start) : 
div(_div_start),
header(div_content_buf), body(header.next_div), footer(body.next_div)
{

}

};