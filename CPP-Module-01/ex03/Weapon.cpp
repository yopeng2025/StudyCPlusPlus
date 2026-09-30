#include "Weapon.hpp"

Weapon::Weapon(const std::string& type): type(type) {}

// 1st const: protect return value && 2nd:member variable _type
const std::string& Weapon::getType() const
{
    return type;
}

void Weapon::setType(std::string NewType)
{
    type = NewType;
}