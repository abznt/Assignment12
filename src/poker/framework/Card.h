#ifndef ASSIGNMENT12_CARD_H
#define ASSIGNMENT12_CARD_H

#include "Face.h"
#include "Suit.h"
#include "CardConversions.h"
#include <iostream>

class Card
{
  public:
    const Face face;
    const Suit suit;

  public:
    Card(Face face, Suit suit);
    Card(const Card* other);
    [[nodiscard]] int value() const
    {
        return static_cast<int>(face);
    }
};

inline std::ostream &operator<<(std::ostream &os, const Card &card)
{
    return os << CardConversions::faceToStringMap.at(card.face) << CardConversions::suitToStringMap.at(card.suit);
}

#endif // ASSIGNMENT12_CARD_H
