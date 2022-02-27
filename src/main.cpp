#include <iostream>

#include <uvm_file.h>
#include <uvm_helper.h>

//#region [ rgba(0,0,200,0.1)]
int main(int argc,char** argv){

/*
    [0] uvm exec path
    [1] uvm file to exec
    [2 ...] uvm args to pass to the vm    
*/

    if(argc == 1){
        //std::cout << "not enough args insert a UVM file\n";
        log_error("not enough args insert a UVM file\n",0);
        return -1;
    }


    // uvm b c d e

    // b
    char* uvm_file_path = argv[1];

    // c d e
    char** uvm_argv = argv + 2;
    // 3
    int uvm_argc = argc - 2;

    //std::cout << "reading " << uvm_file_path << "\n";
    log_messagef("reading file: %s",0,uvm_file_path);


    uvm_file uvmFile(uvm_file_path);
}
//#endregion