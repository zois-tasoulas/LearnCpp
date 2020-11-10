#include <cassert>
#include <initializer_list>
#include <iostream>

class IntArray
{
private:
    int m_length{};
    int *m_data{};

public:
    IntArray() = default;

    IntArray(int length) :
        m_length{ length },
        m_data{ new int[length]{} }
    {
    }

    IntArray(std::initializer_list<int> list) : // allow IntArray to be initialized via list initialization
    IntArray(static_cast<int>(list.size())) // use delegating constructor to set up initial array
    {
        // Now initialize our array from the list
        int count{ 0 };
        for (auto element : list) {
            m_data[count] = element;
            ++count;
        }
    }

    ~IntArray()
    {
        delete[] m_data;
        /* we don't need to set m_data to null or m_length to 0 here, since the
         * object will be destroyed immediately after this function anyway
         */
    }

    IntArray(const IntArray&) = delete; // to avoid shallow copies

    IntArray& operator=(const IntArray& array) {
        // In case of self assignment, no need to copy anything
        if (m_data == array.m_data)
            return *this;

        if (m_length != array.m_length) {
            delete[] m_data;
            m_length = array.m_length;
            m_data = new int[m_length];
        }

        for (int ii{0}; ii < m_length; ++ii) {
            m_data[ii] = array.m_data[ii];
        }

        return *this;
    }

    IntArray& operator=(const std::initializer_list<int> list) {
        if (m_length != static_cast<int>(list.size())) {
            delete[] m_data;
            m_length = list.size();
            m_data = new int[m_length];
        }

        int index{0};
        for (auto element : list) {
            m_data[index++] = element;
        }

        return *this;
    }

    int& operator[](int index) {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int getLength() const { return m_length; }
};

int main()
{
    IntArray array { 5, 4, 3, 2, 1 }; // initializer list
    for (int count{ 0 }; count < array.getLength(); ++count)
        std::cout << array[count] << ' ';

    std::cout << '\n';

    array = { 1, 3, 5, 7, 9, 11 };

    for (int count{ 0 }; count < array.getLength(); ++count)
        std::cout << array[count] << ' ';

    std::cout << '\n';

    IntArray arrayB {1, 1, 2, 3, 5, 8, 13, 21};

    for (int count{ 0 }; count < arrayB.getLength(); ++count)
        std::cout << arrayB[count] << ' ';

    std::cout << '\n';

    arrayB = arrayB;

    for (int count{ 0 }; count < arrayB.getLength(); ++count)
        std::cout << arrayB[count] << ' ';

    std::cout << '\n';

    return 0;
}
