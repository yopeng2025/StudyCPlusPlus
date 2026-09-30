#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
    {
        Weapon  axe = Weapon("hammer");
        HumanA  Adam("Adam", axe);

        Adam.attack();
        axe.setType("iron axe");
        Adam.attack();

    }
    {
        Weapon  sword = Weapon("sword");
        HumanB  Sam("Sam");
        Sam.attack();
        Sam.setWeapon(sword);
        Sam.attack();
        sword.setType("silver sword");
        Sam.attack();
    }
    return 0;
}