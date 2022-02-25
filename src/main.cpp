#include <iostream>

#include "uvm_file.h"

//#region [ rgba(0,200,0,0.1)]
/*

TODOs

*.uvm file structure
    uvm version
    entry point index (see csf list)
    cfs list class/struct/functions pointer in the body section
    body
        structs
        classes
            methods
        functions

in file pointing are relative to the father in the tree

*/
//#endregion

//#region [ rgba(0,0,200,0.1)]
int main(int argc,char** argv){

/*
    [0] uvm exec path
    [1] uvm file to exec
    [2 ...] uvm args to pass to the vm    
*/

    if(argc == 1){
        std::cout << "not enough args insert a UVM file\n";

        return -1;
    }


    // uvm b c d e

    // b
    char* uvm_file_path = argv[1];

    // c d e
    char** uvm_argv = argv + 2;
    // 3
    int uvm_argc = argc - 2;

    std::cout << "reading " << uvm_file_path << "\n"; 

    uvm_file uvmFile(uvm_file_path);
}
//#endregion