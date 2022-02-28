#include <iostream>

int main(int argc,char** argv){
    if(argc != 3){
        std::cout << "wrong args need only 2";
    }

    char* source = argv[1];
    char* uvm_obj = argv[2];
}