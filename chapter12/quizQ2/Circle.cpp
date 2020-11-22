#include "headers/Circle.h"

std::ostream& Circle::print (std::ostream &out) const
{
    return out << "Circle(" << m_center << ", radius " << m_radius << ')';
}

std::string Circle::getShape () const
{
    return "Circle";
}

int Circle::getRadius() const
{
    return m_radius;
}
