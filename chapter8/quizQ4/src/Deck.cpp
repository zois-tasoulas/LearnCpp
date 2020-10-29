#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>

#include "Deck.h"

    Deck::Deck()
    {
        m_cardIndex = 0;

        index_type card{ 0 };

        auto suits{ static_cast<index_type>(CardSuit::MAX_SUITS) };
        auto ranks{ static_cast<index_type>(CardRank::MAX_RANKS) };

        for (index_type suit{ 0 }; suit < suits; ++suit) {
            for (index_type rank{ 0 }; rank < ranks; ++rank) {
                m_deck[card] = {static_cast<CardRank>(rank), static_cast<CardSuit>(suit)};
                ++card;
            }
        }
    }

    void Deck::print(void)
    {
        for (const auto& card : m_deck) {
            card.print();
            std::cout << ' ';
        }
        std::cout << '\n';
    }

    void Deck::shuffle(void)
    {
        static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

        std::shuffle(m_deck.begin(), m_deck.end(), mt);
        // After shuffling, next card should be dealt from the top
        m_cardIndex = 0;
    }

    const Card& Deck::dealCard(void)
    {
        return m_deck[m_cardIndex++];
    }
