#ifndef HEADERS_SHAPE
#define HEADERS_SHAPE

#include <iostream>

class Shape
{
public:
    virtual ~Shape()
    {
    }

    friend std::ostream& operator<< (std::ostream& out, const Shape& shape);
    virtual std::ostream& print (std::ostream &out) const = 0;
    virtual std::string getShape () const = 0;
};

#endif // HEADERS_SHAPE
