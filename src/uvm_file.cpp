#include "uvm_file.h"

#include <iostream>
#include <fstream>

#include <uvm_helper.h>
#include <uvm_div.h>

uvm_file::uvm_file(char* _file_path){

    file_path = _file_path;

    //open file
    std::ifstream infile(_file_path);

    //get length of file
    infile.seekg(0, std::ios::end);
    buffer_size = infile.tellg();
    infile.seekg(0, std::ios::beg);

    //allocate the buffer
    raw_bytes = (uint8_t*)malloc(buffer_size);

    //read file
    infile.read((char*)raw_bytes, buffer_size);

    parse_version();

    //parse file
    log_messagef("starting parsing file: %s",0,file_path.c_str());

    log_message("divving header\n",0);

    header_div = uvm_div(raw_bytes + 4,HEADER,raw_bytes);

    log_message("divving body\n",0);

    body_div = uvm_div(header_div.div_end_ptr + 1,BODY,raw_bytes);

    log_message("divving footer\n",0);

    footer_div = uvm_div(body_div.div_end_ptr + 1,FOOTER,raw_bytes);
}

void uvm_file::parse_version(){
    //version parse

    uvm_version = convert_bytes<uint32_t>(raw_bytes);

    // std::cout << "UVM version: " << uvm_version << std::endl;
    log_messagef("UVM version: %i",0,uvm_version);
}