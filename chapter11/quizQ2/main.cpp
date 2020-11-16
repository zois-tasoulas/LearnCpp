#include <iostream>

#include "include/Apple.h"
#include "include/Banana.h"
#include "include/GrannySmith.h"

int main()
{
    Apple a{ "red" };
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}
