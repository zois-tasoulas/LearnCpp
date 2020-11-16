#ifndef INCLUDE_MONSTER
#define INCLUDE_MONSTER

#include "Creature.h"

class Monster : public Creature
{
public:
    enum class Type {
        dragon = 0,
        orc,
        slime,
        max_types
    };

    Monster() = delete; // No default constructor
    Monster(Type monsterType);
    static Monster getRandomMonster();

private:
    static const Creature& getDefaultCreature(Type type);
};

#endif // INCLUDE_MONSTER
