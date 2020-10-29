#ifndef DECK_H
#define DECK_H

#include <array>

#include "Card.h"

using index_type = size_t;
constexpr int cardsInDeck {52};

class Deck
{
private:
    std::array<Card, cardsInDeck> m_deck{};
    index_type m_cardIndex{};

public:
    Deck();
    void print(void);
    void shuffle(void);
    const Card& dealCard(void);
};

#endif // DECK_H
