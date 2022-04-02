#pragma once

#include <uvm/div.h>
#include <uvm/div_types/div_header.h>
#include <uvm/div_types/div_body.h>
#include <uvm/div_types/div_footer.h>


namespace uvm
{
    
class div_file : public uvm::div {
public:
    div_file(uint8_t* _div_start);

    div_header header;
    div_body body;
    div_footer footer;

};

} // namespace uvm