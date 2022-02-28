#include <uvm_div.h>

uvm_div::uvm_div() noexcept {

}

uvm_div::uvm_div(uint8_t* div_start,uvm_token token_identifier,uint8_t* buffer){

    div_start_ptr = div_start;

    //get the correct tokens
    uint8_t start_token = get_start_token(token_identifier);
    uint8_t end_token = get_end_token(token_identifier);

    token = (uvm_token)start_token;

    //start token identifier check
    if(*div_start_ptr == start_token){
        //get the div size
        div_size = convert_bytes<uint32_t>(div_start_ptr + 1);

        //calcolate teoretical end div position
        div_end_ptr = div_start_ptr + div_size;

        //end token identifier check
        if(*div_end_ptr == end_token){
            //correct start and end token

            div_content_buf = div_start_ptr + sizeof(uint32_t);

            //remove 4 bytes for the size and one to remove the end token from the buffer
            div_content_size = div_size - 5;

            next_div =  div_end_ptr + 1;

        }else{
            //wrong token
            log_errorf("wrong end token value expected: %x got %x @ %i\n",0,end_token,*div_end_ptr,div_end_ptr - buffer);
        }
    }else{
        //wrong token
    log_errorf("wrong start token value expected: %x got %x @ %i\n",0,start_token,*div_start_ptr,div_start_ptr - buffer);
    }
}

void uvm_div::log(){
    log_messagef("start token ptr: %x\nend token ptr: %x\ndiv content ptr: %x\ndiv size: %i\ndiv content size: %i\n",0,div_start_ptr,div_end_ptr,div_content_buf,div_size,div_content_size);
}