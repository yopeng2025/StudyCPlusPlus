#include "whatever.hpp"
#include <iostream>

int main( void ) {

    int a = 2;
    int b = 3;

    //::Scope Resolution Operator
    // call template function in global scope, instead of std::namespace
    ::swap(a, b); 
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    int e = 42;
    int f = 42;

    ::swap(e, f);
    std::cout << "e =  " << e << ", f =  " << f <<std::endl;
    std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
    std::cout << "min(e, f) = " << ::max(e, f) << std::endl;

    return 0;
}