#ifndef HEADERS_TRIANGLE
#define HEADERS_TRIANGLE

#include "Shape.h"
#include "Point.h"

class Triangle final : public Shape
{
private:
    Point m_pointA;
    Point m_pointB;
    Point m_pointC;

    virtual std::ostream& print (std::ostream &out) const override;
    virtual std::string getShape () const;

public:
    Triangle() : m_pointA {0, 0, 0}, m_pointB {0, 0, 0}, m_pointC {0, 0, 0}
    {
    }

    Triangle(const Point &pointA, const Point &pointB, const Point &pointC)
        : m_pointA {pointA}, m_pointB {pointB}, m_pointC {pointC}
    {
    }

    ~Triangle()
    {
    }
};

#endif // HEADERS_TRIANGLE
