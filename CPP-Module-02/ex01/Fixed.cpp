#include "Fixed.hpp"

Fixed::Fixed(): _value(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i){
    std::cout << "Int constructor called" << std::endl;
    _value = i << _fractionalBits;
}

Fixed::Fixed(const float f){
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(f * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other){
    std::cout << "Copy constructor called" << std::endl; 
    *this = other;
}

Fixed&  Fixed::operator=(const Fixed& other){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_value = other._value;
    return *this;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

int    Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void    Fixed::setRawBits(int const raw){
    _value = raw;
}

float   Fixed::toFloat(void) const{
    return (float)_value / (1 << _fractionalBits);
}

int     Fixed::toInt(void) const{
    return  _value >> _fractionalBits;
}

std::ostream & operator<<(std::ostream & o, Fixed const & i){
    o << i.toFloat(); //std::cout only desplays 6 precision(round): 1234.43
    return o;
}
