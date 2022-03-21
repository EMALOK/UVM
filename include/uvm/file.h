#include <cstddef>
#include <cstdint>

#include <string>

class file{
public:

    size_t buffer_size;
    uint8_t* raw_bytes;

    std::string file_path;

    file(char* _file_path);


private:
};