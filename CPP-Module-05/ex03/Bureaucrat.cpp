#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <iostream>
#include <string>
#include <exception>

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string &name, int grade): name(name), grade(grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other)
        grade = other.grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {return name;}

int Bureaucrat::getGrade() const {return grade;}

void    Bureaucrat::increment() {
    if (grade == 1)
        throw Bureaucrat::GradeTooHighException();
    else
        grade--;
}

void    Bureaucrat::decrement() {
    if (grade == 150)
        throw Bureaucrat::GradeTooLowException();
    else
        grade++;
}

void    Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (std::exception & e){
        std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const & form) const
{
    try {
        form.execute(*this);
        std::cout << getName() << " executed " << form.getName() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

std::ostream& operator<<(std::ostream& output, Bureaucrat const& b) {
    output << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return output;
}