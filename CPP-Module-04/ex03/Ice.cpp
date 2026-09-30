#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice(): AMateria("ice")
{
    // std::cout << "Ice consturctor called" << std::endl;
}

Ice::~Ice()
{
    // std::cout << "Ice desturctor called" << std::endl;
}

Ice::Ice(const Ice& other): AMateria(other)
{
    // std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
    if (this != &other)
        AMateria::operator=(other);
    return *this;
}

AMateria*   Ice::clone() const
{
    Ice*     i = new Ice(*this);
    return i;
}

void    Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}