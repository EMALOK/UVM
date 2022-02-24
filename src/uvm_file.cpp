#include <iostream>
#include <fstream>

#include "uvm_file.h"


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

    parse_header();
}

void uvm_file::parse_header(){
    //version parse

    header.version = raw_bytes[3];
    header.version <<= 8;
    header.version += raw_bytes[2];
    header.version <<= 8;
    header.version += raw_bytes[1];
    header.version <<= 8;
    header.version += raw_bytes[0];

    std::cout << "UVM version: " << (int)header.version << std::endl;
}