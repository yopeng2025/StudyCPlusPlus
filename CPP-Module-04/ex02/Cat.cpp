#include "Cat.hpp"

Cat::Cat(): AAnimal("Cat") {
    std::cout << type << " constructor called" << std::endl;
    brain = new Brain();
}

Cat::~Cat() {
    std::cout << type << " destructor called" << std::endl;
    delete  brain;
}

Cat::Cat(const Cat& other): AAnimal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other)
    {
        AAnimal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    } 
    return *this;
}

void    Cat::makeSound() const {
    std::cout << "Cat meows: meow~" << std::endl;
}

Brain*  Cat::getBrain() const {
    return brain;
}