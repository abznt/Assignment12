#ifndef ASSIGNMENT12_DRAWROUND_H
#define ASSIGNMENT12_DRAWROUND_H

#include "game/PokerGame.h"
#include "game/states/IState.h"

class DrawRound : public IState
{
  private:
    PokerGame* m_game;

  public:
    explicit DrawRound(PokerGame* game);
    void processTurn() override;
};

#endif // ASSIGNMENT12_DRAWROUND_H
