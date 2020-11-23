#ifndef HEADERS_PAIR1
#define HEADERS_PAIR1

template <typename T>
class Pair1 final
{
private:
    T m_elementA;
    T m_elementB;

public:
    Pair1 (const T& elementA, const T& elementB) : m_elementA {elementA}, m_elementB {elementB}
    {
    }

    ~Pair1 () = default;

    const T& first () const;
    const T& second () const;
};

template <typename T>
const T& Pair1<T>::first () const
{
    return m_elementA;
}

template <typename T>
const T& Pair1<T>::second () const
{
    return m_elementB;
}

#endif // HEADERS_PAIR1
