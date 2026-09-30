#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef> //size_t

//normal array: allow read & write
template <typename T, typename F>
void iter(T *array, const size_t length, F func)
{
    if (!array || !func)
        return ;
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}

//const array: read-only
//passing (int*) to (const int*) is legal, but the other way is NOT! 
template <typename T, typename F>
void iter(const T *array, const size_t length, F func)
{
    if (!array || !func)
        return ;
    for (size_t i = 0; i < length; i++)
        func(array[i]);                //=func(const array[i]), passing read-only parameter
}

#endif

//"Think carefully about how to support both const and non-const elements in your iter function."
//answer: Function Overloading函数重载, 2 versions of iter()