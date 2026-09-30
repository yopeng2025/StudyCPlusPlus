#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {(void)other;}

Intern& Intern::operator=(const Intern& other) {(void)other; return *this;}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string formName, const std::string formTarget) {
    std::string name[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == name[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            switch (i)
            {
                case 0:
                    return new ShrubberyCreationForm(formTarget);
                case 1:
                    return new RobotomyRequestForm(formTarget);
                case 2:
                    return new PresidentialPardonForm(formTarget);
            }
        }
    }
    std::cout << "Intern fails to create " << formName << "(file not found)" << std::endl;
    return NULL;
}