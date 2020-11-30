#include <iostream>
#include <stdexcept>

#include "headers/Fraction.h"

Fraction::Fraction(int numerator, int denominator)
    : m_numerator {numerator}, m_denominator {denominator}
{
    if (m_denominator == 0) {
        throw std::runtime_error("Invalid denominator");
    }
}

std::ostream& operator<<(std::ostream &out, const Fraction &fraction)
{
    out << fraction.m_numerator << '/' << fraction.m_denominator;
    return out;
}
