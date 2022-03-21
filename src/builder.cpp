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

    std::vector<uint8_t> out_header = header.get_data();
    std::vector<uint8_t> out_body = body.get_data();
    std::vector<uint8_t> out_footer = footer.get_data();

    std::ofstream fout;
    fout.open(argv[1], std::ios::binary | std::ios::out);

    fout.write((const char *)out_header.data(),out_header.size());
    fout.write((const char *)out_body.data(),out_body.size());
    fout.write((const char *)out_footer.data(),out_footer.size());

    fout.close();

}