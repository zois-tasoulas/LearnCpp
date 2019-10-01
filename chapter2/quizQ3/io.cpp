#include <iostream>

#include "io.h"

int readNumber()
{
    int num{};

    std::cout << "Provide an integer: ";
    std::cin >> num;

    return num;
}

void writeAnswer(int num)
{
    std::cout << "The sum of the two inputed integers is " << num << ".\n";
}
