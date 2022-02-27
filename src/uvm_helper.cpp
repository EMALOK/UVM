#include <uvm_helper.h>
#include <iostream>
#include <memory>
#include <stdexcept>

//#region [rgba(255,69,0,0.1)]
//logging functions
void log_message(std::string message,uint32_t message_log_level){
    reset_console_color();
    if(message_log_level <= log_level){
        std::cout << message << std::endl;
    }
    reset_console_color();
}

void log_warning(std::string message,uint32_t message_log_level){
    set_console_color(magenta,default_color);
    if(message_log_level <= log_level){
        std::cout << message << std::endl;
    }
    reset_console_color();
}

void log_error(std::string message,uint32_t message_log_level){
    set_console_color(red,default_color);
    if(message_log_level <= log_level){
        std::cout << message << std::endl;
    }
    reset_console_color();
}

void set_console_color(ansi_color FG,ansi_color BG){
    printf("%c[%d;%dm", 0x1B, FG,BG + BG_offset);
}

void set_console_color(ansi_color FG,bool bright_FG,ansi_color BG,bool bright_BG){
    printf("%c[%d;%dm", 0x1B, FG + (bright_FG * 60),BG + (bright_BG * 60) + BG_offset);
}

void reset_console_color(){
    printf("%c[%d;%dm",0x1B,default_color,default_color + BG_offset);
}

//#endregion

//#region [rgba(0,0,200,0.1)]
//token utils

uint8_t get_start_token(uvm_token token){
    //set the msb to 0
    return token & 0b01111111;
}

uint8_t get_end_token(uvm_token token){
    //reset to 0 the msb then set it to 1
    return (token & 0b01111111) + 0b10000000; 
}

//#endregion
