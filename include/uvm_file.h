class uvm_file{
public:
    struct Header{
        uint32_t version;
    };

    size_t buffer_size;
    uint8_t* raw_bytes;

    Header header;

    uvm_file(char* _file_path);


private:

    void parse_header();
};