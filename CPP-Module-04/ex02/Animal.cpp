#include "Animal.hpp"
#include "Brain.hpp"

AAnimal::AAnimal(): type("Animal") {
    std::cout << type << " constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type): type(type) {
    std::cout << "Animal constructor called" << std::endl;
} 

AAnimal::~AAnimal() {
    std::cout << "Animal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) {
    *this = other;
    std::cout << "Animal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    if (this != &other)
        this->type = other.type;
    return *this;
}

void    AAnimal::makeSound() const {
//    std::cout << "Animal makes a sound!" << std::endl;
}

std::string AAnimal::getType() const {
    return  type;
}
