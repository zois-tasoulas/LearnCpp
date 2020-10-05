#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter full Name: ";
    std::string fullName {};
    std::getline(std::cin, fullName);

    std::cout << "Enter your age: ";
    int age {};
    std::cin >> age;

    std::cout << "You've lived " << static_cast<double>(age) / fullName.length()
              << " years for each letter in your name."<< std::endl;

    return 0;
}
