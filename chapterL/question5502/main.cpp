#include <iostream>

int main()
{
    char letter {'a'};

    while (letter <= 'z') {
        std::cout << "Letter is " << letter << ", it's ASCII code is "
                  << static_cast<int>(letter) << std::endl;
        ++letter;
    }

    return 0;
}
