#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(): type("default") 
{
    // std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type): type(type) 
{
    // std::cout << "AMateria type constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
    *this = other;
    // std::cout << "AMateria copy constructor called" << std::endl;
}

//cat1 = dog1 (even assign dog type to "cat1", "cat1" is still type:cat, not type:dog)
AMateria&   AMateria::operator=(const AMateria& ) {return *this;}

AMateria::~AMateria()
{
    // std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const {return type;}

void    AMateria::use(ICharacter& ) {}
