#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ClapTrap    Clap("Clpappy");
    Clap.attack("Enemy1");

    ScavTrap    Scav("Scavvy");
    Scav.attack("Enemy2");
    Scav.guardGate();

    FragTrap    Frag("Fraggy");
    Frag.attack("Enemy3");
    Frag.highFivesGuys();

    // FragTrap    FragCopy = Frag;
    // FragCopy.attack("Enemy4");
    // FragCopy.highFivesGuys();

    return 0;
}