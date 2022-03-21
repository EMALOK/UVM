#include <iostream>

#include <uvm/file.h>
#include <uvm/div.h>
#include <helper.h>

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


    // uvm_exec_call uvm_main_file_path c d e

    // uvm_main_file_path
    char* uvm_file_path = argv[1];

    // c d e
    char** uvm_argv = argv + 2;
    // 3
    int uvm_argc = argc - 2;

    //std::cout << "reading " << uvm_file_path << "\n";
    log_messagef("reading file: %s",0,uvm_file_path);

    uvm::file uvmFile(uvm_file_path);
}
//#endregion