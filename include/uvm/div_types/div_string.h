#include <uvm/div.h>
#include <string>


namespace uvm {
    
class div_string : public div {
public:
    div_string(uint8_t* _div_start);

    std::string content_string;

    void print(int depth = 0);
private:
};

} // namespace uvm
