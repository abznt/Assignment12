#ifndef ASSIGNMENT12_DEALINGROUND_H
#define ASSIGNMENT12_DEALINGROUND_H

#include "game/states/IState.h"
#include "game/PokerGame.h"

class DealingRound : public IState
{
  private:
    PokerGame* m_game;

  public:
    explicit DealingRound(PokerGame* game);
    void processTurn() override;
};

#endif // ASSIGNMENT12_DEALINGROUND_H
