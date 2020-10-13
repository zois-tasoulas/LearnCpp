#include <algorithm>
#include <array>
#include <ctime>
#include <iostream>

enum class Suits
{
    clubs = 0,
    diamonds,
    hearts,
    spades,
    max_suits
};

enum class Ranks
{
    rank_ace = 0,
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    rank_jack,
    rank_queen,
    rank_king,
    max_ranks
};

struct Card
{
    Ranks rank {};
    Suits suit {};
};

constexpr int deck_size = 52;
using deckType = std::array<Card, deck_size>;

void printCard (const Card &card)
{
    switch(card.rank) {
        case Ranks::rank_ace:
            std::cout << 'A';
            break;
        case Ranks::rank_2:
            std::cout << '2';
            break;
        case Ranks::rank_3:
            std::cout << '3';
            break;
        case Ranks::rank_4:
            std::cout << '4';
            break;
        case Ranks::rank_5:
            std::cout << '5';
            break;
        case Ranks::rank_6:
            std::cout << '6';
            break;
        case Ranks::rank_7:
            std::cout << '7';
            break;
        case Ranks::rank_8:
            std::cout << '8';
            break;
        case Ranks::rank_9:
            std::cout << '9';
            break;
        case Ranks::rank_10:
            std::cout << 'T';
            break;
        case Ranks::rank_jack:
            std::cout << 'J';
            break;
        case Ranks::rank_queen:
            std::cout << 'Q';
            break;
        case Ranks::rank_king:
            std::cout << 'K';
            break;
        default:
            std::cout << "Wrong rank!\n";
            break;
    }

    switch(card.suit) {
        case Suits::clubs:
            std::cout << 'C';
            break;
        case Suits::diamonds:
            std::cout << 'D';
            break;
        case Suits::hearts:
            std::cout << 'H';
            break;
        case Suits::spades:
            std::cout << 'S';
            break;
        default:
            std::cout << "Wrong suit!\n";
            break;
    }
}

deckType createDeck()
{
    deckType deck {};

    for (int suit {0}; suit < static_cast<int>(Suits::max_suits); ++suit) {
        for (int rank {0}; rank < static_cast<int>(Ranks::max_ranks); ++rank) {
            const int index {suit * static_cast<int>(Ranks::max_ranks) + rank};
            deck[static_cast<size_t>(index)].rank = static_cast<Ranks>(rank);
            deck[static_cast<size_t>(index)].suit = static_cast<Suits>(suit);
        }
    }

    return deck;
}

void printDeck(deckType &deck)
{
    for (Card card: deck) {
        printCard(card);
        std::cout << ' ';
    }
    std::cout << std::endl;
}

void shuffleDeck(deckType &deck, std::mt19937 mt)
{
  std::shuffle(deck.begin(), deck.end(), mt);
}

int getCardValue (const Card &card)
{
    int value {};
    switch (card.rank) {
        case Ranks::rank_2:
            value = 2;
            break;
        case Ranks::rank_3:
            value = 3;
            break;
        case Ranks::rank_4:
            value = 4;
            break;
        case Ranks::rank_5:
            value = 5;
            break;
        case Ranks::rank_6:
            value = 6;
            break;
        case Ranks::rank_7:
            value = 7;
            break;
        case Ranks::rank_8:
            value = 8;
            break;
        case Ranks::rank_9:
            value = 9;
            break;
        case Ranks::rank_10:
        case Ranks::rank_jack:
        case Ranks::rank_queen:
        case Ranks::rank_king:
            value = 10;
            break;
        case Ranks::rank_ace:
            value = 11;
            break;
        default:
            std::cout << "Unexpected card value!\n";
            break;
    }
    return value;
}

int main()
{
    auto deck{createDeck()};
    printDeck(deck);
    std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    shuffleDeck(deck, mt);
    printDeck(deck);

    return 0;
}
