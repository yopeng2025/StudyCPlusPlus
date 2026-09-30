#include "Fixed.hpp"

Fixed::Fixed(): _value(0){}

Fixed::Fixed(const int i){
    _value = i << _fractionalBits;
}

Fixed::Fixed(const float f){
    _value = roundf(f * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other){
    *this = other;
}

Fixed&  Fixed::operator=(const Fixed& other){
    if (this != &other)
        this->_value = other._value;
    return *this;
}

Fixed::~Fixed(){
}

int    Fixed::getRawBits(void) const{
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

//comparison operators

bool    Fixed::operator>(const Fixed& other) const{
    return _value > other._value;
}

bool    Fixed::operator<(const Fixed& other) const{
    return _value < other._value;
}

bool    Fixed::operator>=(const Fixed& other) const{
    return _value >= other._value;
}

bool    Fixed::operator<=(const Fixed& other) const{
    return _value <= other._value;
}

bool    Fixed::operator==(const Fixed& other) const{
    return _value == other._value;
}

bool    Fixed::operator!=(const Fixed& other) const{
    return _value != other._value;
}

//arithmetic operators

Fixed   Fixed::operator+(const Fixed& other) const{
    Fixed   result;
    result.setRawBits(_value + other._value);
    return result;
}

Fixed   Fixed::operator-(const Fixed& other) const{
    Fixed   result;
    result.setRawBits(_value - other._value);
    return result;
}

Fixed   Fixed::operator*(const Fixed& other) const{
    Fixed   result;
    result.setRawBits((_value * other._value) >> _fractionalBits);
    return result;
}

Fixed   Fixed::operator/(const Fixed& other) const{
    Fixed   result;
    result.setRawBits((_value << _fractionalBits) / other._value);
    return result;
}

//increment / decrement

Fixed& Fixed::operator++(){
    ++_value;
    return *this;
}

Fixed& Fixed::operator--(){
    --_value;
    return *this;
}

Fixed Fixed::operator++(int){
    Fixed   tmp(*this);
    _value++;
    return tmp;
}

Fixed Fixed::operator--(int){
    Fixed   tmp(*this);
    --_value;
    return tmp;
}

//static method

Fixed& Fixed::min(Fixed& a, Fixed& b){
    if (a < b)
        return a;
    else
        return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
    if (a > b)
        return a;
    else
        return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
    if (a < b)
        return a;
    else
        return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
    if (a > b)
        return a;
    else
        return b;
}

std::ostream & operator<<(std::ostream & o, Fixed const & i){
    o << i.toFloat();
    return o;
}

