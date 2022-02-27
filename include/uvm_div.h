#include <uvm_helper.h>
#include <cstddef>
#include <cstdint>

class uvm_div {
public:
    uint8_t* div_start_ptr = nullptr;
    uint8_t* div_end_ptr = nullptr;
    size_t div_size = 0;
    size_t content_size = 0;
    uvm_token token;

    uvm_div(uint8_t* div_start,uvm_token token_identifier,uint8_t* buffer);
private:
};