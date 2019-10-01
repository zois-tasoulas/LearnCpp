#include <iostream>

int readNum()
{
    int num{};

    std::cout << "Enter an integer number:\n";
    std::cin >> num;

    return num;
}

int doubleNumber(int a)
{
    return 2 * a;
}

void printOut(int num)
{
    std::cout << num << " doubled is " << doubleNumber(num) << '\n';
}

int main()
{
    printOut(readNum());
    return 0;
}
