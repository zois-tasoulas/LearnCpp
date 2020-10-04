#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";

    int smaller {};

    std::cin >> smaller;

    std::cout << "Enter a larger integer: ";

    int larger {};

    std::cin >> larger;

    if (smaller > larger) {
        std::cout << "Swapping the values" << std::endl;

        int swap {};

        swap = smaller;
        smaller = larger;
        larger = swap;
    } // swap dies here

    std::cout << "Smaller values is " << smaller << std::endl;
    std::cout << "Larger values is " << larger << std::endl;

    return 0;
} // smaller and larger die here
