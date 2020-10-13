#include <algorithm>
#include <array>
#include <ctime>
#include <iostream>
#include <limits>

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

enum class Results
{
    draw = 0,
    player_wins,
    dealer_wins
};

struct Card
{
    Ranks rank {};
    Suits suit {};
};

struct Player
{
    int sum {};
    int aceCount {};
};

constexpr int deckSize = 52;
constexpr int bustLimit = 21;
constexpr int dealerThreshold = 17;
using deckType = std::array<Card, deckSize>;

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

deckType createDeck(void)
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

void printDeck(const deckType &deck)
{
    for (Card card: deck) {
        printCard(card);
        std::cout << ' ';
    }
    std::cout << std::endl;
}

void shuffleDeck(deckType &deck)
{
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
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

// Side effects on player and index
void pickCard(const deckType &deck, size_t &index, Player &player)
{
    player.sum += getCardValue(deck[index]);
    if (deck[index].rank == Ranks::rank_ace) {
        ++player.aceCount;
    }

    ++index;
}

// Side effects on player
void checkAndFixBusted(Player &player)
{
    if (player.sum > bustLimit && player.aceCount > 0) {
        player.sum -= 10;
        player.aceCount -= 1;
    }
}

Results playBlackjack (const deckType &deck)
{
    size_t index {0};
    Player dealer {};
    pickCard(deck, index, dealer);
    std::cout << "The dealer picked a card."<< std::endl;
    Player player {};
    pickCard(deck, index, player);

    // Player picks second card
    pickCard(deck, index, player);

    checkAndFixBusted(player);

    std::string option {};
    while (player.sum < bustLimit) {
        std::cout << "Your current cards value is: " << player.sum
                  << ". Would you like to hit or stand? " << std::endl;
        std::cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (option == "hit") {
            pickCard(deck, index, player);
        } else if (option == "stand") {
            break;
        } else {
            std::cout << "Unknown choice.\n";
        }
        checkAndFixBusted(player);
    }

    if (player.sum > bustLimit){
        printf("Player is busted, %d\n", player.sum);
        return Results::dealer_wins;
    }

    // Dealer makes his/her moves
    while (dealer.sum < dealerThreshold) {
        pickCard(deck, index, dealer);
        checkAndFixBusted(dealer);
    }

    std::cout << "The player accrued " << player.sum
              << " points. The dealer accrued " << dealer.sum << " points."
              << std::endl;
    if (player.sum > dealer.sum || dealer.sum > bustLimit) {
        return Results::player_wins;
    } else if (player.sum == dealer.sum) {
        return Results::draw;
    } else {
        return Results::dealer_wins;
    }
}

void announceResult (Results result)
{
    switch (result) {
        case Results::dealer_wins:
            printf("The dealer wins!\n");
            break;
        case Results::player_wins:
            printf("The player wins!\n");
            break;
        case Results::draw:
            printf("The game is a draw!\n");
            break;
        default:
            printf("Unknown result");
            break;
    }
}

int main()
{
    auto deck{createDeck()};
    shuffleDeck(deck);

    announceResult(playBlackjack(deck));

    return 0;
}
