//STL: Standard Template Library
//     1. Container: data structures (vector, list, stack ...)
//     2. Iterators: objects used to access elements of a data structure
//     3. Algorithms: functions (sort(), find() ...)

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class NotFound: public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Element not found in container.";
        }
};

template <typename T>
typename T::iterator easyfind(T &container, int n);

#include "easyfind.tpp"

#endif