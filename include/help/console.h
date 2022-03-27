#include <stdint.h>
#include <string>
#include <climits>
#include <memory>
#include <stdexcept>

static uint32_t log_level = 1;

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

template<typename ... Args>
inline std::string string_format( const std::string& format, Args ... args )
{
    int size_s = std::snprintf( nullptr, 0, format.c_str(), args ... ) + 1; // Extra space for '\0'
    if( size_s <= 0 ){ throw std::runtime_error( "Error during formatting." ); }
    auto size = static_cast<size_t>( size_s );
    auto buf = std::make_unique<char[]>( size );
    std::snprintf( buf.get(), size, format.c_str(), args ... );
    return std::string( buf.get(), buf.get() + size - 1 ); // We don't want the '\0' inside
}

template<typename ... Args>
inline void log_messagef(std::string message,uint32_t message_log_level, Args ... args){
    log_message(string_format(message,args ...),message_log_level);
}

template<typename ... Args>
inline void log_warningf(std::string message,uint32_t message_log_level, Args ... args){
    log_warning(string_format(message,args ...),message_log_level);
}

template<typename ... Args>
inline void log_errorf(std::string message,uint32_t message_log_level, Args ... args){
    log_error(string_format(message,args ...),message_log_level);
}

void set_console_color(ansi_color FG,ansi_color BG);
void set_console_color(ansi_color FG,bool bright_FG,ansi_color BG,bool bright_BG);

void reset_console_color();