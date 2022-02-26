#include <cstddef>
#include <cstdint>

class uvm_file{
public:

    size_t buffer_size;
    uint8_t* raw_bytes;

    uint32_t uvm_version;

    uvm_file(char* _file_path);


private:

    void parse_version();
    void parse_file();

    void parse_header();
    void parse_body();
};