#include <uvm/file.h>

#include <iostream>
#include <fstream>

#include <helper.h>
#include <uvm/div_types/div_file.h>

namespace uvm {

file::file(char* _file_path) : file_div(raw_bytes){

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

    infile.close();
    //parse file
    log_messagef("starting parsing file: %s",0,file_path.c_str());
};

};