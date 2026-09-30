#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <ctime>   //time() return: seconds since 1970.01.01
#include <cstdlib> //rand() random NO., srand() seed ramdon NO.

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

int main() {
    std::srand(std::time(0));

    Bureaucrat  boss("President", 1);
    Bureaucrat  middle("Manager", 45);
    Bureaucrat  intern("Intern", 150);

    ShrubberyCreationForm   Form_shrub("Shrub");
    RobotomyRequestForm     Form_robot("Robotomy");
    PresidentialPardonForm  Form_pardon("Zack");

    // unsigned & execute
    std::cout << YELLOW << "[attemping to execute unsigned form...]" << RESET << std::endl;
    boss.executeForm(Form_shrub);

    // boss
    std::cout << GREEN << "[attemping to sign form...]" << RESET << std::endl;
    boss.signForm(Form_shrub);
    std::cout << GREEN << "[attemping to execute signed form...]" << RESET << std::endl;
    boss.executeForm(Form_shrub);

    std::cout << GREEN << "[attemping to sign form...]" << RESET << std::endl;
    boss.signForm(Form_robot);
    std::cout << GREEN << "[attemping to execute signed form...]" << RESET << std::endl;
    boss.executeForm(Form_robot);

    std::cout << GREEN << "[attemping to sign form...]" << RESET << std::endl;
    boss.signForm(Form_pardon);
    std::cout << GREEN << "[attemping to execute signed form...]" << RESET << std::endl;
    boss.executeForm(Form_pardon);

    //middle
    std::cout << GREEN << "[attemping to sign form...]" << RESET << std::endl;
    middle.signForm(Form_shrub);
    std::cout << GREEN << "[attemping to execute signed form...]" << RESET << std::endl;
    middle.executeForm(Form_shrub);

    std::cout << GREEN << "[attemping to sign form...]" << RESET << std::endl;
    middle.signForm(Form_robot);
    std::cout << GREEN << "[attemping to execute signed form...]" << RESET << std::endl;
    middle.executeForm(Form_robot);

    std::cout << GREEN << "[attemping to sign form...]" << RESET << std::endl;
    middle.signForm(Form_pardon);
    std::cout << GREEN << "[attemping to execute signed form...]" << RESET << std::endl;
    middle.executeForm(Form_pardon);

    //intern
    std::cout << GREEN << "[attemping to sign form...]" << RESET << std::endl;
    intern.signForm(Form_shrub);
    std::cout << GREEN << "[attemping to execute signed form...]" << RESET << std::endl;
    intern.executeForm(Form_shrub);

    std::cout << GREEN << "[attemping to sign form...]" << RESET << std::endl;
    intern.signForm(Form_robot);
    std::cout << GREEN << "[attemping to execute signed form...]" << RESET << std::endl;
    intern.executeForm(Form_robot);

    std::cout << GREEN << "[attemping to sign form...]" << RESET << std::endl;
    intern.signForm(Form_pardon);
    std::cout << GREEN << "[attemping to execute signed form...]" << RESET << std::endl;
    intern.executeForm(Form_pardon);

    

    return 0;
}