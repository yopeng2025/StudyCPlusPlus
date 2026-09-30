#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string const & name): name(name), floorCount(0)
{
    // std::cout << "Character constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(const Character& other): name(other.name), floorCount(0)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            delete inventory[i];
            inventory[i] = NULL;
        }
        for (int i = 0; i < floorCount; i++)
        {
            delete floor[i];
            floor[i] = NULL;
        }
        floorCount = 0;
        for (int i = 0; i < 4; i++)
        {
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character()
{
    // std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        if (inventory[i])
            delete inventory[i];
    for (int i = 0; i < floorCount; i++)
        if (floor[i])
            delete floor[i];
}

std::string const & Character::getName() const {return name;}

void    Character::equip(AMateria* m)
{
    if (!m)
        return ;
    for (int i = 0; i < 4; i++)
        if (inventory[i] == m)
            return ;                         //avoid double free
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            // std::cout << "[debug]: " << inventory[i]->getType() << std::endl;
            return ;
        }
    }
    delete m;
    std::cout << "Inventory full, Materia deleted to prevent leak." << std::endl;
}

//unequip() must NOT delete the Materia
void    Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || inventory[idx] == NULL)
        return ;
    if (floorCount < 1000)
        floor[floorCount++] = inventory[idx]; //floor takes owership
    else                                      //in case floor is full
    {
        delete inventory[idx];
        std::cout << "Floor is full, Materia destroyed!" << std::endl;
    }
    inventory[idx] = NULL;                //inventory losts owership
}

void    Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4 || inventory[idx] == NULL)
        return ;
    inventory[idx]->use(target);
}