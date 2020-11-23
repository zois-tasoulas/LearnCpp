#ifndef HEADERS_PAIR
#define HEADERS_PAIR

template <typename T1, typename T2>
class Pair
{
protected:
    T1 m_elementA;
    T2 m_elementB;

public:
    Pair (const T1& elementA, const T2& elementB) : m_elementA {elementA}, m_elementB {elementB}
    {
    }

    ~Pair () = default;

    const T1& first () const;
    const T2& second () const;
};

template <typename T1, typename T2>
const T1& Pair<T1, T2>::first () const
{
    return m_elementA;
}

template <typename T1, typename T2>
const T2& Pair<T1, T2>::second () const
{
    return m_elementB;
}

#endif // HEADERS_PAIR
