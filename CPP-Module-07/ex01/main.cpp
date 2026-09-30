#include "iter.hpp"
#include <iostream>
#include <cstddef> //size_t

//const parameter: read-only, is compatible with both (const) and (non-const) elements 
void print(const int &n) 
{
    std::cout << n << " ";
}

int main(void)
{
    int array1[] = {1, 2, 3, 4, 5};
    size_t length1 = sizeof(array1) / sizeof(array1[0]);
    iter(array1, length1, print);
    std::cout << std::endl;

    const int array2[] = {11, 22, 33, 44, 55};
    size_t length2 = sizeof(array2) / sizeof(array2[0]);
    iter(array2, length2, print);
    std::cout << std::endl;

    return 0;
}



// //normal parameter(can be changed): do not accept (const), which is unchangable
// void add(int &n)
// {
//     n++;
//     std::cout << n << " ";
// }