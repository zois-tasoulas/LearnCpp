#include <array>

#include "include/Monster.h"

Monster::Monster(Type monsterType) : Creature{getDefaultCreature(monsterType)}
{
}

const Creature& Monster::getDefaultCreature(Type type)
{
    static std::array<Creature,
                      static_cast<std::size_t>(Type::max_types)> monsterData {
        { {"dragon", 'D', 20, 4, 100},
        {"orc", 'o', 4, 2, 25},
        {"slime", 's', 1, 1, 10} }
    };

    return monsterData.at(static_cast<std::size_t>(type));
}

Monster Monster::getRandomMonster()
{
    static constexpr int min{0};
    static constexpr int max{static_cast<int>(Type::max_types) - 1};
    static constexpr double fraction { 1.0 / (RAND_MAX + 1.0) };

    int type{min + static_cast<int>((max - min + 1) * (std::rand() * fraction))};

    return Monster{static_cast<Type>(type)};
}
