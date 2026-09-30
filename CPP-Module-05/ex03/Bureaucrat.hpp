#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class Bureaucrat
{
    private:
        const std::string name;
        int               grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        class    GradeTooHighException: public std::exception
        {
            public:
                virtual const char* what() const throw(); 
        };
        class    GradeTooLowException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        std::string   getName() const;
        int           getGrade() const;
        void          increment();
        void          decrement();
        void          signForm(AForm& form);
        void          executeForm(AForm const & form) const;
};

std::ostream& operator<<(std::ostream& output, Bureaucrat const& b);

#endif
