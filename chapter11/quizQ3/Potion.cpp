#include "include/Potion.h"

Potion::Potion() : m_type{getRandomType()}, m_size{getRandomSize()}
{
    m_value = assignValue(m_type, m_size);
}

Potion::Type Potion::getType () const
{
    return m_type;
}

std::string Potion::getTypeName () const
{
    switch (m_type) {
        case Type::health:
            return "Health";
        case Type::strength:
            return "Strength";
        case Type::poison:
            return "Poison";
        default:
            throw("Unexpected type assigned");
            break;
    }
}

std::string Potion::getSizeName () const
{
    switch (m_size) {
        case Size::small:
            return "Small";
        case Size::medium:
            return "Medium";
        case Size::large:
            return "Large";
        default:
            throw("Unexpected size assigned");
            break;
    }
}

int Potion::getValue() const
{
    return m_value;
}

Potion::Size Potion::getRandomSize()
{
    return static_cast<Size>(randomNumber0To2());
}

Potion::Type Potion::getRandomType()
{
    return static_cast<Type>(randomNumber0To2());
}

int Potion::randomNumber0To2()
{
    static constexpr int min {0};
    static constexpr int max {2};
    static constexpr double fraction { 1.0 / (RAND_MAX + 1.0) };

    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

int Potion::assignValue(Type type, Size size)
{
    static int valueArray[3][3] { {2, 2, 2},
                                    {1, 1, 1},
                                    {-1, -1, -1} };
    return valueArray[static_cast<int>(type)][static_cast<int>(size)];
}
