/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:55:28 by yopeng            #+#    #+#             */
/*   Updated: 2026/01/30 14:01:54 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#define PINK  "\033[35m"
#define YELLOW "\033[93m"
#define RESET "\033[0m"

PHONEBOOK::PHONEBOOK(void)
{
    this->_index = 0;
    this->_full = false;
    return ;
}

PHONEBOOK::~PHONEBOOK(void)
{
    return ;
}

void    PHONEBOOK::show_instruction(void)
{
    std::cout << PINK << "Enter command [ADD, SEARCH, EXIT]:" << RESET << std::endl;
}

void    PHONEBOOK::set_information(void)
{
   std::string  input;

   if (this->_full == false)
   {
        std::cout << PINK << "Contact NO." << this->_index + 1 << RESET << std::endl;
        if (this->_contacts[this->_index].set_contact() == true)
        {
            if (this->_index == 7)
                this->_full = true;
            else
                this->_index++;
        }
   }
   else
   {
        while (true)
        {
            std::cout << YELLOW 
                    << "Phonebook is full.\nAdding a new contact will replace the oldest one." 
                    << RESET 
                    << std::endl;
            std::cout << PINK 
                    << "Enter [1] to add new contact.\nEnter [0] to go back to main menu." 
                    << RESET 
                    << std::endl;
            getline(std::cin, input);
            if (std::cin.eof() == true)
            {
                std::cout << PINK << "You pressed ctrl+D, exiting now." << RESET << std::endl;
                std::exit(0);
            }
            else if (input == "0")
            {
                std::cout << PINK <<"Back to main menu without deleting and creating a contact." << RESET << std:: endl;
                break ;
            }
            else if (input == "1")
            {
                this->_index++;
                if (this->_index == 8)
                    this->_index = 0;
                std::cout << PINK
                        << "Contact NO."
                        << this->_index + 1
                        << RESET
                        <<std::endl;
                this->_contacts[this->_index].set_contact();
                break ;
            }
        }
    }
}

void    PHONEBOOK::get_information(void)const
{   
    int input_number;
    int j;
    
    if (this->_index == 0 && this->_full == false)
    {
        std::cout << YELLOW << "Please add contact before searching." << RESET << std::endl;
        return ;
    }
    //打印简单电话簿
    std::cout << YELLOW << "|--------------------------------------|" << std::endl;
	std::cout << "|Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|-----|----------|----------|----------|" << std::endl;
    if (this->_full == true)
        j = 8;
    else
        j = this->_index;
    for (int i = 0; i < j; i++)
	    this->_contacts[i].get_contact(i + 1);
 
    while (true)
    {
        //要求输入查询联系人NO.
        std::string input;
        std::cout << PINK << "Enter contact NO. that you are searching for.\nOr enter [0] to go back to main menu." << RESET << std::endl;
        while (true)
        {
            if (!std::getline(std::cin, input))
            {
                std::cout << PINK << "You pressed Ctrl+D, exiting now." << RESET << std::endl;
                std::exit(0);
            }
            if (input == "0")
                return ;
            input_number = std::atoi(input.c_str());
            if (input_number > j )
                std::cout << YELLOW << "You only have [" << j << "] contacts" << RESET << std::endl;
            if (input_number >= 1 && input_number <= j)
            {
                this->_contacts[input_number - 1].get_specific_contact();
                break ;
            }
            std::cout << PINK << "Enter a number from 1 to 8." << std::endl;
            std::cout << "Enter [0] to go back to main menu." << RESET << std::endl;
        }
    }
}
