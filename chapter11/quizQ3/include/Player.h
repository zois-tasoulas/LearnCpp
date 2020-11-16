#ifndef INCLUDE_PLAYER
#define INCLUDE_PLAYER

#include <string>

#include "Creature.h"
#include "Potion.h"

class Player : public Creature
{
private:
    int m_level{};

public:
    Player() = default; //No default constructor
    Player(const std::string& name);

    // Getter function
    int getLevel() const;

    void levelUp();
    bool hasWon() const;
    void drinkPotion(const Potion& potion);
};

#endif // INCLUDE_PLAYER
