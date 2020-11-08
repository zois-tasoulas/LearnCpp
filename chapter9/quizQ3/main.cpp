#include <cassert>
#include <iostream>

class IntArray
{
private:
    int* m_array{};
    int m_size{};

    void deepCopy(const IntArray& array);

public:
    IntArray(int size) : m_size{size}
    {
        assert(size > 0 && "Array size should be greater or equal to 1");
        m_array = new int[size]{};
    }

    IntArray(const IntArray& array)
    {
        deepCopy(array);
    }

    ~IntArray()
    {
        delete[] m_array;
    }

    friend std::ostream& operator<<(std::ostream& out, const IntArray& array);
    int& operator[](const int index);
    IntArray& operator=(const IntArray &array);
};

void IntArray::deepCopy(const IntArray& array)
{
    m_size = array.m_size;

    delete[] m_array;
    m_array = new int[m_size];

    for (int ii{0}; ii < m_size; ++ii) {
        m_array[ii] = array.m_array[ii];
    }
}

std::ostream& operator<<(std::ostream& out, const IntArray& array)
{
    for (int ii{0}; ii < array.m_size; ++ii) {
        out << array.m_array[ii] << ' ';
    }

    return out;
}

int& IntArray::operator[](const int index)
{
    assert(index >= 0 && "Index should be greater or equal to 1");
    assert(index < m_size && "Index should not exceed the array size");

    return m_array[index];
}

IntArray& IntArray::operator=(const IntArray &array)
{
    if (this != &array)
        deepCopy(array);

    return *this;
}

IntArray fillArray()
{
    IntArray a(5);

    a[0] = 5;
    a[1] = 8;
    a[2] = 2;
    a[3] = 3;
    a[4] = 6;

    return a;
}

int main()
{
    IntArray a{ fillArray() };
    std::cout << a << '\n';

    auto &ref{ a }; // we're using this reference to avoid compiler self-assignment errors
    a = ref;

    IntArray b(1);
    b = a;

    std::cout << b << '\n';

    return 0;
}
