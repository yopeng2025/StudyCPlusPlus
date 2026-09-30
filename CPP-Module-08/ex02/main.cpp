#include "MutantStack.hpp"
#include <list>

int main()
{
    std::cout << "Default Test----------" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;   //access the last element
    mstack.pop();                             //remove the last element
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "print stack elements: " << std::endl;
    while (it != ite)
    {
         std::cout << *it << std::endl;
         ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "Reverse Test--------------" << std::endl;
    MutantStack<int>::reverse_iterator it1 = mstack.rbegin();
    MutantStack<int>::reverse_iterator it2 = mstack.rend();
    ++it1;
    --it1;
    while(it1 != it2)
    {
        std::cout << *it1 << std::endl;
        ++it1;
    }

    std::cout << "A Real list-----------" << std::endl;
    std::list<int>  myList;
    myList.push_back(5);
    myList.push_back(17);
    std::cout << myList.back() << std::endl;
    myList.pop_back();
    std::cout << myList.size() << std::endl;
    myList.push_back(3);
    myList.push_back(5);
    myList.push_back(737);
    myList.push_back(0);

    std::list<int>::iterator myit1 = myList.begin();
    std::list<int>::iterator myit2 = myList.end();
    ++myit1;
    --myit1;
    std::cout << "print list elements: " << std::endl;
    while(myit1 != myit2)
    {
        std::cout << *myit1 << std::endl;
        ++myit1;
    }

    return 0;
}