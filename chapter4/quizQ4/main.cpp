#include <iostream>
#include "constants.h"

int readHeight();
void printDistance(int seconds, int height);
double distanceFallen(int seconds);

int main()
{
    int height{readHeight()};
    int seconds{0};

    printDistance(seconds, height);
    seconds += 1;
    printDistance(seconds, height);
    seconds += 1;
    printDistance(seconds, height);
    seconds += 1;
    printDistance(seconds, height);
    seconds += 1;
    printDistance(seconds, height);
    seconds += 1;
    printDistance(seconds, height);

    return 0;
}

int readHeight()
{
    int height;

    std::cout << "Please enter the height of the tower in \
meters: ";
    std::cin >> height;

    return height;
}

void printDistance(int seconds, int height)
{
    double distance{height - distanceFallen(seconds)};

    if (distance > 0) {
        std::cout << "At " << seconds << ", the ball is at \
height: " << distance << " meters.\n";
    } else {
        std::cout << "At " << seconds << ", the ball is on \
the ground.\n";
    }
}

double distanceFallen(int seconds)
{
    double distance{myConstants::gravity * seconds * seconds / 2};

    return distance;
}
