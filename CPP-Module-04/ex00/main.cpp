//BaseClass: virtual, DerivedClass: override

#include "Polymorphism.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete i;
    delete j;
    delete meta;

//test-----------------------------------------

    const WrongAnimal* k = new WrongCat();
    std::cout << k->getType() << std::endl;
    k->makeSound();

    delete k;

    return 0;
}