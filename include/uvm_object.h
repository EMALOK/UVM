#include <string>
#include "uvm_token.h"

class uvm_object {
public:
    enum object_type : uint8_t{
        FUNCTION_OBJ_TYPE = FUNCTION ,
        STRUCT_OBJ_TYPE = STRUCT,
        CLASS_OBJ_TYPE = CLASS
    };

    std::string object_name;
    object_type object_type;

private:
};