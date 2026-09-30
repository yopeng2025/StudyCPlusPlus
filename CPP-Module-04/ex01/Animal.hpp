#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Brain;

class Animal {
    protected:
        std::string         type;
    public:
        Animal();
        Animal(std::string type);
        virtual ~Animal();
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);

        virtual void        makeSound() const;
        virtual std::string getType() const; 
};

#endif