#ifndef ASSIGNMENT12_CARDCONVERSIONS_H
#define ASSIGNMENT12_CARDCONVERSIONS_H

#include "Face.h"
#include "Suit.h"
#include <map>
#include <string>

class CardConversions
{
  public:
    inline static const std::map<Face, std::string> faceToStringMap{
        std::make_pair(Face::TWO, "2"),   std::make_pair(Face::THREE, "3"), std::make_pair(Face::FOUR, "4"),
        std::make_pair(Face::FIVE, "5"),  std::make_pair(Face::SIX, "6"),   std::make_pair(Face::SEVEN, "7"),
        std::make_pair(Face::EIGHT, "8"), std::make_pair(Face::NINE, "9"),  std::make_pair(Face::TEN, "10"),
        std::make_pair(Face::JACK, "J"),  std::make_pair(Face::QUEEN, "Q"), std::make_pair(Face::KING, "K"),
        std::make_pair(Face::ACE, "A")};
    inline static const std::map<Suit, std::string> suitToStringMap{
        std::make_pair(Suit::SPADES, "S"), std::make_pair(Suit::CLUBS, "C"), std::make_pair(Suit::HEARTS, "H"),
        std::make_pair(Suit::DIAMONDS, "D")};
};

#endif // ASSIGNMENT12_CARDCONVERSIONS_H
