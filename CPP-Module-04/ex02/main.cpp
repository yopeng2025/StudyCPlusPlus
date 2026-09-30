#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void) {
    // const AAnimal* test = new AAnimal();              //cannot instantiate abstract class

    const AAnimal* myAnimal[6];
    int     i;

    for (i = 0; i < 3; i++)
        myAnimal[i] = new Dog();
    for (i = 3; i < 6; i++)
        myAnimal[i] = new Cat(); 
    for (i = 0; i < 6; i++)                             //polymorphism
    {
        std::cout << myAnimal[i]->getType() << std::endl;
        myAnimal[i]->makeSound();
    }
    for (i = 0; i < 6; i++)
        delete myAnimal[i];

    Dog      myDog;
    Dog      copyDog(myDog);                             //deep copy
    std::cout << "myDog brain: " << myDog.getBrain() << std::endl;
    std::cout << "copyDog brain: " << copyDog.getBrain() << std::endl;
    std::cout << std::endl;
    Cat      myCat;
    Cat      copyCat(myCat);                             
    std::cout << "myCat brain: " << myCat.getBrain() << std::endl;
    std::cout << "copyCat brain: " << copyCat.getBrain() << std::endl;
    std::cout << std::endl;

    return 0;
}
