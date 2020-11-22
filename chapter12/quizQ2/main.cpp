#include <iostream>
#include <vector>

#include "headers/Circle.h"
#include "headers/Point.h"
#include "headers/Triangle.h"

int getLargestRadius (std::vector<Shape*> v);

int main()
{
    std::vector<Shape*> v{
      new Circle{Point{1, 2, 3}, 7},
      new Triangle{Point{1, 2, 3}, Point{4, 5, 6}, Point{7, 8, 9}},
      new Circle{Point{4, 5, 6}, 3}
    };

    for (const auto* shape : v) {
        std::cout << (*shape) << std::endl;
    }

    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

    for (const auto* shape : v) {
        delete shape;
    }

    return 0;
}

int getLargestRadius (const std::vector<Shape*> v)
{
    int maxRadius {0};

    for (const auto* shape : v) {
        if (shape->getShape() == "Circle") {
            maxRadius = std::max(dynamic_cast<const Circle*>(shape)->getRadius(),
                                 maxRadius);
        }
    }

    return maxRadius;
}
