#ifndef ASSIGNMENT12_EVALUATEROUND_H
#define ASSIGNMENT12_EVALUATEROUND_H

#include "game/PokerGame.h"
#include "game/states/IState.h"

class EvaluateRound : public IState
{
  private:
    PokerGame* m_game;

  public:
    explicit EvaluateRound(PokerGame* game);
    void processTurn() override;
};

#endif // ASSIGNMENT12_EVALUATEROUND_H
