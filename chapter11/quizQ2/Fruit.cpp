#include "include/Fruit.h"

Fruit::Fruit(const std::string& name, const std::string& color)
           : m_name{name}, m_color{color}
{
}

const std::string& Fruit::getName()
{
      return m_name;
}

const std::string& Fruit::getColor()
{
    return m_color;
}
