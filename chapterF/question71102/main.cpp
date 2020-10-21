#include <iostream>
#include <limits>

int readNumber (void)
{
    int num {};
    while (true) {
        std::cout << "Provide a non negative integer: ";
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

int digitSum (int num)
{
    if (num < 10) {
        return num;
    } else if (num > 10) {
        return (num % 10) + digitSum(num / 10);
    } else {
        std::cout << "Negative number found, not expected.\n";
        return -1;
    }

}

int main()
{
    int num {93427}; // Can be initialized with readNumber()

    std::cout << "The sum of the digits of " << num << " is " << digitSum(num) << std::endl;

    return 0;
}
