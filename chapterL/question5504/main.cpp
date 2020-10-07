#include <iostream>

int main()
{
    int outer {1};

    while (outer <= 5) {
        int inner {5};

        while (inner > outer) {
            std::cout << "  ";  // Two spaces
            --inner;
        }
        while (inner > 0) {
            std::cout << inner << ' ';
            --inner;
        }
        std::cout << std::endl;
        ++outer;
    }

    return 0;
}
