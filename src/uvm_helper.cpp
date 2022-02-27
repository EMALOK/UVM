#include <uvm_helper.h>
#include <iostream>

//#region [rgba(0,200,0,0.1)]
// function used to convet the data from the buffer to the actual value
uint16_t convert_bytes_16(uint8_t* buf) {
    uint16_t res = 0;
    for(int i = 1;i >= 0;i--){
        res <<= 8;
        res += buf[i];
    }
    return res;
}

uint32_t convert_bytes_32(uint8_t* buf){
    uint16_t res = 0;
    for(int i = 3;i >= 0;i--){
        res <<= 8;
        res += buf[i];
    }
    return res;
}

uint64_t convert_bytes_64(uint8_t* buf){
    uint16_t res = 0;
    for(int i = 7;i >= 0;i--){
        res <<= 8;
        res += buf[i];
    }
    return res;
}

//#endregion

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