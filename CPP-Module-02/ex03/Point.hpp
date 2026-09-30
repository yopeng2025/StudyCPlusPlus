#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const         _x;
        Fixed const         _y;
    public:
        Point();
        Point(float x, float y);
        Point(Point const &other);
        ~Point();

        Fixed   getx() const;
        Fixed   gety() const;
};

bool            bsp(Point const A, Point const B, Point const C, Point const P);
Fixed    trangleArea(Point const &A, Point const &B, Point const &C); 

#endif
