#include <iostream>

int readNumber();
void writeAnswer(int num);

int main()
{
    int sum{};

    sum = readNumber() + readNumber();
    writeAnswer(sum);

    return 0;
}

int readNumber()
{
    int num;

    std::cout << "Provide an integer: ";
    std::cin >> num;

    return num;
}

void writeAnswer(int num)
{
    std::cout << "The sum of the two inputed integers is " << num << ".\n";
}
