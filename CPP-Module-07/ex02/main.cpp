#include "Array.hpp"
#include <iostream>
#include <string>
#include <exception>

int main(int, char**)
{
    Array<char> c1(26);
    char* c2 = new char[26];

    int j = 97;
    for(int i = 0; i < 26; i++)
    {
        c1[i] = j;
        // std::cout << "c 1: " << c1[i] << std::endl;
        c2[i] = j;
        // std::cout << "c 2: " << c2[i] << std::endl;
        j++;
    }
    {
        Array<char> tmp1 = c1;
        Array<char> tmp2(tmp1);
    }
    for (int i = 0; i < 26; i++)
    {
        if (c1[i] != c2[i])
        {
            std::cerr << "Error: arrays not match!" << std::endl;
            return 1;
        }
    }
    //test index out of bounds
    std::cout << "OUT OF BOUNDS INDEX TEST---------------" << std::endl;
    try
    {
        c1[30] = 65; //A
    }
    catch (std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
    }
        try
    {
        c1[-2] = 65; 
    }
    catch (std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
    }

    for (int i = 0; i < 26; i++)
    {
        c1[i] = 'a';
        // std::cout << i << ": " << c1[i] << std::endl;
    }

    //test empty
    std::cout << "EMPTY TEST---------------" << std::endl;
    Array<char> empty;
    std::cout << "Empty size: " << empty.size() << std::endl;
    try
    {
        empty[0] = 65;
    }
    catch (std::exception &e)
    {
        std::cerr << "Empty " << e.what() << std::endl;
    }

    //test self-assignment
    std::cout << "SELF TEST----------------" <<std::endl;
    Array<char> self(1);
    self[0] = 65;       //A
    self = self;
    std::cout << "Self assignment test(should be A): " << self[0] << std::endl; 

    //string test
    std::cout << "STRING TEST---------------" << std::endl;
    Array<std::string> s(2);
    s[0] = "Good";
    s[1] = "morning!";
    std::cout << s[0] << " " << s[1] << std::endl;

    delete[] c2;

    return 0;
}   