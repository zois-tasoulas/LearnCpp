#include <iostream>

class HelloWorld
{
private:
	char *m_data{};

public:
	HelloWorld()
	{
		m_data = new char[14];
		const char *init{ "Hello, World!" };
		for (int i = 0; i < 14; ++i)
			m_data[i] = init[i];
	}

	void deepCopy(const HelloWorld& source)
	{
        delete[] m_data;

        if (source.m_data) {
            m_data = new char[14];

            for (int ii{0}; ii < 14; ++ii) {
                m_data[ii] = source.m_data[ii];
            }
        } else {
            m_data = nullptr;
        }
	}

    // Copy constructor
	HelloWorld(const HelloWorld& source)
	{
	    deepCopy(source);
	}

	~HelloWorld()
	{
        delete[] m_data;
	}

	void print() const
	{
		std::cout << m_data << '\n';
	}

    // Assignment operator
    HelloWorld& operator=(const HelloWorld& source)
    {
        if (this != &source) {
            deepCopy(source);
        }

        return *this;
    }
};

int main()
{
	HelloWorld hello{};
	hello.print();

    return 0;
}
