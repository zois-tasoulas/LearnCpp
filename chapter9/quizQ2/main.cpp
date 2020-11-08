#include <iostream>

class Average
{
private:
    std::int_least32_t m_sum{};
    std::int_least8_t m_seen{};

public:
    Average(std::int_least32_t sum=0, std::int_least8_t seen=0) : m_sum{sum}, m_seen{seen}
    {
    }

    Average& operator+=(int numAdd);
    friend std::ostream& operator<<(std::ostream& out, const Average& avrg);
};

Average& Average::operator+=(int numAdd)
{
    m_sum += numAdd;
    ++m_seen;

    return *this;
}

std::ostream& operator<<(std::ostream& out, const Average& avrg)
{
    out << (static_cast<float>(avrg.m_sum) / avrg.m_seen);

    return out;
}

int main()
{
    Average avg{};

    avg += 4;
    std::cout << avg << '\n'; // 4 / 1 = 4

    avg += 8;
    std::cout << avg << '\n'; // (4 + 8) / 2 = 6

    avg += 24;
    std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

    avg += -10;
    std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

    (avg += 6) += 10; // 2 calls chained together
    std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

    Average copy{ avg };
    std::cout << copy << '\n';

    return 0;
}
