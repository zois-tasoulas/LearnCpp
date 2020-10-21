#include <iostream>
#include <functional>
#include <limits>
#include <tuple>

using arithmeticFnc = std::function<int(int,int)>;

char readMathOp (void)
{
    char mathOp {};
    bool loopFlag {true};
    while (loopFlag) {
        std::cout << "Please enter the character of a mathematical operation."
                  << "\nAccepted characters are '+', '-', '*' and '/': ";
        std::cin >> mathOp;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cout << "Wrong type of input given\n";
        } else {
            switch(mathOp) {
                case '+':
                case '-':
                case '*':
                case '/':
                    loopFlag = false;
                    break;
                default:
                    std::cout << "Unrecognized operator entered.\n";
                    break;
            }
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return mathOp;
}

std::tuple<int, int> readTwoIntegers()
{
    int num1 {};
    int num2 {};
    while(true) {
        std::cout << "Provide two integers separated by space: ";
        std::cin >> num1 >> num2;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong input given.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }

    return std::make_tuple(num1, num2);
}

int add (int a, int b)
{
    return a + b;
}

int subtract (int a, int b)
{
    return a - b;
}

int multiply (int a, int b)
{
    return a * b;
}

int divide (int a, int b)
{
    return a / b;
}

arithmeticFnc getArithmeticFunction(char op)
{
    arithmeticFnc func {};
    switch(op) {
        case '+':
            func = add;
            break;
        case '-':
            func = subtract;
            break;
        case '*':
            func = multiply;
            break;
        case '/':
            func = divide;
            break;
        default:
            std::cout << "Unexpected arithmetic operator given.\n";
            break;
    }
    return func;
}

int main()
{
    char mathOp {readMathOp()};
    int a {};
    int b {};
    std::tie(a,b) = readTwoIntegers();

    arithmeticFnc func {getArithmeticFunction(mathOp)};
    std::cout << "The result of the operation "<< a << ' ' << mathOp << ' '
              << b << " is " << func(a, b) << std::endl;
    return 0;
}
