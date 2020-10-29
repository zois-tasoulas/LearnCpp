#ifndef CARD_H
#define CARD_H


enum class CardSuit
{
    SUIT_CLUB = 0,
    SUIT_DIAMOND,
    SUIT_HEART,
    SUIT_SPADE,
    MAX_SUITS
};

enum class CardRank
{
    RANK_2 = 0,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8,
    RANK_9,
    RANK_10,
    RANK_JACK,
    RANK_QUEEN,
    RANK_KING,
    RANK_ACE,
    MAX_RANKS
};

class Card
{
private:
    CardRank m_rank{};
    CardSuit m_suit{};

public:
    // Default constructor
    Card() = default;

    Card(CardRank rank, CardSuit suit);
    void print (void) const;
    int value (void) const;

};
#endif // CARD_H
