#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap    Clap("Clappy");

    Clap.attack("Enemy");
    Clap.takeDamage(5);
    Clap.beRepaired(5);

    return 0;
}