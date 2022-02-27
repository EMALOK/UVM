#include <cstdint>
#include <string>

//the more the log_level is higher more verbose the message wil be
//eg. ll=0 no message
//eg. ll=10 lots of messages
static uint32_t log_level = 1;

// function used to convet the data from the buffer to the actual value
uint16_t convert_bytes_16(uint8_t* buf);
uint32_t convert_bytes_32(uint8_t* buf);
uint64_t convert_bytes_64(uint8_t* buf);

enum ansi_color : uint8_t {
    black = 30,
    red = 31,
    green = 32,
    yellow = 33,
    blue = 34,
    magenta = 35,
    cyan = 36,
    white = 37,
    default_color = 39
};

const uint8_t BG_offset = 10;

void log_message(std::string message,uint32_t message_log_level);
void log_warning(std::string message,uint32_t message_log_level);
void log_error(std::string message,uint32_t message_log_level);
void set_console_color(ansi_color FG,ansi_color BG);
void set_console_color(ansi_color FG,bool bright_FG,ansi_color BG,bool bright_BG);
void reset_console_color();