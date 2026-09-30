#include "ScalarConverter.hpp"
#include <string>
#include <iostream>

int main (int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
    else
        ScalarConverter::convert(argv[1]);
    return 0;
}


/*
static_cast → 正常转换int float ... (向上转型 (Upcasting), 将derived class指针-转化为-base class指针)
reinterpret_cast → 暴力内存重解释(int <-> pointer)
dynamic_cast → 带检查的继承转换 检测baseclass是不是某个deriveclass(安全向下转型（Downcasting）,多态继承polymorphism,即至少有一个虚函数)
*/