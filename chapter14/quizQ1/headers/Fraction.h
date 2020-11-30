#ifndef HEADERS_FRACTION
#define HEADERS_FRACTION

class Fraction final
{
private:
    int m_numerator{};
    int m_denominator{};

public:
    Fraction() = delete; // Disable default constructor
    Fraction(int numerator, int denominator);

    friend std::ostream& operator<<(std::ostream &out, const Fraction &fraction);
};

#endif // HEADERS_FRACTION
