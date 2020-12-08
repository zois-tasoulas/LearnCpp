#include <iostream>
#include <memory> // for std::shared_ptr

class Something; // assume Something is a class that can throw an exception

int main()
{
    doSomething(std::make_shared<Something>(),
                std::make_shared<Something>());

    return 0;
}
