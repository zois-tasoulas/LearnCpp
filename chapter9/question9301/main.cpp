#include "cassert"
#include <iostream>

class Fraction
{
private:
    int m_numerator{};
    int m_denominator{};

public:
    Fraction(int numerator=0, int denominator=1) : m_numerator(numerator), m_denominator(denominator)
    {
        assert(denominator != 0 && "Denominator cannot be initialized to zero\n");
        if (numerator != 0)
            reduce();
    }

    void print()
    {
        std::cout << m_numerator << '/' << m_denominator << std::endl;
    }

    int gcd(const int a,  const int b)
    {
        return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
    }

    void reduce()
    {
        int myGcd {gcd(m_numerator, m_denominator)};

        m_numerator /= myGcd;
        m_denominator /= myGcd;
    }

    friend Fraction operator*(const Fraction &f1, const Fraction &f2);
    friend Fraction operator*(const Fraction &f1, const int num);
    friend Fraction operator*(const int num, const Fraction &f1);
    friend std::ostream& operator<<(std::ostream &out, const Fraction &frac);
    friend std::istream& operator>>(std::istream &in, Fraction &frac);
};

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
    return {f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator};
}

Fraction operator*(const Fraction &f1, const int num)
{
    return {f1.m_numerator * num, f1.m_denominator};
}

Fraction operator*(const int num, const Fraction &f1)
{
    return {f1.m_numerator * num, f1.m_denominator};
}

std::ostream& operator<<(std::ostream &out, const Fraction &frac)
{
    out << frac.m_numerator << '/' << frac.m_denominator;

    return out;
}

std::istream& operator>>(std::istream &in, Fraction &frac)
{
    char backSlash{};

    in >> frac.m_numerator;
    in >> backSlash; // Consume fraction back slash
    in >> frac.m_denominator;

    return in;
}

int main()
{
    Fraction f1{};
    std::cout << "Enter fraction 1: ";
    std::cin >> f1;

    Fraction f2{};
    std::cout << "Enter fraction 2: ";
    std::cin >> f2;

    std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value

    return 0;
}
