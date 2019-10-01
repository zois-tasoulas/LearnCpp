#include "io.h"

int main()
{
    int sum{};

    sum = readNumber() + readNumber();
    writeAnswer(sum);

    return 0;
}
