#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
    private:
        const std::string   name;
        bool                ifSigned;
        const int           gradeToSign;
        const int           gradeToExecute;
    public:
        Form();
        Form(const std::string name, const int grade_sign, const int grade_execute);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        std::string         getName() const;
        bool                getIfSigned() const;
        int                 getGradeToSign()const;
        int                 getGradeToExecute() const;
        void                beSigned(const Bureaucrat & bureaucrat);
};

std::ostream& operator<<(std::ostream& output, Form const& form);

#endif