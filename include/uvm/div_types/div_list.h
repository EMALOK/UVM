#include <type_traits>
#include <vector>

#include <uvm/div.h>

namespace uvm {

template<class div_type>
class div_list : public div {
public:
    div_list(uint8_t* _div_start) : div(_div_start){

        //compile time assert
        //static_assert(std::is_base_of(div,div_type)::value,"div_type is not derived out of div\n");

        //empty list
        if(div_content_size == 0)
            return;

        while(1){
            div_type div_c(div_content_buf);

            contents.push_back(div_c);

            //exit condition
            if(div_c.div_end_ptr >= div_end_ptr)
                break;

        }

    }

    std::vector<div_type> contents;
private:

};

}