#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include "Data.hpp"
#include <string>
#include <stdint.h> //uintptr_t (C++98)

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);
        ~Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif

/*
uintptr_t: 8bytes(x64) 4bytes(x32) unsigned integer pointer type 用于存放指针地址，兼容32位64位

reinterpret_cast: C++暴力的转换
指针 -> 整数：reinterpret_cast<uintptr_t>(ptr)   
整数 -> 指针：reinterpret_cast<Data*>(raw)
*/