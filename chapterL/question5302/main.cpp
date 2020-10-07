#include <iostream>

enum class Animal
{
    cat,
    chicken,
    dog,
    goat,
    ostrich,
    pig
};

std::string getAnimalName (Animal myAnimal)
{
    std::string name {};

    switch (myAnimal)
    {
        case Animal::cat:
            name = "cat";
            break;
        case Animal::chicken:
            name = "chicken";
            break;
        case Animal::dog:
            name = "dog";
            break;
        case Animal::goat:
            name = "goat";
            break;
        case Animal::ostrich:
            name = "ostrich";
            break;
        case Animal::pig:
            name = "pig";
            break;
        default:
            std::cout << "\n[ERROR][getAnimalName] Unrecognized animal type."
                      << std::endl;
            break;
    }
    return name;
}

void printNumberOfLegs(Animal myAnimal)
{
    int numOfLegs {};

    switch (myAnimal)
    {
        case Animal::cat:
            numOfLegs = 4;
            std::cout << "A ";
            break;
        case Animal::chicken:
            numOfLegs = 2;
            std::cout << "A ";
            break;
        case Animal::dog:
            numOfLegs = 4;
            std::cout << "A ";
            break;
        case Animal::goat:
            numOfLegs = 4;
            std::cout << "A ";
            break;
        case Animal::ostrich:
            numOfLegs = 2;
            std::cout << "An ";
            break;
        case Animal::pig:
            numOfLegs = 4;
            std::cout << "A ";
            break;
        default:
            std::cout << "\n[ERROR][printNumberOfLegs] Unrecognized animal"
                      << " type." << std::endl;
            break;
    }

    std::cout << getAnimalName(myAnimal) << " has " << numOfLegs << " legs."
              << std::endl;
}

int main()
{
    printNumberOfLegs(Animal::cat);
    printNumberOfLegs(Animal::chicken);

    return 0;
}
