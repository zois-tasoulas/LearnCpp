#include <cmath>
#include <iostream>

#include "Point2d.h"

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

    return 0;
}

double square(double x)
{
    return x * x;
}

double distanceFrom(Point2d a, Point2d b)
{
    return std::sqrt(square(a.m_x - b.m_x) + square(a.m_y - b.m_y)) ;
}
