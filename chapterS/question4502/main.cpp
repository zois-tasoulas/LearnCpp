#include <iostream>

enum MonsterType
{
    MONSTER_ORC,
    MONSTER_GOBLIN,
    MONSTER_TROLL,
    MONSTER_OGRE,
    MONSTER_SKELETON
};

int main ()
{
    MonsterType monster {MONSTER_TROLL};

    std::cout << "Monter race is: " << monster << std::endl;

    return 0;
}
