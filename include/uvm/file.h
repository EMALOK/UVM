#include <cstddef>
#include <cstdint>

#include <string>

#include <uvm/div_types/div_file.h>

namespace uvm {

class file{
public:

    size_t buffer_size;
    uint8_t* raw_bytes;

    std::string file_path;

    div_file file_div;

    file(char* _file_path);

private:
};

};