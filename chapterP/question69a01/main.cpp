#include <algorithm>
#include <iostream>
#include <limits>

int main()
{
    std::cout << "How many names would you like to enter? ";
    int numOfNames {};
    std:: cin >> numOfNames;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string *names {new std::string[static_cast<size_t>(numOfNames)]};

    for (int ii{0}; ii < numOfNames; ++ii) {
        std::cout << "Enter name #" << ii + 1 << ": ";
        std::cin >> names[ii];
    }
    std::cout << std::endl;

    std::sort(names, names + numOfNames);

    std::cout << "Here is your sorted list:" << std::endl;
    for (int ii{0}; ii < numOfNames; ++ii) {
        std::cout << "Enter name #" << ii + 1 << ": " << names[ii] << std::endl;
    }

    return 0;
}
