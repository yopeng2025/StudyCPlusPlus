#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <iostream>
#include <string>
#include <exception>

AForm::AForm():name("default"), ifSigned(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(const std::string &name, const int grade_sign, const int grade_execute):
name(name), ifSigned(false), gradeToSign(grade_sign), gradeToExecute(grade_execute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other):
name(other.name), ifSigned(other.ifSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other)
        ifSigned = other.ifSigned;
    return *this;
}

AForm::~AForm() {}

const char* AForm::GradeTooLowException::what() const throw() {
    return "form grade is too low!";
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "form grade is too high!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "form is not signed!";
}

std::string AForm::getName() const {return name;}

bool    AForm::getIfSigned() const {return ifSigned;}

int     AForm::getGradeToSign() const {return gradeToSign;}

int     AForm::getGradeToExecute() const {return gradeToExecute;}

void    AForm::beSigned(const Bureaucrat& Bureaucrat) {
    if (Bureaucrat.getGrade() > gradeToSign)
        throw AForm::GradeTooLowException();
    ifSigned = true;
}

std::ostream& operator<<(std::ostream& output, AForm const & form){
    output << "Form: " << form.getName()
           << " | Signed: " << (form.getIfSigned()? "Yes" : "No")
           << " | Grade to sign: " << form.getGradeToSign()
           << " | Grade to execute: " << form.getGradeToExecute();
    return output;
}

void    AForm::checkRequirement(Bureaucrat const & executor) const {
    if (!this->ifSigned)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw AForm::GradeTooLowException();
}