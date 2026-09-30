#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

int main() {
    //grade 1-150 
    try {
        Bureaucrat  A("Ann", 2);
        std::cout << A << std::endl;
        A.increment();
        std::cout << "After increment: " << A << std::endl;
    }
    catch (std::exception & exception)
    {
        std::cerr << "Error: " << exception.what() << std::endl;
    }
    //grade too high
    try {
        Bureaucrat B("Bob", 1);
        std::cout << B << std::endl;
        B.increment();
    }
    catch (std::exception & exception) {
        std::cerr << "Error: " << exception.what() << std::endl;
    }
    //grade too low
    try {
        Bureaucrat C("Cam", 150);
        std::cout << C << std::endl;
        C.decrement();
        std::cout << "After decrement: " << C << std::endl;
    }
    catch (std::exception & exception)
    {
        std::cerr << "Error: " << exception.what() << std::endl;
    }

    return 0;
}