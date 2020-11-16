#ifndef INCLUDE_BANANA
#define INCLUDE_BANANA

#include <string>

#include "Fruit.h"

class Banana : public Fruit
{
public:
    Banana(const std::string& color="yellow", const std::string& name="banana");
};

#endif // INCLUDE_BANANA
