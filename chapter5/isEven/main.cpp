#include <iostream>

int readInput();
bool isEven(int number);
void printOutput(int number, bool logicalValue);

int main()
{
    int x{readInput()};

    printOutput(x, isEven(x));

    return 0;
}

int readInput()
{
    int number;

    std::cout << "Please provide an integer: ";
    std::cin >> number;

    return number;
}

bool isEven(int number)
{
    if (number % 2 == 0) {
        return true;
    } else {
        return false;
    }
}

void printOutput(int number, bool logicalValue)
{
    if (logicalValue) {
        std::cout << number << " is even";
    } else {
        std::cout << number << " is odd";
    }
}
