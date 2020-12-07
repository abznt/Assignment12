#include "BettingRound.h"
#include "game/states/DealingRound.h"
#include "game/states/DrawRound.h"
#include "game/states/EvaluateRound.h"
#include "game/BettingResult.h"
#include <stdexcept>
#include <queue>

BettingRound::BettingRound(PokerGame *game, unsigned round) : m_game(game), m_round(round), m_removeList()
{
}
void BettingRound::processTurn()
{
    std::queue<std::shared_ptr<AParticipant>> bettingQueue;
    // Fill the betting queue with the game's current participants
    for (auto &p : m_game->getCurParticipants())
    {
        bettingQueue.push(p);
    }
    switch (m_round)
    {
    case 1:
        std::cout << "Betting round 1..." << std::endl;
        while (!bettingQueue.empty())
        {
            auto p = bettingQueue.front();
            bettingQueue.pop();
            p->processAnteRound();
        }
        m_game->setState(new DealingRound(m_game));
        break;
    case 2:
        std::cout << "Betting round 2..." << std::endl;
        processBets(bettingQueue);
        m_game->setState(new DrawRound(m_game));
        break;
    case 3:
        std::cout << "Betting round 3..." << std::endl;
        processBets(bettingQueue);
        m_game->setState(new EvaluateRound(m_game));
        break;
    default:
        throw std::runtime_error("Unhandled betting round number");
    }
}
void BettingRound::processBets(std::queue<std::shared_ptr<AParticipant>> bettingQueue)
{
    std::queue<std::shared_ptr<AParticipant>> bettingHistory;
    while (!bettingQueue.empty())
    {
        auto p = bettingQueue.front();
        bettingQueue.pop();
        BettingResult result = p->processBettingRound();
        switch (result)
        {
        case BettingResult::CHECK:
            bettingHistory.push(p);
            break;
        case BettingResult::BET:
            while (!bettingHistory.empty())
            {
                auto ph = bettingHistory.front();
                bettingHistory.pop();
                bettingQueue.push(ph);
            }
            bettingHistory.push(p);
            break;
        case BettingResult::FOLD:
            m_removeList.emplace_back(p);
            break;
        }
        removeParticipants();
    }
    m_game->getBettingOptions().reset();
    m_game->setCurBet(0);
}
void BettingRound::removeParticipants()
{
    for (auto &p : m_removeList)
    {
        m_game->removeCurParticipant(p);
    }
}
