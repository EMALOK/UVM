#include <iostream>
#include <istream>
#include <fstream>
#include <vector>
#include <iterator>
#include <uvm_helper.h>

int main(int argc,char** argv){
    if(argc != 3){
        std::cout << "wrong args need only 2";
    }

    char* source = argv[1];
    char* uvm_obj = argv[2];

    std::ifstream source_stream(source);
    std::fstream uvm_obj_stream(uvm_obj,std::ios_base::binary);


    std::vector<std::string> source_file = std::vector<std::string>(std::istream_iterator<std::string>(source_stream),std::istream_iterator<std::string>());
    std::vector<uint8_t> output_buffer;

    for(int i = 0; i < source_file.size();i++){
        std::string line = source_file[i];

        //remove all tabs and spaces   
        //while there is a tab
        while(line.find("\t",0) != std::string::npos){
            //find the tab
            size_t tab_pos = line.find("\t",0);
            //remove the tab
            line.erase(line.begin() + tab_pos);
        }

        //while there is a space
        while(line.find(" ",0) != std::string::npos){
            //find the space
            size_t tab_pos = line.find(" ",0);
            //remove the space
            line.erase(line.begin() + tab_pos);
        }

        //is block end?
        if(line[0] == '\\'){
            //end
            //remove back slash
            line.erase(line.begin());

            if(line == "HEADER"){
                
            }

        }else{
            //start
        }


    }

}