#include "headers/Point.h"

std::ostream& operator<<(std::ostream &out, const Point &p)
{
    return out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ')';
}
