#include "Hand.h"
#include <stdexcept>
#include <utility>

size_t Hand::numCards() const
{
    return m_cards.size();
}

bool Hand::full() const
{
    if (m_cards.size() == Hand::MAX_CARDS)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Hand::addCard(Hand::CARD_PTR card)
{
    if (numCards() < Hand::MAX_CARDS)
    {
        m_cards.emplace_back(std::move(card));
    }
    else
    {
        throw std::runtime_error("Cannot add card (hand is full)");
    }
}
Hand::CARD_PTR Hand::removeCard(size_t index)
{
    if (index < numCards())
    {
        if (m_cards.at(index))
        {
            auto tmp = std::move(m_cards.at(index));
            m_cards.erase(m_cards.begin() + index);
            return std::move(tmp);
        }
        else
        {
            throw std::runtime_error("Cannot remove card (no card at index)");
        }
    }
    else
    {
        throw std::invalid_argument("Invalid index (hand size = " + std::to_string(numCards()) + ")");
    }
}
void Hand::clear()
{
    m_cards.clear();
}
std::vector<Card> Hand::viewCards() const
{
    std::vector<Card> cardView{};
    for (auto &card : m_cards)
    {
        cardView.emplace_back(card->face, card->suit);
    }
    return cardView;
}
Card Hand::peekCard(size_t index) const
{
    if (index < numCards())
    {
        if (m_cards.at(index))
        {
            return Card(m_cards.at(index).get());
        }
        else
        {
            throw std::runtime_error("Cannot remove card (no card at index)");
        }
    }
    else
    {
        throw std::invalid_argument("Invalid index (hand size = " + std::to_string(numCards()) + ")");
    }
}
