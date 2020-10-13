#include <iostream>

int main()
{
    std::string names[]{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred",
                        "Greg", "Holly"};
    std::cout << "Enter a name: ";
    std::string inputName {};
    std::cin >> inputName;

    bool found {false};
    for (const auto &name: names) {
        if ( name == inputName) {
            found = true;
            break;
        }
    }

    std::cout << inputName;
    if (found) {
        std::cout << " was found.\n";
    } else {
        std::cout << " was not found.\n";
    }

    return 0;
}
