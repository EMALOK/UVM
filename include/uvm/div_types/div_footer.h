#pragma once

#include <uvm/div.h>

namespace uvm
{
    
class div_footer : public div {
public:
    div_footer(uint8_t* _div_start);

    div_footer() noexcept = default;

};

} // namespace uvm