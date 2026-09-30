#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {
    std::cout << type << " constructor called" << std::endl;
    brain = new Brain();
}

Dog::~Dog() {
    std::cout << type << " destructor called" << std::endl;
    delete  brain;//require manually delete !pointer！class *Brain, so it can call destructor
}

Dog::Dog(const Dog& other): Animal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

void    Dog::makeSound() const {
    std::cout << "Dog barks: woof woof!" << std::endl;
}

Brain*  Dog::getBrain() const {
    return brain;
}