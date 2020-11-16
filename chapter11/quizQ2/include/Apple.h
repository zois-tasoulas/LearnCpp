#ifndef INCLUDE_APPLE
#define INCLUDE_APPLE

#include <string>

#include "Fruit.h"

class Apple : public Fruit
{
public:
    Apple(const std::string& color="red", const std::string& name="apple");
};

#endif // INCLUDE_APPLE
