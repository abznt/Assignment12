#ifndef ASSIGNMENT12_HAND_H
#define ASSIGNMENT12_HAND_H

#include "Card.h"
#include <memory>
#include <vector>

class Hand
{
  public:
    static constexpr size_t MAX_CARDS = 5;
    using CARD = std::unique_ptr<const Card>;
    using CARDS = std::vector<CARD>;

  private:
    CARDS m_cards;

  public:
    Hand() = default;

    [[nodiscard]] size_t numCards() const;
    void addCard(CARD card);
    CARD removeCard(size_t index);
    [[nodiscard]] const std::vector<Card> viewCards() const;
    void clear();
};

#endif // ASSIGNMENT12_HAND_H
