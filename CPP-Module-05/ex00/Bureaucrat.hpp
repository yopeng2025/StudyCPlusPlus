#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
    private:
        const std::string name;
        int               grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
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
        void          increment();//grade--
        void          decrement();//grade++
};

std::ostream& operator<<(std::ostream& output, Bureaucrat const& b);

#endif



/*
const char* exception::what() const
{
    char*   exception = "null-terminated message\0";
    return (exception);
}

what()： includes error information
1st const: return read-only string
2nd const: would not change information of Exception

try {
  throw 505;
}
catch (int errorCode) {
  cout << "Error occurred: " << errorCode;
}

try: protect errors inside {} from exploding
throw: staff who find an error(fire) & stop excuting the rest of the code(pull fire alarm)
catch: specialist who deal with the error(firefighter)
*/