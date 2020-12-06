#include "Deck.h"
#include <stdexcept>

const std::vector<Face> Deck::faces{Face::TWO,   Face::THREE, Face::FOUR, Face::FIVE, Face::SIX,
                                      Face::SEVEN, Face::EIGHT, Face::NINE, Face::TEN,  Face::JACK,
                                      Face::QUEEN, Face::KING,  Face::ACE};

const std::vector<Suit> Deck::suits{Suit::CLUBS, Suit::SPADES, Suit::DIAMONDS, Suit::HEARTS};

Deck::Deck()
{
    std::random_device rd;
    m_rng.seed(rd());
    fillDeck();
}

void Deck::shuffle()
{
    if (!m_cards.empty())
    {
        size_t nCards = m_cards.size();
        for (size_t i = 0; i < nCards; ++i)
        {
            std::uniform_int_distribution<> dist(i, nCards - 1);
            int j = dist(m_rng);
            std::iter_swap(m_cards.begin() + i, m_cards.begin() + j);
        }
    }
    else
    {
        throw std::runtime_error("Cannot call shuffle() on an empty deck");
    }
}

Card Deck::peekTopCard() const
{
    if (!empty())
    {
        return Card(m_cards.back().get());
    }
    else
    {
        throw std::runtime_error("Deck is empty");
    }
}

std::unique_ptr<const Card> Deck::removeTopCard()
{
    if (!empty())
    {
        auto tmpCard = std::move(m_cards.back());
        m_cards.pop_back();
        return std::move(tmpCard);
    }
    else
    {
        throw std::runtime_error("Cannot call removeTopCard() on an empty deck");
    }
}

void Deck::fillDeck()
{
    for (auto &suit : suits)
    {
        for (auto &face : faces)
        {
            m_cards.emplace_back(std::make_unique<const Card>(face, suit));
        }
    }
}
