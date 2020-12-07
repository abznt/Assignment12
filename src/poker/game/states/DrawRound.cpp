#include "DrawRound.h"
#include "BettingRound.h"

DrawRound::DrawRound(PokerGame *game) : m_game(game)
{
}
void DrawRound::processTurn()
{
    std::cout << "Draw round..." << std::endl;
    for (auto &p : m_game->getCurParticipants())
    {
        p->processDrawRound();
    }
    m_game->setState(new BettingRound(m_game, 3));
}
