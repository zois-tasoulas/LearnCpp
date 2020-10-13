#include <iostream>

void mySwap (int &a, int &b)
{
    int aux {a};

    a = b;
    b = aux;
}

int main()
{
    std::cout << "Enter value of number A: ";
    int numA {};
    std::cin >> numA;
    std::cout << "Enter value of number B: ";
    int numB {};
    std::cin >> numB;

    mySwap(numA, numB);
    std::cout << "After swap A is " << numA << " and B is " << numB << " .\n";

    return 0;
}
