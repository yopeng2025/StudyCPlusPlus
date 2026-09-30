#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <cstdlib> //rand()

RobotomyRequestForm::RobotomyRequestForm():
AForm("RobotomyRequestForm", 72, 45), target("defaultRobotomyTarget") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):
AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void    RobotomyRequestForm::execute(Bureaucrat const & b) const
{
    checkRequirement(b);
    std::cout << "[Drilling Noise]: Bzzzzz!!! Bzzzz!!" << std::endl;
    if (rand() % 2 == 0)
        std::cout << "Success in robotomizing " << target << "!" << std::endl;
    else
        std::cout << "Fail to robotomize " << target << "..." << std::endl;
}
