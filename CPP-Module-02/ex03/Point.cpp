#include "Point.hpp"
#include  "Fixed.hpp"

Point::Point(): _x(Fixed(0)), _y(Fixed(0)){}

Point::Point(float x, float y): _x(Fixed(x)), _y(Fixed(y)){}

Point::Point(Point const &other): _x(other._x), _y(other._y){}

Point::~Point(){}

Fixed   Point::getx() const {return _x;}

Fixed   Point::gety() const {return _y;}
