#ifndef POLYMORPHISM_HPP
#define POLYMORPHISM_HPP

#include <iostream>
#include <string>

class Animal {
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string type);
        virtual ~Animal();//virtual: call Dog::~Dog() --> Animal::~Animal
        Animal& operator=(const Animal& other);
        virtual void        makeSound() const;
        virtual std::string getType() const; 
};

class Dog: public Animal {
    public:
        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog();
        void                makeSound() const;
};

class Cat: public Animal {
    public:
        Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        ~Cat();
        void                makeSound() const;
};

//-----------------------------------------------------------

class WrongAnimal {
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        virtual ~WrongAnimal();  //virtual: call WrongCat::~WrongCat() & WrongAnimal::~WrongAnimal

        void    makeSound() const;
        std::string getType() const;
};

class WrongCat: public WrongAnimal {
    public:
        WrongCat();
        ~WrongCat();

        void    makeSound() const;
};

#endif
