#pragma once

#include <uvm/div.h>

#include <uvm/div_types/div_list.h>
#include <uvm/div_types/div_string.h>

namespace uvm
{
    
class div_header : public div {
public:
    div_header(uint8_t* _div_start);

    div_header() noexcept = default;

    div_list<div_string> file_dependencies;

    void print(int depth = 0);
};

} // namespace uvm
