#include <iostream>

void evenNumbers()
{
    for (int num {0}; num <= 20; ++num) {
        if (num % 2 == 0) {
            std::cout << num << std::endl;
        }
    }
    std::cout << std::endl;
}

long long sumTo (int value)
{
    long long acc {0};

    for (int cnt; cnt <= value; ++cnt) {
        acc += cnt;
    }

    return acc;
}

int main()
{
    evenNumbers();

    int value {10};
    std::cout << "Sum of all numbers from 1 to "<< value << " is "
              << sumTo(value) << std::endl;

    return 0;
}
