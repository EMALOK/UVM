#include <cstddef>
#include <cstdint>

#include <uvm_div.h>

class uvm_file{
public:

    size_t buffer_size;
    uint8_t* raw_bytes;

    std::string file_path;

    uvm_div header_div;
    uvm_div body_div;
    uvm_div footer_div;

    uvm_file(char* _file_path);


private:
};