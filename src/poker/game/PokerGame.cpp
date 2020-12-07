#include "PokerGame.h"
#include "game/states/GameStart.h"
#include <stdexcept>

PokerGame::PokerGame()
    : m_state(new GameStart(this)), m_deck{}, m_playing{true}, m_pot{0}, m_curBet{0}, m_bettingOptions{}
{
    m_deck.shuffle();
}
void PokerGame::addParticipant(std::shared_ptr<AParticipant> p)
{
    if (m_participants.size() < PokerGame::MAX_PLAYERS)
    {
        m_participants.emplace_back(p);
        m_curParticipants.emplace_back(p);
    }
    else
    {
        throw std::runtime_error("Game full, cannot add participant");
    }
}
void PokerGame::processTurn()
{
    m_state->processTurn();
}
void PokerGame::setState(IState *state)
{
    m_state = state;
}
bool PokerGame::playing() const
{
    return m_playing;
}
std::vector<std::shared_ptr<AParticipant>> PokerGame::getParticipants()
{
    return m_participants;
}
std::vector<std::shared_ptr<AParticipant>> PokerGame::getCurParticipants()
{
    return m_curParticipants;
}
bool PokerGame::removeCurParticipant(std::shared_ptr<AParticipant> p)
{
    auto result = std::find(m_curParticipants.begin(), m_curParticipants.end(), p);
    if (result != m_curParticipants.end())
    {
        m_curParticipants.erase(result);
        return true;
    }
    else
    {
        return false;
    }
}
void PokerGame::deal(size_t numCards, std::shared_ptr<AParticipant> p)
{
    for (size_t i = 0; i < numCards; ++i)
    {
        p->hand().addCard(std::move(m_deck.removeTopCard()));
    }
}
void PokerGame::deal(size_t numCards, AParticipant *p)
{
    for (size_t i = 0; i < numCards; ++i)
    {
        p->hand().addCard(std::move(m_deck.removeTopCard()));
    }
}
void PokerGame::newRound()
{
    m_deck.reset();
    m_deck.shuffle();
    m_curParticipants.clear();
    for (auto &p : m_participants)
    {
        p->hand().clear();
        m_curParticipants.emplace_back(p);
    }
    m_pot = 0;
    m_curBet = 0;
}
void PokerGame::addToPot(unsigned int amount)
{
    m_pot += amount;
}
unsigned PokerGame::getPot() const
{
    return m_pot;
}
[[maybe_unused]] unsigned PokerGame::flushPot()
{
    unsigned amount = m_pot;
    m_pot = 0;
    return amount;
}
