#include "DealingRound.h"
#include "game/states/BettingRound.h"
#include <iostream>

DealingRound::DealingRound(PokerGame *game) : m_game(game)
{
}
void DealingRound::processTurn()
{
    std::cout << "Dealing cards..." << std::endl;
    for (auto &p : m_game->getParticipants())
    {
        m_game->deal(5, p);
    }
    m_game->setState(new BettingRound(m_game, 2));
}

