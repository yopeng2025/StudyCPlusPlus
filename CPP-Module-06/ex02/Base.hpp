#ifndef BASE_HPP
#define BASE_HPP

class Base
{
    public:
        virtual ~Base() {};
};

#endif


/*
关于 RTTI（运行时类型识别） 的练习。

在 C++ 中，当你有一个指向基类（Base）的指针时，它可能实际上指向一个子类（A, B 或 C）。
这个练习的任务就是让你在不知道真实身份的情况下，通过代码“侦测”出它到底是谁。

dynamic_cast:安全向下转型（Downcasting）
    Pointer: success->adress fail->NULL
    Reference: success->adress fail->throw std::bad_cast
想象你有一窝小猫（A, B, C），本质都是小猫（Base）
    指针识别：你问小猫：“你是A吗？” 如果不是A，它就保持沉默（返回 NULL）。
    引用识别：你强行把小猫塞进一个A形状的猫窝里。如果塞不进去，它会发出一声尖叫（抛出异常）。
*/