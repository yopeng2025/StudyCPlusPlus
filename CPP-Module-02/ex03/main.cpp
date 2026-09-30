#include "Fixed.hpp"
#include "Point.hpp"

int main(void){
    Point   A(0, 0);
    Point   B(10, 0);
    Point   C(0, 10);
    Point   P(3, 3);
    Point   Q(10, 10);

    std::cout << std::boolalpha;//output "true / false" instead of 1 / 0
    std::cout << "Is P inside the triangle? " << bsp(A, B, C, P) << std::endl;
    std::cout << "Is Q inside the triangle? " << bsp(A, B, C, Q) << std::endl;

    return 0;
}