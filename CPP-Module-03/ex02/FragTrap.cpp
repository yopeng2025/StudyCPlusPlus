#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
    _hitPoints = 100; 
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap constructor called." << std::endl; 
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    _hitPoints = 100; 
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    *this = other;
    std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called." << std::endl;
}

void    FragTrap::attack(const std::string& target)
{
       if (_hitPoints == 0 || _energyPoints == 0)
    {
        std::cout << _name << " cannot atttack." << std::endl;
        return ;
    }
    _energyPoints--;
    std::cout << "FragTrap " << _name 
                << " attacks " << target 
                << ", causing " << _attackDamage 
                << " points of damage!" << std::endl;
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << _name << " says: Give me five guys!✋" << std::endl;
}
