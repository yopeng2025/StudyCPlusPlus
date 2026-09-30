#include "Animal.hpp"
#include "Brain.hpp"

Animal::Animal(): type("Animal") {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type): type(type) {
    std::cout << "Animal constructor called" << std::endl;
} 

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
    *this = other;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other)
        this->type = other.type;
    return *this;
}

void    Animal::makeSound() const {
    std::cout << "Animal makes a sound!" << std::endl;
}

std::string Animal::getType() const {
    return  type;
}
