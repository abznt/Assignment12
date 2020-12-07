#ifndef ASSIGNMENT12_GAMEOVER_H
#define ASSIGNMENT12_GAMEOVER_H

#include "game/PokerGame.h"
#include "game/states/IState.h"

class GameOver : public IState
{
  private:
    PokerGame* m_game;

  public:
    explicit GameOver(PokerGame* game);
    void processTurn() override;

  private:
    bool queryNewGame(unsigned &newGame);
};

#endif // ASSIGNMENT12_GAMEOVER_H
