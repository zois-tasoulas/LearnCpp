#include <iostream>

class IntPair
{
public:
    int m_val1{};
    int m_val2{};

    void set(int num1, int num2)
    {
        m_val1 = num1;
        m_val2 = num2;
    }

    void print()
    {
        std::cout << "Pair(" << m_val1 << ", " << m_val2 << ")\n";
    }
};

int main()
{
   IntPair p1;

   p1.set(1, 1);

   IntPair p2{2, 2};

   p1.print();
   p2.print();

   return 0;
}
