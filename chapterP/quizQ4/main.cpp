#include <iostream>

void printString (const char *str)
{
    for (const char *ptr{str}; *ptr != '\0'; ++ptr) {
        std::cout << *ptr << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    char str[] {"Hello, world!"};
    printString(str);

    return 0;
}
