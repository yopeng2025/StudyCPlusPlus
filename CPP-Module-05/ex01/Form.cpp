#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>
#include <string>
#include <exception>

Form::Form():name("default"), ifSigned(false), gradeToSign(150), gradeToExecute(150) {}

Form::Form(const std::string name, const int grade_sign, const int grade_execute):
name(name), ifSigned(false), gradeToSign(grade_sign), gradeToExecute(grade_execute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& other):
name(other.name), ifSigned(other.ifSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

Form& Form::operator=(const Form& other) {
    if (this != &other)
        this->ifSigned = other.ifSigned;
    return *this;
}

Form::~Form() {}

const char* Form::GradeTooLowException::what() const throw() {
    return "form grade is too low!";
}

const char* Form::GradeTooHighException::what() const throw() {
    return "form grade is too high!";
}

std::string Form::getName() const {return name;}

bool    Form::getIfSigned() const {return ifSigned;}

int     Form::getGradeToSign() const {return gradeToSign;}

int     Form::getGradeToExecute() const {return gradeToExecute;}

void    Form::beSigned(const Bureaucrat& Bureaucrat) {
    if (Bureaucrat.getGrade() > gradeToSign)
        throw Form::GradeTooLowException();
    ifSigned = true;
}

std::ostream& operator<<(std::ostream& output, Form const & form){
    output << "Form: " << form.getName()
           << " | Signed: " << (form.getIfSigned()? "Yes" : "No")
           << " | Grade to sign: " << form.getGradeToSign()
           << " | Grade to execute: " << form.getGradeToExecute();
    return output;
}

