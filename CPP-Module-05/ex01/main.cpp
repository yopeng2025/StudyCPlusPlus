#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>
#include <string>

int main() {
 
    try {
        Bureaucrat  A("Ann", 1);
        Bureaucrat  B("Bob", 2);
        Bureaucrat  C("Cam", 3);
        std::cout << A << std::endl;
        std::cout << B << std::endl;
        std::cout << C << std::endl;

        Form        F1("Form1", 1, 1);
        Form        F2("Form2", 2, 1);
        Form        F3("Form3", 3, 1);
        std::cout << F1 << std::endl;
        std::cout << F2 << std::endl;
        std::cout << F3 << std::endl;

        A.signForm(F1);
        A.signForm(F2);
        A.signForm(F3);
        B.signForm(F1);
        B.signForm(F2);
        B.signForm(F3);
        C.signForm(F1);
        C.signForm(F2);
        C.signForm(F3);
    }
    catch (std::exception & exception)
    {
        std::cerr << "Error: " << exception.what() << std::endl;
    }

    return 0;
}