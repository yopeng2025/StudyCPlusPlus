//nan: not a number (double)
//nanf: not a number (float)
//inf: infinity number (double) 无穷大
//-inf: inifinity minus
//inff: infinity (float)
//-inff

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <limits>  //nan inf
#include <iomanip> //set precision

#include <cstdlib> //strtod(string to double) atof(ascii to float) return: double (for better precision) 
#include <cmath>
#include <climits> //INT_MAX INT_MIN
#include <cctype>  //std::isprint

bool ScalarConverter::ifPseudo(const std::string& literal)
{
    return (literal == "nan" || literal == "nanf" || \
            literal == "inf" || literal == "inff" || \
            literal == "+inf" || literal == "+inff" || \
            literal == "-inf" || literal == "-inff");
} 

void ScalarConverter::printSpecial(const std::string& literal)
{
    std::string s = literal;
    if (s == "nanf") s = "nan";
    else if (s == "inff") s = "inf";
    else if (s == "-inff") s = "-inf";

    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << s << "f" << std::endl;
    std::cout << "double: " << s << std::endl;
}

void    ScalarConverter::convert(const std::string& literal)
{
    if (ifPseudo(literal))
    {
        printSpecial(literal);
        return ;
    }

    double doubleNumber;
    char   *end;
    //char "a"
    if (literal.length() == 1 && !std::isdigit(literal[0])) //only 1 char && not digital no.
        doubleNumber = static_cast<double>(literal[0]); //turn char into ASCII
    //turn literal into double 42->42.0 (char:* int:42 float: 42.0f double:42.0)
    else
    {
        doubleNumber = std::strtod(literal.c_str(), &end); //return double no.(10 digits)
        // std::cout << "[debug]: " << doubleNumber << std::endl;//std::cout diplays only 6 digits
        //输入42abc *end指向a
        if(*end != '\0')
        {
            if (!(*end == 'f' && *(end + 1) == '\0')) //42a 42aa 42ff ... 所有非42f
            {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: nanf" << std::endl;
                std::cout << "double: nan" << std::endl;
                return ;
            }
        }
    }

    //处理完极端情况(单词)，单个字符，处理“数字”并打印 (42, 42.0, 42.0f, 4.2 ...)
    //char
    std::cout << "char: ";
    //情况1： ASCII以外
    if (doubleNumber < 0 || doubleNumber > 127)
        std::cout << "impossible" << std::endl;
    //情况2：ASCII以内，非可打印字符0-31(tab， space...),127(del)
    else if (!std::isprint(static_cast<char>(doubleNumber))) //9(Tab)->false 32(sapce)->true 127(del)->false; static_cast<char> truncate decimal no.
        std::cout << "non displayable" << std::endl;
    //情况3：ASCII以内，可打印的字符， * 0-9 A-Z a-z ...
    else
        std::cout << "'" << static_cast<char>(doubleNumber) << "'" << std::endl;

    //int
    std::cout << "int: ";
    if (doubleNumber > INT_MAX || doubleNumber < INT_MIN)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(doubleNumber) << std::endl;
    
    //float & double
    std::cout << std::fixed << std::setprecision(1);//科学计数法-2.14748e+09 (-2.147483648共9位小数) 但由于设置了小数精度为1,所以显示-2147483648.0
    std::cout << "float: " << static_cast<float>(doubleNumber) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(doubleNumber) << std::endl;
}

/*
strtod(.c_str(), &end)

c_str(): 将string转为（c字符数组 + \0）
&end:    char*指针， 指向string中停止解析的位置 
         1. 42.42, 指向\0 ->double
         2. 42.42f,指向f  ->float
         3. 42abc，指向a
         4. abc, 指向a
strtod(): 1. abc， 返回0.0，end指向a
          2. 0,    返回0.0，end指向\0
*/

/*
浮点数精度丢失（Precision Loss）
答案：float（单精度浮点数）只有大约7位有效数字, 超出后丢失精度
输入：2147483648(10位数字)
输出：float：2147483648.0f
输入：2147843649
输出：float：2147483648.0f 一模一样！
在 float 的世界里，-2147483648 和 -2147483649 由于太接近了，最终都指向了同一个能被 float 表达的二进制数值。

Double可以储存15-17 位有效数字，没有这个问题

*/