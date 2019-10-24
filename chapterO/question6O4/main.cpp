#include <iostream>
#include <bitset>

void printBinary(int number);

int main()
{
    int number {};

    std::cout << "Please provide an integer between 0 and 255: ";
    std::cin >> number;
    printBinary(number);
    return 0;
}

void printBinary(int number)
{
    int powerOf2 {128};
    int i {};

    std::cout << number << " in binary is: ";
    for (i = 0; i < 7; ++i) {
        if (number >= powerOf2) {
            std::cout << 1;
            number -= powerOf2;
        } else {
            std::cout << 0;
        }
        powerOf2 /= 2;
    }
    if (number == 1) {
        std::cout << 1;
    } else {
        std::cout << 0;
    }
}
