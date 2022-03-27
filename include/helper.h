#pragma once

#include <help/console.h>
#include <help/binary.h>

/*
#include <stdint.h>
#include <string>
#include <climits>
#include <memory>
#include <stdexcept>

template<typename T>
T convert_bytes(uint8_t* buf){
    T res = 0;
    for(int i = sizeof(T) - 1;i >= 0;i--){
        res <<= 8;
        res += buf[i];
    }
    return res;
}
*/