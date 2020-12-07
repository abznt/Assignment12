#ifndef ASSIGNMENT12_HAND_H
#define ASSIGNMENT12_HAND_H

#include "Card.h"
#include "CardConversions.h"
#include <memory>
#include <vector>
#include <iostream>

class Hand
{
  public:
    static constexpr size_t MAX_CARDS = 5;
    using CARD_PTR = std::unique_ptr<const Card>;

  private:
    std::vector<CARD_PTR> m_cards;

  public:
    Hand() = default;

    [[nodiscard]] size_t numCards() const;
    [[nodiscard]] bool full() const;
    void addCard(CARD_PTR card);
    CARD_PTR removeCard(size_t index);
    [[nodiscard]] Card peekCard(size_t index) const;
    [[nodiscard]] std::vector<Card> viewCards() const;
    void clear();
};

inline std::ostream& operator<<(std::ostream& os, const Hand& hand)
{
    os << "{ ";
    for (auto &card : hand.viewCards())
    {
        os << "[" << card << "] ";
    }
    os << "}";
    return os;
}

#endif // ASSIGNMENT12_HAND_H
