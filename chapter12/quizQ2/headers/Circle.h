#ifndef HEADERS_CIRCLE
#define HEADERS_CIRCLE

#include "Shape.h"
#include "Point.h"

class Circle final : public Shape
{
private:
    Point m_center;
    int m_radius {};

    virtual std::ostream& print (std::ostream &out) const override;
    virtual std::string getShape () const;

public:
    Circle() : m_center {0, 0, 0}, m_radius {0}
    {
    }

    Circle(const Point &center, const int radius)
        : m_center {center}, m_radius {radius}
    {
    }

    ~Circle()
    {
    }

    int getRadius() const;
};

#endif // HEADERS_CIRCLE
