#include <uvm_div.h>

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

        }else{
            //wrong token
            log_errorf("wrong end token value:%E @ %E",0,end_token,div_end_ptr - buffer);
        }
    }else{
        //wrong token
        log_errorf("wrong start token value:%E @ %E",0,start_token,div_start_ptr - buffer);
    }
}