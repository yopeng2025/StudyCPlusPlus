#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
    private:
        const std::string   name;
        bool                ifSigned;
        const int           gradeToSign;
        const int           gradeToExecute;
    public:
        AForm();
        AForm(const std::string &name, const int grade_sign, const int grade_execute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm(); //enable derived classs calls destrctor

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
        class FormNotSignedException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        std::string     getName() const;
        bool            getIfSigned() const;
        int             getGradeToSign()const;
        int             getGradeToExecute() const;
        void            beSigned(const Bureaucrat & bureaucrat);

        virtual void    execute(Bureaucrat const & executor) const = 0;
        void            checkRequirement(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& output, AForm const& form);

#endif
