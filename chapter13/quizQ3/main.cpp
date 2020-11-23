#include <iostream>

#include "headers/StringValuePair.h"

int main()
{
    StringValuePair<int> svp("Hello", 5);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}
