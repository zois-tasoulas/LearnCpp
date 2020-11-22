#include "headers/Triangle.h"

std::ostream& Triangle::print (std::ostream &out) const
{
    return out << "Triangle(" << m_pointA << ", " << m_pointB << ", "
               << m_pointC << ')';
}

std::string Triangle::getShape () const
{
    return "Triangle";
}
