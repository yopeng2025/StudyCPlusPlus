#include <iostream>
#include "Array.hpp"
#include <cstdlib> //srand()
#include <ctime> //time()

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE: defines the visibility and lifetime of a variable, 
    //ensuring its destructor is automatically called when execution leaves the {} block
    {
        Array<int> tmp = numbers;  //assignment constructor
        Array<int> test(tmp);      //copy constructor
    }
    //"}" call Array destructor
    //test if tmp and test have 2 different memory adresses(deep copy)
    //yes: free test, free tmp
    //no: double free --> segmentation fault

    //test 1. operator[]
    //     2. deep copy (free tmp might accidently free numbers)
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    //test operator[]: index out of bounds, throw exception
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    //test if operator[] is still robust
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}