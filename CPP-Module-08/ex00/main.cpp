#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

//vector: similar to "array"
//        dynamic size, add/delete the last element
//        ✅​ accessed by index

int main(void)
{
    int array[] = {1, 2, 3, 4, 5};        //{1, 2,... 5, NULL}

    //vector
    std::vector<int> v(array, array + 5); //(begin, end(NULL))
    try 
    {
        std::vector<int>::iterator it = easyfind(v, 5);
        std::cout << "Found VECTOR element: " << *it << std::endl;
        easyfind(v, 42);
    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }

    //list
    std::list<int> l(array, array + 5);
    try
    {
        std::list<int>::iterator it;
        it = easyfind(l, 3);
        std::cout << "Found LIST element: " << *it << std::endl;
        easyfind(l, 4422);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}