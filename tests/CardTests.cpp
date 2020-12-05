#include "gtest/gtest.h"
#include "Card.h"

TEST(CardTests, TestConstructor)
{
    ASSERT_NO_THROW(Card(Face::TWO, Suit::HEARTS));
}

TEST(CardTests, TestValue)
{
    Card c1{Face::FIVE, Suit::SPADES};
    Card c2{Face::FIVE, Suit::HEARTS};
    Card c3{Face::TWO, Suit::CLUBS};
    Card c4{Face::ACE, Suit::DIAMONDS};
    EXPECT_EQ(c1.value(), 5);
    EXPECT_EQ(c2.value(), 5);
    EXPECT_EQ(c3.value(), 2);
    EXPECT_EQ(c4.value(), 14);
}