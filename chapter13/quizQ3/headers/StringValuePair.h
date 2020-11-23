#ifndef HEADERS_STRINGVALUEPAIR
#define HEADERS_STRINGVALUEPAIR

#include "Pair.h"

template <typename T>
class StringValuePair : public Pair<std::string, T>
{
public:
    StringValuePair(const std::string& str, const T& value)
        : Pair<std::string, T>(str, value)
    {
    }

    ~StringValuePair () = default;
};

#endif // HEADERS_STRINGVALUEPAIR
