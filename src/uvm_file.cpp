#include "uvm_file.h"

#include <iostream>
#include <fstream>

#include <uvm_helper.h>
#include <uvm_div.h>

uvm_file::uvm_file(char* _file_path){
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

    parse_file();
}

void uvm_file::parse_version(){
    //version parse

    uvm_version = convert_bytes<uint32_t>(raw_bytes);

    std::cout << "UVM version: " << uvm_version << std::endl;
}

void uvm_file::parse_file(){

    //switch based on the file version
    std::cout << "starting parsing file" << std::endl;

    parse_header();

    parse_body();
}

void uvm_file::parse_header(){
    uvm_div header_div(raw_bytes + 4,HEADER,raw_bytes);
}

void uvm_file::parse_body(){

}