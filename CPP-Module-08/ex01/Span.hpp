#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>
#include <iterator>
#include <algorithm>

class Span
{
    private:
        std::vector<int>    elements; //includes size() insert() push_back()
        unsigned int        N;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        class SlotFullException: public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Number slots are full, cannot add a number.";
                }
        };
        class NoSpanException: public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "No span can be found.";
                }
        };

        void    addNumber(int n);
        template <typename T>
        void    addNumber(T begin, T end);
        int     shortestSpan() const;
        int     longestSpan() const;
}; 

// Template implementation must be in header file
template <typename T>
void Span::addNumber(T begin, T end)
{
    //NO. already added + NO. to be added > Max_element No.
    if (elements.size() + std::distance(begin, end) > N)  //iterator distance/span {1,2,3} = 3 distance
        throw SlotFullException();
    elements.insert(elements.end(), begin, end);
}

#endif


/*
    std::vector<int> v = {1, 2, 3};
insert(iterator pos, const T& value) - 插入单个元素
    v.insert(v.begin() + 1, 99); 
    {1, 99, 2, 3}
insert(iterator pos, size_t count, const T& value) - 插入多个相同元素
    v.insert(v.end(), 3, 5);      
    {1, 99, 2, 3, 5, 5, 5}
insert(iterator pos, InputIt first, InputIt last) - 插入迭代器范围内的元素
    std::vector<int> v2 = {7, 8};
    v.insert(v.end(), v2.begin(), v2.end());  
    {1, 99, 2, 3, 5, 5, 5, 7, 8}
*/