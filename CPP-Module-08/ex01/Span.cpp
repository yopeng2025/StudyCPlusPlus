#include "Span.hpp"
#include <exception>
#include <algorithm> //sort() push_back()
#include <iterator>  //distance()

Span::Span(): N(0) {}

Span::Span(unsigned int N): N(N) {}

Span::Span(const Span& other)
{
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        N = other.N;
        elements = other.elements;  // vector's assignment operator handles deep copy
    }
    return *this;
}

Span::~Span() {}


void Span::addNumber(int n)
{   
    if (elements.size() < N)
    {
        elements.push_back(n);
    }
    else
        throw SlotFullException();
}

int Span::shortestSpan() const
{
    if (elements.size() <= 1)
        throw NoSpanException();
    std::vector<int> sorted_elements = elements;
    std::sort(sorted_elements.begin(), sorted_elements.end());
    int min = sorted_elements[1] - sorted_elements[0];
    for(unsigned int i = 1; i < sorted_elements.size() - 1; i++)
    {
        if ((sorted_elements[i + 1] - sorted_elements[i]) < min)
            min = sorted_elements[i + 1] - sorted_elements[i];
    }
    return min;
}

int Span::longestSpan() const
{
    if (elements.size() <= 1)
        throw NoSpanException();
    std::vector<int> sorted_elements = elements;
    std::sort(sorted_elements.begin(), sorted_elements.end());
    return sorted_elements[elements.size() - 1] - sorted_elements[0];
}