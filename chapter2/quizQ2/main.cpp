int readNumber();
void writeAnswer(int num);

int main()
{
    int sum{};

    sum = readNumber() + readNumber();
    writeAnswer(sum);

    return 0;
}
