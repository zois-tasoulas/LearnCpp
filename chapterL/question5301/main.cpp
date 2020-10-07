#include <iostream>

long int calculate (int num1, int  num2, char op)
{
    long long result {};

    switch (op)
    {
        case '+':
            result = static_cast<long long>(num1) + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = static_cast<long long>(num1) * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        case '%':
            result = num1 % num2;
            break;
        default:
            std::cout << "\n[ERROR] Wrong arithmetic operator passed to the"
                      << " function!\nThe result printed is not valid."
                      << std::endl;
            break;
    }

    return result;
}

int main()
{
    int num1 {};
    int num2 {};

    std::cout << "Insert two numbers: ";
    std::cin >> num1 >> num2;

    char op {};
    std::cout << "Insert an arithmetic operator (acceptable are +, -, *, /, %): ";
    std::cin >> op;

    long long result = calculate(num1, num2, op);
    std::cout << "The result of the operation is: " << result << std::endl;

    return 0;
}
