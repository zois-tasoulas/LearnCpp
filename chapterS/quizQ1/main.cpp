#include <iostream>

enum class MonsterType
{
    ogre,
    dragon,
    orc,
    giant_spider,
    slime
};

struct Monster
{
    MonsterType type {};
    std::string name {};
    int health {0};
};

std::string retMonsterType (MonsterType type)
{
    std::string typeString {};

    if (type == MonsterType::ogre) {
        typeString = "Ogre";
    } else if (type == MonsterType::dragon) {
        typeString = "Dragon";
    } else if (type == MonsterType::orc) {
        typeString = "Orc";
    } else if (type == MonsterType::giant_spider) {
        typeString = "Giant spider";
    } else if (type == MonsterType::slime) {
        typeString = "Slime";
    } else {
        typeString = "Unknown monster type!";
    }

    return typeString;
}

void printMonster(Monster myMonster)
{
    std::cout << "This " << retMonsterType(myMonster.type) << " is named "
              << myMonster.name << " and has " << myMonster.health << " health."
              << std::endl;
}

int main()
{
    Monster ogre {MonsterType::ogre, "Torg", 145};
    printMonster(ogre);

    Monster slime {MonsterType::slime, "Blurp", 23};
    printMonster(slime);

    return 0;
}
