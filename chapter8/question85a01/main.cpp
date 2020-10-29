#include <iostream>
#include <cstdint>

class RGBA
{
private:
    std::uint_fast8_t m_red;
    std::uint_fast8_t m_green;
    std::uint_fast8_t m_blue;
    std::uint_fast8_t m_alpha;

public:
    RGBA(const std::uint_fast8_t red=0, const std::uint_fast8_t green=0,
         const std::uint_fast8_t blue=0, const std::uint_fast8_t alpha=255) :
        m_red{red},
        m_green{green},
        m_blue{blue},
        m_alpha{alpha}
    {
    }

    void print()
    {
        std::cout << "r=" << static_cast<int>(m_red) << " g="
                  << static_cast<int>(m_green) << " b="
                  << static_cast<int>(m_blue) << " a="
                  << static_cast<int>(m_alpha) << std::endl;
    }
};

int main()
{
    RGBA teal{0, 127, 127};
    teal.print();

    return 0;
}
