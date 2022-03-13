#pragma once

#include <uvm_helper.h>
#include <cstddef>
#include <cstdint>

class uvm_div {
public:
    uint8_t* div_start_ptr = nullptr;
    uint8_t* div_end_ptr = nullptr;
    uint8_t* div_content_buf = nullptr;
    uint8_t* next_div = nullptr;
    size_t div_size = 0;
    size_t div_content_size = 0;

    uvm_div() noexcept;

    uvm_div(uint8_t* div_start,uint8_t* buffer);
private:
};