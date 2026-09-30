#include <iostream>
#include <vector>
#include <cstdlib> //srand() rand()
#include <ctime>
#include "Span.hpp"

int main()
{
    //default
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    // span1
    Span sp1 = Span(10000);
    std::vector<int> numbers1;
    for (int i = 0; i < 10000; i++)
        numbers1.push_back(i);
    
    sp1.addNumber(numbers1.begin(), numbers1.end());
    std::cout << "Span 1------------" << std::endl;
    std::cout << "shortestSpan: " << sp1.shortestSpan() << std::endl;
    std::cout << "longestSpan: " << sp1.longestSpan() << std::endl;

    // span2
    Span sp2 = Span(100000);
    std::vector<int> numbers2;
    srand(time(0));
    for (int i = 0; i < 100000; i++)
        numbers2.push_back(rand());
    sp2.addNumber(numbers2.begin(), numbers2.end());
    std::cout << "Span 2------------" << std::endl;
    std::cout << "shortestSpan: " << sp2.shortestSpan() << std::endl;
    std::cout << "longestSpan: " << sp2.longestSpan() << std::endl;
    
    return 0;
}
