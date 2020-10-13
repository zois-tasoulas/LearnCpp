#include <iostream>

namespace Animals
{
    enum AnimalNames {
        cat,
        chicken,
        dog,
        duck,
        elephant,
        snake,
        numOfAnimals
    };
}

std::string printAnimalName (Animals::AnimalNames animal)
{
    std::string name {};

    switch(animal)
    {
        case Animals::cat:
            name = "cat";
            break;
        case Animals::chicken:
            name = "chicken";
            break;
        case Animals::dog:
            name = "dog";
            break;
        case Animals::duck:
            name = "duck";
            break;
        case Animals::elephant:
            name = "elephant";
            break;
        case Animals::snake:
            name = "snake";
            break;
        default:
            std::cout << "[ERROR] Wrong animal name given." << std::endl;
            break;
    }

    return name;
}

int main()
{
    // double highestTemperature[365] {};
    int numOfLegs[Animals::numOfAnimals] {4, 2, 4, 2, 4, 0};

    std::cout << "An " << printAnimalName(Animals::elephant) << " has "
              << numOfLegs[Animals::elephant] << " legs." << std::endl;

    return 0;
}
