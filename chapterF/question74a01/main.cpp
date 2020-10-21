#include <iostream>
#include <string>
#include <vector>
#include <utility>

struct Employee
{
    std::string name;
    //etc
};

int sumTo(const int inputNumber);

void printEmployeeName(const Employee &employee1);

std::pair<int, int> minmax(const int numA, const int numB);

int getIndexOfLargestValue(const std::vector<int> &myArray);

const std::string& getElement(const std::vector<std::string> &myArray, const int index);

int main()
{

    return 0;
}
