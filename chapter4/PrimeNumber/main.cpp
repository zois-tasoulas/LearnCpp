#include <iostream>

void isPrime (int x)
{
    if (x == 2) {
        std::cout << "The digit is prime.\n";
    } else if (x == 3) {
        std::cout << "The digit is prime.\n";
    } else if (x == 5) {
        std::cout << "The digit is prime.\n";
    } else if (x == 7) {
        std::cout << "The digit is prime.\n";
    } else {
        std::cout << "The digit is not prime.\n";
    }
}

int main()
{
    int x{};
    std::cout << "Please enter a single digit integer: ";
    std::cin >> x;
    isPrime(x);

    return 0;
}
