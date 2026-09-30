#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

Base* generate(void)
{
    int i;

    i = std::rand() % 3;
    switch (i)
    {
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
        default:
            break;
    }
    return NULL;
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p)) //dynamic_cast 的返回值被用作了 if 语句的判断条件。因为结果被“使用”了，编译器就不会报警告。
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void    identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);//执行了一个有返回值的操作，却没把结果存在变量里，也没传给函数。编译器会担心你是“不小心写错了”或者“忘记处理结果了”， 因此要（void）
        std::cout << "A" << std::endl;
        return ;
    }
    catch (std::exception &e) {}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch (std::exception &e) {}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch (std::exception &e) {}
}

int main(void)
{
    std::srand(std::time(NULL));

    Base*   base;
    base = generate();

    std::cout << "Pointer: ";
    identify(base);
    std::cout << "Reference: ";
    identify(*base);

    delete base;
    return 0;
}