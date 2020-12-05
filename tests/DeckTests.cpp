#include "gtest/gtest.h"
#include "Deck.h"
#include "Card.h"

TEST(DeckTests, TestConstructor)
{
    ASSERT_NO_THROW(Deck());
    Deck d1{};
    ASSERT_FALSE(d1.empty());
    ASSERT_EQ(d1.numCards(), 52);
}

TEST(DeckTests, TestPeek)
{
    Deck d1{};
    const Card c1 = d1.peekTopCard();
    EXPECT_EQ(c1.face, Face::ACE);
    EXPECT_EQ(c1.suit, Suit::HEARTS);
}

TEST(DeckTests, TestRemove)
{
    Deck d1{};
    size_t initialSize = d1.numCards();
    auto cardPtr1 = d1.removeTopCard();
    EXPECT_EQ(initialSize - 1, d1.numCards());
    EXPECT_EQ(cardPtr1->face, Face::ACE);
    EXPECT_EQ(cardPtr1->suit, Suit::HEARTS);
}