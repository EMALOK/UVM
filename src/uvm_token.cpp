#include <cstdint>

#include <uvm_token.h>

uint8_t get_start_token(uvm_token token){
    //set the msb to 0
    return token & 0b01111111;
}

uint8_t get_end_token(uvm_token token){
    //reset to 0 the msb then set it to 1
    return (token & 0b01111111) + 0b10000000; 
}