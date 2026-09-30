#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap    Clap("Clappy");
    Clap.attack("Enemy1");

    ScavTrap    Scav("Scavvy");
    Scav.attack("Enemy2");
    Scav.guardGate();

    // ScavTrap    ScavCopy = Scav;
    // ScavCopy.attack("Enemy3");

    return 0;
}