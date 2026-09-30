#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T>
class Array
{
    private:
        T*              elements; //array
        unsigned int    n;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();

        class OutOfBounds: public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Array: index out of bounds.";
                }
        };

        unsigned int  size(void) const;
        T& operator[](unsigned int i);             //element can be modified  e.g. a[0] = 88
        const T& operator[](unsigned int i) const; //read-only element        e.g. std::cout << a[0] 
};

#include "Array.tpp"

#endif