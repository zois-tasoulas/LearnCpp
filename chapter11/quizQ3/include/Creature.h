#ifndef INCLUDE_CREATURE
#define INCLUDE_CREATURE

#include "string"

class Creature
{
protected:
    std::string m_name{};
    char m_symbol{};
    int m_health{};
    int m_damagePerAttack{};
    int m_gold{};

public:
    Creature() = delete; // Default constructor not available
    Creature(const std::string& name,
             const char symbol,
             const int health,
             const int damagePerAttack,
             const int gold);

    // Getter functions
    const std::string& getName() const;
    char getSymbol() const;
    int getHealth() const;
    int getDamagePerAttack() const;
    int getGold() const;

    void reduceHealth(const int healthReduction);
    bool isDead() const;
    void addGold(const int additionalGold);
};

#endif // INCLUDE_CREATURE
