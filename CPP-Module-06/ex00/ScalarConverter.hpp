/*
C++ Type Conversion: 
convert the value of one data type to another type.

#include <iostream>
#include <iomanip>   // for fixed and setprecision

int main() {
  int num1 = 5;
  int num2 = 2;
  double sum = static_cast<double>(num1)/num2; // 5.0 / 2 == 2.5 
  cout << fixed << setprecision(1) << sum;     // 2.5 control the number of decimals
  return 0;
}

*/

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
         private://"It must not be instantiable by users"（不可被实例化）
                ScalarConverter();
                ScalarConverter(const ScalarConverter& other);
                ScalarConverter& operator=(const ScalarConverter& other);
                        ~ScalarConverter();
                static bool ifPseudo(const std::string& literal);
                static void printSpecial(const std::string& literal);
        public:
                static void convert(const std::string& literals);
};

#endif