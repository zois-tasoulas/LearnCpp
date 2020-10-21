#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <tuple>
#include <vector>
#include <utility>

constexpr int answerThreshold {4};

int square (int num)
{
    return num * num;
}

std::pair<int,int> readInput (void)
{
    std::cout << "Enter a positive integer to start from? ";
    int start {};
    std::cin >> start;

    std::cout << "How many numbers to generate? ";
    int range {};
    std::cin >> range;

    return std::make_pair(start, range);
}

int readNumber (void)
{
    std::cout << "Give a number: ";
    int inputNum {};
    std::cin >> inputNum;

    return inputNum;
}

int createRandomNumber (const int min, const int max)
{
    // Initialize Mersenne Twister random seed
    static std::mt19937 mersenne {static_cast<std::mt19937::result_type>(std::time(nullptr))};
    // Create a distribution between 2 and 4
    std::uniform_int_distribution<> distribution {min, max};

    return distribution(mersenne);
}

void populateVector (std::vector<int>& numbers, const int range,
                     const int randNumber, const int startNumber)
{
    for (auto ii {0}; ii < range; ++ii) {
        numbers.push_back(square(startNumber + ii) * randNumber);
    }
}

void playGame(std::vector<int>& numbers, const int range, const int randNumber)
{
    std::cout << "I generated " << range << " square numbers. Do you know what"
              << " each number is after multiplying it by " << randNumber
              << "?\n";
    while (1) {
        int inputNum {readNumber()};

        auto index {std::find(std::begin(numbers), std::end(numbers), inputNum)};
        if (index != std::end(numbers)) {
            numbers.erase(index);
            std::cout << "Nice! ";
            if (numbers.empty())
                break;
            std::cout << numbers.size() << " number(s) left.\n";
        } else {
            int closestToGuess {*std::min_element(std::begin(numbers),
                                                 std::end(numbers), [inputNum](int a, int b){
                                                 return std::abs(inputNum - a) < std::abs(inputNum - b);
                                                 } )};
            std::cout << inputNum << " is wrong!";
            if ((inputNum - closestToGuess) <= answerThreshold) {
                std::cout << " Try " << closestToGuess << " next time.";
            }
            std::cout << std::endl;
            break;
        }
    }

    if (numbers.empty()) {
        std::cout << "You found all numbers, good job!\n";
    }
}

int main ()
{
    int startNum {};
    int range {};

    std::tie (startNum, range) = readInput();

    constexpr int minNum {2};
    constexpr int maxNum {4};

    int randNumber {createRandomNumber(minNum, maxNum)};

    std::vector<int> numbers {};
    numbers.reserve(static_cast<size_t>(range));

    populateVector(numbers, range, randNumber, startNum);

    playGame(numbers, range, randNumber);

    return 0;
}
