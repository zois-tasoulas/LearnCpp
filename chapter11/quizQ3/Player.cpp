#include "cassert"

#include "include/Player.h"

Player::Player(const std::string& name)
        : Creature(name, '@', 10, 1, 0), m_level{1}
{
}

int Player::getLevel() const
{
    return m_level;
}

void Player::levelUp()
{
    ++m_level;
    ++m_damagePerAttack;
}

bool Player::hasWon() const
{
    assert(m_level <= 20 && "Level found greater than 20");
    return (m_level == 20) ? true : false;
}

void Player::drinkPotion(const Potion& potion)
{
    switch (potion.getType()) {
        case Potion::Type::health:
        case Potion::Type::poison:
            m_health += potion.getValue();
            break;
        case Potion::Type::strength:
            m_damagePerAttack += potion.getValue();
            break;
        default:
            throw("Unexpected potion type");
    }
}
