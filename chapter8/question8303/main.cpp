#include <array>
#include <assert.h>
#include <iostream>

class Stack
{
private:
    static constexpr int m_maxSize{10};
    std::array<int, m_maxSize> m_stackArray{};
    size_t m_size{};

public:
    void reset()
    {
        m_size = 0;
    }

    bool push(const int val)
    {
       if (m_size == m_maxSize) {
           return false;
       } else {
           m_stackArray[m_size++] = val;
           return true;
       }
    }

    int pop()
    {
        assert(m_size > 0 && "Attempt to pop on an empty stack");

        return m_stackArray[--m_size];
    }

    void print()
    {
        std::cout << "( ";
        for (size_t ii{0}; ii < m_size; ++ii) {
            std::cout << m_stackArray[ii] << " ";
        }
        std::cout << ")\n";
    }
};

int main()
{
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}
