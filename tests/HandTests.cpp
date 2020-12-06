#include "framework/Card.h"
#include "framework/Hand.h"
#include "gtest/gtest.h"

TEST(HandTests, TestConstructor)
{
    ASSERT_NO_THROW(Hand());
    Hand h{};
    ASSERT_EQ(h.numCards(), 0);
}

TEST(HandTests, TestAddCard)
{
    Hand h{};
    h.addCard(std::make_unique<const Card>(Face::TWO, Suit::CLUBS));
    ASSERT_EQ(h.numCards(), 1);
    h.addCard(std::make_unique<const Card>(Face::THREE, Suit::CLUBS));
    ASSERT_EQ(h.numCards(), 2);
    h.addCard(std::make_unique<const Card>(Face::FOUR, Suit::CLUBS));
    ASSERT_EQ(h.numCards(), 3);
    h.addCard(std::make_unique<const Card>(Face::FIVE, Suit::CLUBS));
    ASSERT_EQ(h.numCards(), 4);
    h.addCard(std::make_unique<const Card>(Face::SIX, Suit::CLUBS));
    ASSERT_EQ(h.numCards(), 5);
    ASSERT_THROW(h.addCard(std::make_unique<const Card>(Face::SIX, Suit::CLUBS)), std::runtime_error);
}

TEST(HandTests, TestRemoveCard)
{
    Hand h{};
    for (size_t i = 0; i < Hand::MAX_CARDS; i+=1)
    {
        ASSERT_THROW(h.removeCard(i), std::invalid_argument);
    }
    ASSERT_THROW(h.removeCard(-1), std::invalid_argument);
    ASSERT_THROW(h.removeCard(5), std::invalid_argument);
    h.addCard(std::make_unique<const Card>(Face::TWO, Suit::CLUBS));
    auto result = h.removeCard(0);
    EXPECT_EQ(result->face, Face::TWO);
    EXPECT_EQ(result->suit, Suit::CLUBS);
}

TEST(HandTests, TestClear)
{
    Hand h{};
    h.addCard(std::make_unique<const Card>(Face::TWO, Suit::CLUBS));
    h.addCard(std::make_unique<const Card>(Face::TWO, Suit::CLUBS));
    h.clear();
    EXPECT_EQ(h.numCards(), 0);
}

TEST(HandTests, TestViewHand)
{
    Hand h{};
    h.addCard(std::make_unique<const Card>(Face::TWO, Suit::CLUBS));
    h.addCard(std::make_unique<const Card>(Face::FIVE, Suit::CLUBS));
    h.addCard(std::make_unique<const Card>(Face::SIX, Suit::CLUBS));
    h.addCard(std::make_unique<const Card>(Face::EIGHT, Suit::CLUBS));
    h.addCard(std::make_unique<const Card>(Face::ACE, Suit::CLUBS));
    auto handView = h.viewCards();
    EXPECT_EQ(handView.at(0).face, Face::TWO);
    EXPECT_EQ(handView.at(0).suit, Suit::CLUBS);
    EXPECT_EQ(handView.at(1).face, Face::FIVE);
    EXPECT_EQ(handView.at(1).suit, Suit::CLUBS);
    EXPECT_EQ(handView.at(2).face, Face::SIX);
    EXPECT_EQ(handView.at(2).suit, Suit::CLUBS);
    EXPECT_EQ(handView.at(3).face, Face::EIGHT);
    EXPECT_EQ(handView.at(3).suit, Suit::CLUBS);
    EXPECT_EQ(handView.at(4).face, Face::ACE);
    EXPECT_EQ(handView.at(4).suit, Suit::CLUBS);
}