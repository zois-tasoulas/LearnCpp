#include "Player.h"

    void Player::drawCard(Deck& deck)
    {
        m_score += deck.dealCard().value();
    }

    bool Player::isBust()
    {
        return m_score > maximumScore;
    }

    int Player::score (void)
    {
        return m_score;
    }
