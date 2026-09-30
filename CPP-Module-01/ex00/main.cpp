#include "Zombie.hpp"

int main(void)
{
    Zombie* Rose = newZombie("Rose");
    Rose->announce();
    randomChump("Sunflower");

    delete Rose;
}
