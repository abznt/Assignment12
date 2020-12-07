#include "EvaluateRound.h"
#include "framework/HandEvaluator.h"
#include "game/states/GameOver.h"

EvaluateRound::EvaluateRound(PokerGame *game) : m_game(game)
{
}
void EvaluateRound::processTurn()
{
    std::cout << "Evaluating hands..." << std::endl;
    unsigned maxScore = 0;
    std::shared_ptr<AParticipant> winner = nullptr;
    for (auto &p : m_game->getCurParticipants())
    {
        p->processEvaluateRound();
        unsigned score = HandEvaluator::evaluate(p->hand());
        if (score > maxScore)
        {
            maxScore = score;
            winner = p;
        }
    }
    winner->winMessage();
    winner->addMoney(m_game->flushPot());
    m_game->setState(new GameOver(m_game));
}
