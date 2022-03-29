#include <uvm/div_types/div_string.h>

namespace uvm {
    
div_string::div_string(uint8_t* _div_start) : div(_div_start){

    content_string = std::string((char*)div_content_buf);

}

} // namespace uvm
