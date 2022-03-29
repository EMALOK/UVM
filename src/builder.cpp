#include <iostream>
#include <fstream>
#include <builder/uvm_div_builder.h>
#include <helper.h>

int main(int argc,char** argv){

    if(argc != 2){
        return -1;
    }

    std::vector<uint8_t> header_data_buf = {
        'h','e','a','d'
    };

    std::vector<uint8_t> body_data_buf = {
        'b','o','d','y'
    };

    std::vector<uint8_t> footer_data_buf = {
        'f','o','o','t'
    };

    uvm_div_builder header(header_data_buf);
    uvm_div_builder body(body_data_buf);
    uvm_div_builder footer(footer_data_buf);

    std::vector<uvm_div_builder> divs;

    divs.push_back(header);
    divs.push_back(body);
    divs.push_back(footer);

    uvm_div_builder file_div(divs);

    std::vector<uint8_t> out_file = file_div.get_data();

    std::ofstream fout;
    fout.open(argv[1], std::ios::binary | std::ios::out);

    fout.write((const char *)out_file.data(),out_file.size());

    fout.close();

}