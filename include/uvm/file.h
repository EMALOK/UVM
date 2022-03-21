#include <cstddef>
#include <cstdint>

#include <string>

#include <uvm/div.h>

namespace uvm {

class file{
public:

    size_t buffer_size;
    uint8_t* raw_bytes;

    std::string file_path;

    div header;
    div body;
    div footer;

    file(char* _file_path);


private:
};

};