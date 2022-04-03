#include <uvm/file.h>

#include <iostream>
#include <fstream>

#include <helper.h>
#include <uvm/div_types/div_file.h>

namespace uvm {

file::file(char* _file_path){

    file_path = _file_path;

    //log_messagef("reading file: %s\n",0,file_path);

    //open file
    std::ifstream infile(_file_path);

    //log_messagef("seeking eof\n",0);

    //get length of file
    infile.seekg(0, std::ios::end);
    buffer_size = infile.tellg();
    infile.seekg(0, std::ios::beg);

    //log_messagef("malloc\n",0);

    //allocate the buffer
    raw_bytes = (uint8_t*)malloc(buffer_size);

    //log_messagef("file copy\n",0);

    //read file
    infile.read((char*)raw_bytes, buffer_size);

    //log_messagef("file close\n",0);


    infile.close();

    //log_messagef("div_file\n",0);


    file_div_ptr = new div_file(raw_bytes);
}

file::~file(){
    free(raw_bytes);
}


};