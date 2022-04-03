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

        div_type* div_c = new div_type(div_content_ptr);

        while(1){

            contents.push_back(div_c);

            printf("div_c->div_next_ptr\t = %u\n",div_c->div_next_ptr);
            printf("div_end_ptr\t\t = %u\n",div_end_ptr);

            //exit condition
            if(div_c->div_next_ptr > div_end_ptr)
                break;

            uint8_t* div_next_ptr_copy = div_c->div_next_ptr;

            div_c = new div_type(div_next_ptr_copy);

        }
        

    }

    std::vector<div_type*> contents;

    void print(int depth = 0){
        _print_open_div("div_list",depth);

        for(int i = 0;i < contents.size();i++){
            contents[i]->print(depth + 1);
        }

        _print_close_div("div_list",depth);
    }

    ~div_list(){

        for(int i = 0; i < contents.size(); i++){
            delete contents[i];
        }

    }

private:

};

}