#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class   HumanB
{
    private:
        std::string name;
        Weapon*     weapon;//use pointer: because there might be no weapon， can be null
    public:
        HumanB(const std::string& n);
        
        void    setWeapon(Weapon& w);
        void    attack();
};

#endif