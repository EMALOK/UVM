#include <uvm/div.h>
#include <helper.h>

namespace uvm {

div::div(uint8_t* _div_start){
    
    div_start_ptr = _div_start;
    
    //read the div size
    div_size = convert_bytes<size_t>(_div_start);

    //set the div end
    div_end_ptr = div_start_ptr + div_size;

    //set next div
    next_div = div_end_ptr + 1;

    //content start
    //v   v
    //SSSSxxxxxx
    div_content_buf = div_start_ptr + 4;
}

};