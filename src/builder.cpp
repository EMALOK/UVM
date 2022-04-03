#include <iostream>
#include <fstream>
#include <builder/uvm_div_builder.h>
#include <helper.h>

int main(int argc,char** argv){

    if(argc != 2){
        return -1;
    }

    std::vector<uint8_t> deps1 = {
        'd','e','p','s','1','\0'
    };


    std::vector<uint8_t> deps2 = {
        'd','e','p','s','2','\0'
    };

    std::vector<uint8_t> deps3 = {
        'd','e','p','s','3','\0'
    };

    std::vector<uint8_t> body_data_buf = {
        'b','o','d','y'
    };

    std::vector<uint8_t> footer_data_buf = {
        'f','o','o','t'
    };


    
    uvm_div_builder div_deps1(deps1);
    uvm_div_builder div_deps2(deps2);
    uvm_div_builder div_deps3(deps3);

    //deps list in the header
    uvm_div_builder header_deps_list({div_deps1,div_deps2,div_deps3});


    uvm_div_builder header(header_deps_list.get_data());
    uvm_div_builder body(body_data_buf);
    uvm_div_builder footer(footer_data_buf);

    //final file
    uvm_div_builder file_div({header,body,footer});

    std::vector<uint8_t> out_file = file_div.get_data();

    std::ofstream fout;
    fout.open(argv[1], std::ios::binary | std::ios::out);

    fout.write((const char *)out_file.data(),out_file.size());

    fout.close();

}