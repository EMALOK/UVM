#include <builder/uvm_div_builder.h>
#include <helper.h>
#include <iostream>

//use this contructor to create divs inside
uvm_div_builder::uvm_div_builder(std::vector<uvm_div_builder> internals_divs){
    divs = internals_divs;
    contain_divs = true;
}

//use this constructor to store data
uvm_div_builder::uvm_div_builder(std::vector<uint8_t> _data){
    data = _data;
    contain_divs = false;
}

std::vector<uint8_t> uvm_div_builder::get_data(){
    //return value
    std::vector<uint8_t> out_data;

    if(contain_divs){
        //divs

        uint32_t buffers_total_size = 0;

        std::vector< std::vector<uint8_t> > divs_buffers(divs.size());

        for(int i = 0; i < divs.size();i++){
            divs_buffers[i] = divs[i].get_data();

            // add 1 to get the actual size in bytes
            buffers_total_size += divs_buffers[i].size();

            //std::cout << "iter: " << buffers_total_size << std::endl;

        }

        std::cout << "size tot: " << buffers_total_size << std::endl;

        //convert the data_size to a buffer
        std::vector<uint8_t> buf_data_size = to_bytes(buffers_total_size);


        //insert the data_size
        out_data.insert(out_data.end(),buf_data_size.begin(),buf_data_size.end());

        //insert  all thee data from the divs
        for(int i = 0; i < divs.size();i++){
            out_data.insert(out_data.end(),divs_buffers[i].begin(),divs_buffers[i].end());
        }

    }else{
        //data

        //fetch the buffer size
        uint32_t data_size = data.size();

        std::cout << "size sin: " << data_size << std::endl;

        //convert the data_size to a buffer
        std::vector<uint8_t> buf_data_size = to_bytes(data_size);

        //insert the data_size
        out_data.insert(out_data.end(),buf_data_size.begin(),buf_data_size.end());

        //insert the data
        out_data.insert(out_data.end(),data.begin(),data.end());
    }

    return out_data;
}