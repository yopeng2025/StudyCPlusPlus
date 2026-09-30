#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;

    // std::cout << "\n----- comparison operator -----" << std::endl;
    // Fixed e(5.5f);
    // Fixed f(10.25f);
    // std::cout << "e = " << e << ", f = " << f << std::endl;
    // std::cout << "e > f : " << (e > f) << std::endl;
    // std::cout << "e < f : " << (e < f) << std::endl;
    // std::cout << "e >= f: " << (e >= f) << std::endl;
    // std::cout << "e <= f: " << (e <= f) << std::endl;
    // std::cout << "e == f: " << (e == f) << std::endl;
    // std::cout << "e != f: " << (e != f) << std::endl;

    // std::cout << "\n----- arithmetic operator -----" << std::endl;
    // std::cout << "e + f = " << (e + f) << std::endl;
    // std::cout << "e - f = " << (e - f) << std::endl;
    // std::cout << "e * f = " << (e * f) << std::endl;

    // std::cout << "\n----- increment / decrement -----" << std::endl;
    // Fixed g;
    // std::cout << "g = " << g << std::endl;
    // std::cout << "++g = " << ++g << std::endl;
    // std::cout << "g++ = " << g++ << std::endl;
    // std::cout << "g = " << g << std::endl;
    // std::cout << "--g = " << --g << std::endl;
    // std::cout << "g-- = " << g-- << std::endl;
    // std::cout << "g = " << g << std::endl;

    // std::cout << "\n----- min / max -----" << std::endl;
    // Fixed h(2.5f);
    // Fixed i(7.75f);
    // std::cout << "h = " << h << ", i = " << i << std::endl;
    // std::cout << "min(h, i) = " << Fixed::min(h, i) << std::endl;
    // std::cout << "max(h, i) = " << Fixed::max(h, i) << std::endl;

    return 0;
}
