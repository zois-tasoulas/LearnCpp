#include <iostream>

double enterNumber();
char enterOperation();
void calculateAndPrintResult(double number1, double number2, char operation);

int main()
{
    double input1{enterNumber()};
    double input2{enterNumber()};
    char operation{enterOperation()};

    calculateAndPrintResult(input1, input2, operation);

    return 0;
}

double enterNumber ()
{
    double number{};

    std::cout << "Please enter a real number: ";
    std::cin >> number;

    return number;
}

char enterOperation ()
{
    char operationSymbol;

    std::cout << "Please enter one of the following operation symbols, +, -, * or / : ";
    std::cin >> operationSymbol;

    return operationSymbol;
}

void calculateAndPrintResult(double number1, double number2, char operation)
{
    if (operation == '+') {
        std::cout << number1 << ' ' << operation << ' ' << number2 << " is " << number1 + number2 << '\n';
    } else if (operation == '-') {
        std::cout << number1 << ' ' << operation << ' ' << number2 << " is " << number1 - number2 << '\n';
    } else if (operation == '*') {
        std::cout << number1 << ' ' << operation << ' ' << number2 << " is " << number1 * number2 << '\n';
    } else if (operation == '/') {
        std::cout << number1 << ' ' << operation << ' ' << number2 << " is " << number1 / number2 << '\n';
    } else {
    }
}
