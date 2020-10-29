#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"

constexpr int maximumScore {21};

class Player
{
private:
    int m_score{};

public:
    void drawCard(Deck& deck);
    bool isBust();
    int score (void);
};

#endif // PLAYER_H
