#include <ctime>
#include <iostream>
#include <limits>
#include <random>

int getInt ()
{
    while (true) {
        int input {};
        std::cin >> input;

        if (std::cin.fail() || input < 1 || input > 100) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input given. Give a number between 1 and"
                      << " 100: " << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return input;
        }
    }
}

bool askToReplay ()
{
    while(true) {
        std::cout << "Would you like to play again (y/n)?" << std::endl;
        char answer {};
        std::cin >> answer;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(answer) {
            case 'y':
                return true;
            case 'n':
                return false;
            default:
                break;
        }
    }
}

void playGame(const int randomNumber, const int tries)
{
    bool foundFlag {false};

    for (int ii {1}; ii <= tries; ++ii) {
        std::cout << "Guess #" << ii << ": ";
        int guess {getInt()};

        if (guess > randomNumber) {
            std::cout << "Your guess is too high." << std::endl;
        } else if (guess < randomNumber) {
            std::cout << "Your guess is too low." << std::endl;
        } else { // Guess is equal to random number
            foundFlag = true;
            break;
        }
    }

    if (foundFlag) {
        std::cout << "Correct! You win!" << std::endl;
    } else {
        std::cout << "Sorry, you lose. The correct number was " << randomNumber
                  << '.' << std::endl;
    }
}

int main()
{
    // Initialize Mersenne Twister random seed
    std::mt19937 mersenne {static_cast<std::mt19937::result_type>(std::time(nullptr))};
    // Create a distribution between 1 and 100
    std::uniform_int_distribution<> randomDistribution {1, 100};

    do {
        constexpr int tries {7};
        std::cout << "Let's play a game. I'm thinking of a number between 1"
                  << " and 100. You have " << tries
                  << " tries to guess what it is." << std::endl;
        playGame(randomDistribution(mersenne), tries);
    } while (askToReplay());

    std::cout << "Thank you for playing." << std::endl;

    return 0;
}
