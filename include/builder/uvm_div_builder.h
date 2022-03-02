#include <cstddef>
#include <vector>

class uvm_div_builder;

class uvm_div_builder{
public:
    std::vector<uvm_div_builder> divs;
    std::vector<uint8_t> data;

    bool contain_divs;

    //use this contructor to create divs inside
    uvm_div_builder(std::vector<uvm_div_builder> _divs);

    //use this constructor to store data
    uvm_div_builder(std::vector<uint8_t> _data);

    std::vector<uint8_t> get_data();

}