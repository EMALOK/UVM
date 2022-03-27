#pragma once

#include <uvm/div.h>

namespace uvm
{
    
class div_header : public div {
public:
    div_header(uint8_t* _div_start);

    div_header() noexcept = default;


};

} // namespace uvm
