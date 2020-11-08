#include <iostream>

class Point
{
private:
    double m_x, m_y, m_z;

public:
    Point(double x=0.0, double y=0.0, double z=0.0):
        m_x{x}, m_y{y}, m_z{z}
    {
    }

    Point operator+() const;

    // Convert a Point into its negative equivalent
    Point operator-() const;

    // Return true if the point is set at the origin
    bool operator!() const;

    double getX() const { return m_x; }
    double getY() const { return m_y; }
    double getZ() const { return m_z; }
};

Point Point::operator+() const
{
    return Point(m_x, m_y, m_z);
}

// Convert a Point into its negative equivalent
Point Point::operator-() const
{
    return Point(-m_x, -m_y, -m_z);
}

// Return true if the point is set at the origin, false otherwise
bool Point::operator!() const
{
    return (m_x == 0.0 && m_y == 0.0 && m_z == 0.0);
}

int main()
{
    Point point{}; // use default constructor to set to (0.0, 0.0, 0.0)

    std::cout << "Applying the '+' operator on a Point object.\n"
              << "(x, y, z) is " << "(" << (+point).getX() << ", "
              << (+point).getY() << ", " << (+point).getZ() << ")\n";

    return 0;
}
