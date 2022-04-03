#pragma once

#include <cstddef>
#include <cstdint>

#include <string>

namespace uvm {

class div {
public:
    //start of the div
    uint8_t* div_start_ptr = nullptr;

    //end of the div
    uint8_t* div_end_ptr = nullptr;

    //start of the content of the div
    uint8_t* div_content_ptr = nullptr;

    //the position of a possible div that follows
    uint8_t* div_next_ptr = nullptr;

    //the size of the content inside of the div
    uint32_t div_content_size = 0;

    div(uint8_t* div_start);

    div() noexcept = default;

    virtual void print(int depth = 0);
protected:
    void _print_indent(int depth);
    void _print_open_div(std::string name,int depth);
    void _print_close_div(std::string name,int depth);
};

};