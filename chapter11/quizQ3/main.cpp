#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <iostream>
#include <limits>
#include <string>

#include "include/main.h"
#include "include/Potion.h"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
    std::rand(); // get rid of first result

    std::cout << "Enter you name: ";
    std::string playerName{};
    std::cin >> playerName;

    std::cout << "Welcome, " << playerName << std::endl;
    Player p{playerName};

    while (!p.isDead() && !p.hasWon()) {
        Monster m{ Monster::getRandomMonster() };
        std::cout << "You have encountered a " << m.getName()  << ' '
                  << m.getSymbol() << std::endl;
        while (!p.isDead() && !m.isDead()) {
            std::cout << "Enter 'r' to run or 'f' to fight: ";
            char action{};
            std::cin >> action;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (action) {
                case 'r':
                    if (fiftyPercentProbability()) {
                        attackPlayer(p, m);
                    } else {
                        m.reduceHealth(m.getHealth()); // Escape the monster by setting its health to 0
                        std::cout << "You have successfully fled\n";
                    }
                    break;
                case 'f':
                    fightMonster(p, m);
                    break;
                default:
                    std::cout << "Invalid action selected!\n";
                    break;
            }
        }
    }

    if (p.isDead()) {
        std::cout << "Unfortunately you have died. Your level was "
                  << p.getLevel() << " and you have accumulated "
                  << p.getGold() << " gold.\n";
        std::cout << "Try playing again!\n";
    } else if (p.hasWon()) {
        std::cout << "\nYou won! You accumulated " << p.getGold() << " gold!\n";
    } else {
        std::cout << "The game has unexpectedly terminated\n";
    }

    return 0;
}

void fightMonster(Player& p, Monster& m)
{
    attackMonster(p, m);
    if (m.isDead()) {
        std::cout << "You killed the " << m.getName() << ".\n";
        p.levelUp();
        std::cout << "You are now level " << p.getLevel() << ".\n";
        p.addGold(m.getGold());
        std::cout << "You found " << m.getGold() << " gold.\n";
        if (thirtyPercentProbability()) {
            handlePotion(p);
        }
    } else {
        attackPlayer(p, m);
    }
}

void attackMonster(Player& p, Monster& m)
{
    std::cout << "You hit the " << m.getName() << " for "
              << p.getDamagePerAttack() << " damage.\n";
    m.reduceHealth(p.getDamagePerAttack());
}

void attackPlayer(Player& p, Monster& m)
{
    std::cout << "The " << m.getName() << " hit you for "
              << m.getDamagePerAttack() << " damage.\n";
    p.reduceHealth(m.getDamagePerAttack());
}

void handlePotion(Player& p)
{
    std::cout << "You found a mythical potion! Do you want to drink it (y/n)?: ";
    char answer{};
    std::cin >> answer;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (answer == 'y') {
        Potion pt{};
        std::cout << "You drank a " << pt.getSizeName() << " potion of " << pt.getTypeName() << std::endl;
        p.drinkPotion(pt);
    }
    // If the player presses 'n' or another character, he/she does not drink the potion.
}

bool fiftyPercentProbability()
{
    return generateRandomNumber(0, 1) ? true : false;
}

bool thirtyPercentProbability()
{

    return (generateRandomNumber(0, 9) < 3) ? true : false;
}

int generateRandomNumber(int min, int max)
{
    static constexpr double fraction { 1.0 / (RAND_MAX + 1.0) };

    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}
