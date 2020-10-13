#include <iostream>
#include <limits>

int askNumber()
{
    int input;
    const int minNum {1};
    const int maxNum {9};

    while (true) {
        std::cout << "Give a number between " << minNum << " and " << maxNum
                  << ": ";
        std::cin >> input;

        if (std::cin.fail() || input < 1 || input > 9) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong input given.\n";
       } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }

    return input;
}

int main()
{
    const int userInput {askNumber()};

    constexpr int myArray[] {4, 6, 7, 3, 8, 2, 1, 9, 5};
    const int arraySize {sizeof(myArray) / sizeof(myArray[0])};

    std::cout << "The array elements are:\n";
    for (int ii{0}; ii < arraySize; ++ii) {
        std::cout << myArray[ii] << ' ';
    }
    std::cout << std::endl;

    for (int ii{0}; ii < arraySize; ++ii) {
        if (myArray[ii] == userInput) {
            std::cout << "The element entered appears in index: " << ii
                      << std::endl;
            break;
        }
    }

    return 0;
}
