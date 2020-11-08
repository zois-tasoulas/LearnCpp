#include <cmath>
#include <iomanip>
#include <iostream>

class FixedPoint2
{
private:
    int16_t m_integralPart{};
    int8_t m_fractionalPart{};

public:
    FixedPoint2(int16_t integral=0, int8_t fractional=0)
        : m_integralPart{integral}, m_fractionalPart{fractional}
    {
        if (abs(fractional) > 99) {
            std::cerr << "Fractional part should be between -99 and 99\n";
            throw std::runtime_error("Fractional part out of bounds");
        }

        if ((integral < 0) || (fractional < 0)) {
            m_integralPart = -abs(integral);
            m_fractionalPart = -abs(fractional);
        }
    }

    FixedPoint2(double number=0.0)
    {
        if (number > 32767.99 || number < -32768.99) {
            std::cerr << "Number should be between -32768.99 and 32767.99\n";
            throw std::runtime_error("Number provided for initialization is"
                                     " out of bounds");
        }

        m_integralPart = static_cast<int16_t>(number);
        m_fractionalPart = static_cast<int8_t>(round((number - m_integralPart)
                                                     * 100));
    }

    friend std::ostream& operator<<(std::ostream& out, const FixedPoint2& num);
    operator double() const;
    friend bool operator==(const FixedPoint2& numA, const FixedPoint2& numB);
    friend std::istream& operator>>(std::istream& in, FixedPoint2& num);
    FixedPoint2 operator-() const;
    friend FixedPoint2 operator+(const FixedPoint2& numA, const FixedPoint2& numB);
};

std::ostream& operator<<(std::ostream& out, const FixedPoint2& num)
{
    return out << static_cast<double>(num);
}

FixedPoint2::operator double() const
{
    return static_cast<double>(m_integralPart) + m_fractionalPart / 100.0;
}

bool operator==(const FixedPoint2& numA, const FixedPoint2& numB)
{
    return numA.m_integralPart == numB.m_integralPart
           && numA.m_fractionalPart == numB.m_fractionalPart;
}

std::istream& operator>>(std::istream& in, FixedPoint2& number)
{
    double input{};
    in >> input;

    number = FixedPoint2{input};
    return in;
}

FixedPoint2 FixedPoint2::operator-() const
{
    return FixedPoint2(-m_integralPart, -m_fractionalPart);
}

FixedPoint2 operator+(const FixedPoint2& numA, const FixedPoint2& numB)
{
    return FixedPoint2{static_cast<double>(numA) + static_cast<double>(numB)};
}

void testAddition()
{
    // h/t to reader Sharjeel Safdar for this function
    std::cout << std::boolalpha;
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } ==
                  FixedPoint2{ 1.98 }) << '\n'; // both positive, no decimal overflow
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } ==
                  FixedPoint2{ 2.25 }) << '\n'; // both positive, with decimal overflow
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } ==
                  FixedPoint2{ -1.98 }) << '\n'; // both negative, no decimal overflow
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } ==
                  FixedPoint2{ -2.25 }) << '\n'; // both negative, with decimal overflow
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } ==
                  FixedPoint2{ -0.48 }) << '\n'; // second negative, no decimal overflow
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } ==
                  FixedPoint2{ -0.75 }) << '\n'; // second negative, possible decimal overflow
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } ==
                  FixedPoint2{ 0.48 }) << '\n'; // first negative, no decimal overflow
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } ==
                  FixedPoint2{ 0.75 }) << '\n'; // first negative, possible decimal overflow
}

int main()
{
    testAddition();

    FixedPoint2 a{ -0.48 };
    std::cout << a << '\n';

    std::cout << -a << '\n';

    std::cout << "Enter a number: "; // enter 5.678
    std::cin >> a;

    std::cout << "You entered: " << a << '\n';

    return 0;
}
