#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm():
AForm("PresidentialPardonForm", 25, 5), target("defaultPresidentialPardonTarget") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):
AForm(other), target(other.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void    PresidentialPardonForm::execute(Bureaucrat const & b) const
{
    checkRequirement(b);
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl; 
}