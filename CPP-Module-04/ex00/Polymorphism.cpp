#include "Polymorphism.hpp"

Animal::Animal(): type("Animal") {
    std::cout << type << " constructor called" << std::endl;
}

Animal::Animal(std::string type): type(type) {
    std::cout << "Animal constructor called" << std::endl;
} 

Animal& Animal::operator=(const Animal& other) {
    if (this != &other)
        this->type = other.type;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

void    Animal::makeSound() const {
    std::cout << "Animal makes a sound!" << std::endl;
}

std::string Animal::getType() const {
    return  type;
}

Dog::Dog(): Animal("Dog") {
    std::cout << type << " constructor called" << std::endl;
}

Dog::Dog(const Dog& other): Animal(other) {
    *this = other;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other)
        *this = other;
    return *this;
}

Dog::~Dog() {
    std::cout << type << " destructor called" << std::endl;
}

void    Dog::makeSound() const {
    std::cout << "Dog barks: woof woof!" << std::endl;
}

Cat::Cat(): Animal("Cat") {
    std::cout << type << " constructor called" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other) {
    *this = other;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other)
        *this = other;
    return *this;
}

Cat::~Cat() {
    std::cout << type << " destructor called" << std::endl;
}

void    Cat::makeSound() const {
    std::cout << "Cat meows: meow~" << std::endl;
}


//----------------------------------------------------------


WrongAnimal::WrongAnimal(): type("WrongAnimal") {
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): type(type) {
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << type << " makes a sound: oink!" << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}

WrongCat::WrongCat(): WrongAnimal("WrongCat") {
    std::cout << type << " constructor called" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << type << " destructor called" << std::endl;
}

void    WrongCat::makeSound() const {
    std::cout << type << "makes a sound: hisssss!" << std::endl;
}
