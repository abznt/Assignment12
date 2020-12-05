#ifndef ASSIGNMENT12_DECK_H
#define ASSIGNMENT12_DECK_H

#include "Face.h"
#include "Suit.h"
#include "Card.h"
#include <vector>
#include <memory>
#include <random>

class Deck
{
  public:
    static const std::vector<Face> faces;
    static const std::vector<Suit> suits;

  private:
    std::vector<std::unique_ptr<const Card>> m_cards;
    std::mt19937 m_rng;

  public:
    Deck();

    void shuffle();
    const Card peekTopCard() const;
    std::unique_ptr<const Card> removeTopCard();

    [[nodiscard]] size_t numCards() const
    {
        return m_cards.size();
    }

    [[nodiscard]] bool empty() const
    {
        return m_cards.empty();
    }

  private:
    void fillDeck();
};

#endif // ASSIGNMENT12_DECK_H
