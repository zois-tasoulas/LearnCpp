#include <iostream>
#include <limits>
#include <stdexcept>

#include "headers/Fraction.h"

Fraction readFraction ()
{
    std::cout << "Enter the numerator: ";
    int numerator{};
    std::cin >> numerator;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter the denominator: ";
    int denominator{};
    std::cin >> denominator;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return Fraction{numerator, denominator};
}

int main()
{
    try {
        Fraction myFraction{readFraction()};
        std::cout << "The fraction is " << myFraction << std::endl;
    } catch (const std::exception &excep) {
        std::cout << excep.what() << std::endl;
    }

    return 0;
}
