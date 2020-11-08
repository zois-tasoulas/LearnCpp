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

int main()
{
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();

    Fraction f7{0, 6};
    f7.print();


    return 0;
}
