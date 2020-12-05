#include "Card.h"

Card::Card(Face face, Suit suit) : face(face), suit(suit)
{
}

Card::Card(const Card* other) : face(other->face), suit(other->suit)
{
}
