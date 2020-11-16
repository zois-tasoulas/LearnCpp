#ifndef INCLUDE_POTION
#define INCLUDE_POTION

#include <string>

class Potion
{
public:
    enum class Type {
        health = 0,
        strength,
        poison
    };

    enum class Size {
        small = 0,
        medium,
        large
    };

    Potion();

    // Getter functions
    std::string getTypeName() const;
    std::string getSizeName() const;
    Type getType() const;
    int getValue() const;

private:
    Type m_type{};
    Size m_size{};
    int m_value{};

    Size getRandomSize();
    Type getRandomType();
    int assignValue(Type type, Size size);
    static int randomNumber0To2();
};

#endif // INCLUDE_POTION
