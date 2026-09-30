#include "Serialization.hpp"
#include "Data.hpp"
#include <string>
#include <iostream>

int main(void)
{
    Data    myData;
    myData.i = 88;
    myData.s = "Good morning!";

    Data*   myDataPtr = &myData;
    std::cout << "My data pointer: " << myDataPtr << std::endl;

    uintptr_t myDataAdress = Serializer::serialize(myDataPtr);
    std::cout << "pointer -> int: " << myDataAdress << std::endl;

    Data*   newDataPtr = Serializer::deserialize(myDataAdress);
    std::cout << "int -> pointer: " << newDataPtr << std::endl;

    if (myDataPtr == newDataPtr)
        std::cout << "Success!" << std::endl;
    else
        std::cout << "Fail!" << std::endl;

    return 0;
}