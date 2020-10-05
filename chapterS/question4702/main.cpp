#include <iostream>

struct Fraction {
    int numerator {0};
    int denominator {0};
};

Fraction readFraction()
{
    Fraction frac;
    std::cout << "Please give the numerator of the fraction: ";
    std::cin >> frac.numerator;

    std::cout << "Please give the denominator of the fraction: ";
    std::cin >> frac.denominator;
    std::cout << std::endl;

    return frac;
}

void multiply (Fraction frac1, Fraction frac2)
{
    double numerator {static_cast<double>(frac1.numerator * frac2.numerator)};
    double denominator {static_cast<double>(frac1.denominator * frac2.denominator)};

    std::cout << "The product of the two fractions is: "
              << numerator / denominator << std::endl;
}

int main()
{
    std::cout << "Please give data for two fractions:" << std::endl;
    Fraction fraction1 {readFraction()};
    Fraction fraction2 {readFraction()};

    multiply(fraction1, fraction2);

    return 0;
}
