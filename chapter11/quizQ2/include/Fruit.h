#ifndef INCLUDE_FRUIT
#define INCLUDE_FRUIT

#include <string>

class Fruit
{
private:
    std::string m_name{};
    std::string m_color{};

public:
    Fruit() = delete; // No default constructor
    Fruit(const std::string& name, const std::string& color);

    const std::string& getName();
    const std::string& getColor();
};

#endif // INCLUDE_FRUIT
