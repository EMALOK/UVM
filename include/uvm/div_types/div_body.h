#pragma once

#include <uvm/div.h>

namespace uvm
{
    
class div_body : public div {
public:
    div_body(uint8_t* _div_start);

    div_body() noexcept = default;

};

} // namespace uvm