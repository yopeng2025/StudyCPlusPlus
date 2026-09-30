#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>// sujet: "two arguments must have the same type"
void swap(T &a, T &b) //& avoid copy constructor, pass by reference
{
    T tmp = a; //make use of the copy constructor, can work without default constructor, but T must be copyable
    a = b;
    b = tmp;
}

template <typename T>
const T &min(const T &a, const T &b)
{
    if (a > b)
        return b;
    else if (a < b)
        return a;
    else
        return b;
}

template <typename T>
const T &max(const T &a, const T &b)
{
    if (a > b)
        return a;
    else if (a < b)
        return b;
    else
        return b;
}

#endif