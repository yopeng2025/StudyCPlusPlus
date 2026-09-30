//BSP - Binary Space Partitioning

#include "Fixed.hpp"
#include "Point.hpp"

Fixed    trangleArea(Point const &A, Point const &B, Point const &C){
    Fixed   x1 = B.getx() - A.getx();
    Fixed   x2 = C.getx() - A.getx();
    Fixed   y1 = B.gety() - A.gety();
    Fixed   y2 = C.gety() - A.gety();

    Fixed   parallelogram = x1 * y2 - x2 * y1;

    if (parallelogram < Fixed(0))
        parallelogram = parallelogram * Fixed(-1);
    return parallelogram / Fixed(2);
}

bool    bsp(Point const A, Point const B, Point const C, Point const P){
    Fixed   areaTotal = trangleArea(A, B, C);
    Fixed   area1 = trangleArea(P, B, C);
    Fixed   area2 = trangleArea(A, P, C);
    Fixed   area3 = trangleArea(A, B, P);

    if (area1 == Fixed(0) || area2 == Fixed(0) || area3 == Fixed(0))
        return false;
    else
        return (area1 + area2 + area3 == areaTotal);
}
