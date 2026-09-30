#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

#include <ctime>   //time() return: seconds since 1970.01.01
#include <cstdlib> //rand() random NO., srand() seed ramdon NO.

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

int main() {
    std::srand(std::time(0));

    Intern  intern;
    AForm*  form1;
    AForm*  form2;
    AForm*  form3;

    form1 = intern.makeForm("shrubbery creation", "zack");
    form2 = intern.makeForm("robotomy request", "zack");
    form3 = intern.makeForm("presidential pardon", "zack");

    if (form1)
    {
        Bureaucrat  boss("Boss", 1);
        boss.signForm(*form1);
        boss.executeForm(*form1);
        delete form1;
    }
    if (form2)
    {
        Bureaucrat  boss("Boss", 1);
        boss.signForm(*form2);
        boss.executeForm(*form2);
        delete form2;
    }
    if (form3)
    {
        Bureaucrat  boss("Boss", 1);
        boss.signForm(*form3);
        boss.executeForm(*form3);
        delete form3;
    }

    return 0;
}