#ifndef POINT2D_H
#define POINT2D_H


class Point2d
{
public:
    Point2d(double x=0, double y=0);
    void print(void) const;

    friend double distanceFrom(Point2d a, Point2d b);
    friend double square(double x);

private:
    double m_x{};
    double m_y{};
};

#endif // POINT2D_H
