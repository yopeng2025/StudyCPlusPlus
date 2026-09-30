#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class   HumanA
{
    private:
        std::string name;
        Weapon&     weapon;//use reference: because weapon will be initialize in constructor， can't be NULL
    public:
        HumanA(const std::string& n, Weapon& w);

        void    attack();
};

#endif
