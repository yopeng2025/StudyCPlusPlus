#include <iostream>
#include <string>
#include <iomanip>

int main(void)
{
    std::string     s = "HI THIS IS BRAIN";
    std::string*    stringPTR = &s;//point to memory address of "s", changing it would not change "s"
    std::string&    stringREF = s;//same memory address, changing it can also change content of "s"

    std::cout <<std::setw(30) << std::left 
            << "memory address of s: " << &s << std::endl;
    std::cout <<std::setw(30) << std::left 
            << "memory address of stringPTR: " << stringPTR << std::endl;
    std::cout <<std::setw(30) << std::left 
            << "memory address of stringREF: " << &stringREF << std::endl;

    std::cout <<std::setw(30) << std::left 
            << "value of s: " << s << std::endl;
    std::cout <<std::setw(30) << std::left 
            << "value of stringPTR: " << *stringPTR << std::endl;
    std::cout <<std::setw(30) << std::left 
            << "value of stringPTR: " << stringREF << std::endl;
}