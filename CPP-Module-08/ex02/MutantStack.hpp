// std::stack
// LIFO Last in First out
// × cannot be accessed by index[i]
// push(): add element
// top() : access the last element
// pop() : delete the last element
// size(): how many elements
// empty(): boolean, if stack is empty(1) or not(0)

//std::list
//add and remove elements from both
//× cannot be accessed by index[i]

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque> //double-ended queue: elements can be added and removed from both ends 
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        MutantStack();
        MutantStack(const MutantStack& other);
        MutantStack& operator=(const MutantStack& other);
        ~MutantStack();

        iterator begin();
        iterator end();
        const_iterator begin() const; //make sure elements not being changed e.g. *it = 100 × ; but can be moved ++/--
        const_iterator end() const;
        reverse_iterator rbegin();
        reverse_iterator rend();
        const_reverse_iterator rbegin() const;
        const_reverse_iterator rend() const;
        size_t size() const;
};

#include "MutantStack.tpp"

#endif