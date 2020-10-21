#include <iostream>
#include <limits>

int readNumber (void)
{
    int num {};
    while (true) {
        std::cout << "Provide an integer to present in binary representation: ";
        std::cin >> num;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong input provided.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }

    return num;
}

void toBinary(uint num)
{
    if (num > 1) {
        toBinary(num / 2);
    }
    std::cout << num % 2;
}

void toBinary (int num)
{
    if (num < 0) {
        toBinary(static_cast<uint>(num));
    } else {
        if (num > 1) {
            toBinary(num / 2);
        }
        std::cout << num % 2;
    }
}

int main()
{
    int num {readNumber()};
    toBinary(num);

    return 0;
}
