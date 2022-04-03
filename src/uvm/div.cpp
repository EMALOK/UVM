#include <uvm/div.h>
#include <helper.h>

#include <iostream>

namespace uvm {

div::div(uint8_t* _div_start){    

    div_start_ptr = _div_start;
    
    //content start
    //v   v
    //SSSSxxxxxx
    div_content_ptr = div_start_ptr + 4;
    
    //read the div size
    div_content_size = from_bytes<size_t>(div_start_ptr);

    //set the div end 
    //note: the -1 is because div_content_size indicates the number of bytes
    div_end_ptr = div_content_ptr + div_content_size - 1;

    //set next div
    div_next_ptr = div_end_ptr + 1;

    //printf("\ndiv_start_ptr    = %u\n",div_start_ptr);
    //printf("div_content_size = %u\n",div_content_size);
    //printf("div_next_ptr     = %u\n\n",div_next_ptr);

}

void div::print(int depth){
    _print_open_div("div",depth);

    for(int i = 0; i < div_content_size;i++){

        if(is_printable(div_content_ptr[i])){
            _print_indent(depth + 1);
            printf("%x  (%c)\n",div_content_ptr[i],div_content_ptr[i]);
        }else{
            _print_indent(depth + 1);
            printf("%x\n",div_content_ptr[i]);
        }

    }

    _print_close_div("div",depth);
}

void div::_print_indent(int depth){
    for(int i = 0; i < depth;i++){
        printf("  ");
    }
}

void div::_print_open_div(std::string name,int depth){
    _print_indent(depth);
    printf("<%s size = %u>\n",name.c_str(),div_content_size);
}

void div::_print_close_div(std::string name,int depth){
    _print_indent(depth);
    printf("</%s>\n",name.c_str());
}

};