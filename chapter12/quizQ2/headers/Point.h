#ifndef HEADERS_POINT
#define HEADERS_POINT

#include <iostream>

class Point
{
private:
    int m_x{ 0 };
    int m_y{ 0 };
    int m_z{ 0 };

public:
    Point(int x, int y, int z)
        : m_x{x}, m_y{y}, m_z{z}
    {
    }

    friend std::ostream& operator<<(std::ostream &out, const Point &p);
};

#endif // HEADERS_POINT
