/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:55:21 by yopeng            #+#    #+#             */
/*   Updated: 2026/01/30 14:14:47 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#define PINK  "\033[35m"
#define YELLOW "\033[93m"
#define RESET "\033[0m"

std::string CONTACT::_fields_name[5] =
{
    "First Name",
    "Last Name",
    "Nick Name",
    "Phone Number",
    "Darkest Secret"
};

CONTACT::CONTACT(void)
{
    for (int i = FirstName; i <= DarkestSecret; i++)
        this->_informations[i] = std::string();//从[0]-[4], 各index创建一个初始化的空字符串
    return ;  
}

CONTACT::~CONTACT(void)
{
}

bool    CONTACT::set_contact()
{
    for (int i = FirstName; i <= DarkestSecret; i++)
    {
        std::cout << PINK << "Please enter [" << CONTACT::_fields_name[i] <<"]:" << RESET << std::endl;
        while (!(std::getline(std::cin, this->_informations[i])) || \
            this->_informations[i].length() == 0)
        {
            if (std::cin.eof() == true)
            {
                std::cout << YELLOW << "You pressed ctrl+D, exiting now." << RESET << std::endl;
                std::exit(0);
            }
            else if (this->_informations[i].length() == 0)
            {
                std::cout << PINK << "Please enter [" << CONTACT::_fields_name[i] << "]:" << RESET << std::endl;
            }
        }
    }
    std::cout << YELLOW << "Contact added successfully." << RESET << std::endl;
    return (true);
}

void    CONTACT::get_contact(int i)const
{
    std::cout  << YELLOW << "|" << std::setw(5) << i;//设置宽度固定为5
    for (int j = FirstName; j <= NickName; j++)
    {
        std::cout << "|";
        if (this->_informations[j].length() > 10)
            std::cout << this->_informations[j].substr(0, 9) << ".";//从第0个字符开始复制9个字符
        else
            std::cout << std::setw(10) << this->_informations[j];
    }   
    std::cout << "|" << std::endl;
    std::cout << "|--------------------------------------|" << RESET << std::endl;
}

void    CONTACT::get_specific_contact(void)const
{
    for (int j = FirstName; j <= DarkestSecret; j++)
        std::cout << YELLOW << std::setw(15) << std::left 
                << _fields_name[j] <<": " << _informations[j] << RESET
                << std::endl;
}