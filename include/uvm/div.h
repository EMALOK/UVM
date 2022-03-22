#pragma once

#include <cstddef>
#include <cstdint>

namespace uvm {

class div {
public:
    //start of the div
    uint8_t* div_start_ptr = nullptr;

    //end of the div
    uint8_t* div_end_ptr = nullptr;

    //start of the content of the div
    uint8_t* div_content_buf = nullptr;

    //the position of a possible div that follows
    uint8_t* next_div = nullptr;

    //the size of entire div
    size_t div_size = 0;

    //the size of the content insidee of the div
    size_t div_content_size = 0;

    div() noexcept;

    div(uint8_t* div_start,uint8_t* buffer);
private:
};

};