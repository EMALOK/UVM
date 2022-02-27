#include "uvm_file.h"

#include <iostream>
#include <fstream>

#include <uvm_helper.h>

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
    uint8_t* head_start_ptr;
    uint32_t head_size;
    uint8_t* head_end_ptr;

    if(raw_bytes[4] == get_start_token(HEADER)){
        //token found in the rigth position
        head_start_ptr = raw_bytes + 4;

        head_size = convert_bytes<uint32_t>(head_start_ptr + 1);

        head_end_ptr = head_start_ptr + head_size;

        //if the value at the end of the header is equal to the end_header token
        if(*head_end_ptr == get_end_token(HEADER)){

        }else{
            //token end error
            log_error("header end token not found\n",0);
        }
    }else{
        //token start error
        log_error("header start token not found\n",0);
    }
}

void uvm_file::parse_body(){

}