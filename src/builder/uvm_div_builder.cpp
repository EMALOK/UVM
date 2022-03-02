#include <builder/uvm_div_builder.h>

//use this contructor to create divs inside
uvm_div_builder::uvm_div_builder(std::vector<uvm_div_builder> internals_divs){
    divs = internals_divs;
    contain_divs = true;
}

//use this constructor to store data
uvm_div_builder::uvm_div_builder(std::vector<uint8_t> _data){
    data = _data;
    contain_divs = false;
}

std::vector<uint8_t> uvm_div_builder::get_data(){
    if(contain_divs){
        //divs
    }else{
        //data
    }
}