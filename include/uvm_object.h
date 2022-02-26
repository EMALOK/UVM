#include <string>

class uvm_object {
    enum object_type{
        FUNCTION = 6,
        STRUCT = 7,
        CLASS = 8
    };

    std::string object_name;
};