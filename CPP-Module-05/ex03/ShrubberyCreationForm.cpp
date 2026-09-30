#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): 
AForm("ShrubberyCreationForm", 145, 137), target("defaultShrubberyTarget") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):
AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    checkRequirement(executor);

    //Output File Stream: create file && write in
    //c_str: = c style string (required by ofstream)
    std::string fileName = target + "_shrubbery";
    std::ofstream outfile(fileName.c_str());
    if (outfile.is_open())
    {
        outfile << "       **     " << std::endl;
        outfile << "       /\\      " << std::endl;
        outfile << "      /\\/\\     " << std::endl;
        outfile << "     /*/\\*\\    " << std::endl;
        outfile << "    /*/\\/\\*\\   " << std::endl;
        outfile << "   /\\/\\/\\/\\/\\  " << std::endl;
        outfile << "       ||      " << std::endl;
        outfile.close();
    }
    else
    {
        std::cout << "Error: cannot open file " << fileName << std::endl;
        return ;
    }
}
