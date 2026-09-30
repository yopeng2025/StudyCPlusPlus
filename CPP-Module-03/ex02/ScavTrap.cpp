#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
    _hitPoints = 100; 
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap constructor called." << std::endl; 
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    _hitPoints = 100; 
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    *this = other;
    std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called." << std::endl;
}

void    ScavTrap::attack(const std::string& enemy)
{
       if (_hitPoints == 0 || _energyPoints == 0)
    {
        std::cout << _name << " cannot atttack." << std::endl;
        return ;
    }
    _energyPoints--;
    std::cout << "ScavTrap " << _name 
                << " attacks " << enemy 
                << ", causing " << _attackDamage 
                << " points of damage!" << std::endl;
}

void    ScavTrap::guardGate()
{
    std::cout << _name << " is now in Gate keeper mode." << std::endl;
}
