#include <uvm/div.h>
#include <helper.h>

namespace uvm {

div::div(uint8_t* _div_start){
    
    div_start_ptr = _div_start;
    
    //read the div size
    div_size = from_bytes<size_t>(div_start_ptr);

    div_content_size = div_size - 3;

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