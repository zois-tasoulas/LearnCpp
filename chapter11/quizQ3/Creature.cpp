#include "include/Creature.h"

Creature::Creature(const std::string& name,
             const char symbol,
             const int health,
             const int damagePerAttack,
             const int gold)
             : m_name{name},
               m_symbol{symbol},
               m_health{health},
               m_damagePerAttack{damagePerAttack},
               m_gold{gold}
{
}

const std::string& Creature::getName() const
{
    return m_name;
}

char Creature::getSymbol() const
{
    return m_symbol;
}

int Creature::getHealth() const
{
    return m_health;
}

int Creature::getDamagePerAttack() const
{
    return m_damagePerAttack;
}

int Creature::getGold() const
{
    return m_gold;
}

void Creature::reduceHealth(const int healthReduction)
{
    m_health -= healthReduction;
}

bool Creature::isDead() const
{
    return (m_health <= 0) ? true : false;
}

void Creature::addGold(const int additionalGold)
{
    m_gold += additionalGold;
}
