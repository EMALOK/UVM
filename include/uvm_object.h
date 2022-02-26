#include <string>
#include "uvm_token.h"

class uvm_object {
    enum object_type : uint8_t{
        FUNCTION = 6 ,
        STRUCT = 7,
        CLASS = 8
    };

    std::string object_name;
};