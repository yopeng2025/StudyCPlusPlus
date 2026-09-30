#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Brain;

//A： Abstract class
class AAnimal {
    protected:
        std::string         type;
    public:
        AAnimal();
        AAnimal(std::string type);
        virtual ~AAnimal();
        AAnimal(const AAnimal& other);
        AAnimal& operator=(const AAnimal& other);
        //pure virtual function: instantiable for animal sound
        virtual void        makeSound() const = 0; 
        virtual std::string getType() const; 
};

#endif