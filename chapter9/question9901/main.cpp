#include <cassert>
#include <iostream>
#include <string>

class MyString
{
private:
    std::string m_string{};

public:
    MyString(const std::string& str="") : m_string{str}
    {
    }

    std::string operator()(const int index, const int length);
};

std::string MyString::operator()(const int index, const int length)
{
    assert(index >= 0 && "Index should be greater or equal to zero");
    assert(index + length <= static_cast<int>(m_string.length())
           && "Provided length exceeds the actual string length");

   return m_string.substr(static_cast<size_t>(index),
                          static_cast<size_t>(length));
}

int main()
{
    MyString string{ "Hello, world!" };
    std::cout << string(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}
