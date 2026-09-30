#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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

    DiamondTrap Diamond("Dia");
    Diamond.attack("Enemy4");
    Diamond.whoAmI();

    Diamond.getpoints();

    return 0;
}