// range 0 - 127
enum uvm_token : uint8_t {
    NULL_TOKEN = 0,
    HEADER = 1,
    BODY = 2,
    LIST = 3,
    STRING = 4,
    VAR = 5,
    FUNCTION = 6,
    STRUCT = 7,
    CLASS = 8,
    PRIVATE = 9,
    PUBLIC = 10
};