#ifndef INCLUDE_GRANNYSMITH
#define INCLUDE_GRANNYSMITH

#include <string>

#include "Apple.h"

class GrannySmith : public Apple
{
public:
    GrannySmith(const std::string& color="green", const std::string& name="granny smith apple");
};

#endif // INCLUDE_GRANNYSMITH
