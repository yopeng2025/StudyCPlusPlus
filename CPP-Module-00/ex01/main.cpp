/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:36:27 by yopeng            #+#    #+#             */
/*   Updated: 2026/01/30 14:15:30 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"
#define PINK  "\033[35m"
#define YELLOW "\033[93m"
#define RESET "\033[0m"

int main(void)
{
    PHONEBOOK   PhoneBook;
    bool        run = true;
    std::string command;

    PhoneBook.show_instruction();
    while (run && std::getline(std::cin, command))
    {
        if (command.compare("ADD") == 0)
            PhoneBook.set_information();
        else if (command.compare("SEARCH") == 0)
            PhoneBook.get_information();
        else if (command.compare("EXIT") == 0)
        {
            std::cout << YELLOW << "Exiting" << RESET << std::endl;
            run = false;
            continue;
        }
        else if (std::cin.eof() == true)
        {
            std::cout << YELLOW << "You pressed ctrl+D, exiting now." << RESET << std::endl;
            std::exit(0);
        }
        command.clear();
        PhoneBook.show_instruction();
    }
    if (run)
        std::cout << YELLOW << "You pressed ctrl+D, exiting now." << RESET << std::endl;
    return (0);
}