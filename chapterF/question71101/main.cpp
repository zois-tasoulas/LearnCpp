#include <iostream>
#include <limits>

int readNumber (void)
{
    int num {};
    while (true) {
        std::cout << "Provide a number to calculate its factorial: ";
        std::cin >> num;

        if (std::cin.fail() || num < 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong input provided. Accepted input should be a non "
                      << "negative integer.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }

    return num;
}

int factorial (int num)
{
    if (num == 0) {
        return 1;
    } else if (num > 0) {
        return num * factorial(num - 1);
    } else {
        std::cout << "Negative integer encountered, this point should not have"
                  << " been reached.\n";
        return 0;
    }

}

int main()
{

    int num {readNumber()};

    std::cout << num <<"! is " << factorial(num) << std::endl;

    return 0;
}
