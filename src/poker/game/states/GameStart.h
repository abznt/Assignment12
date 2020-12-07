#ifndef ASSIGNMENT12_GAMESTART_H
#define ASSIGNMENT12_GAMESTART_H

#include "game/PokerGame.h"
#include "game/states/IState.h"

class GameStart : public IState
{
  private:
    PokerGame* m_game;

  public:
    explicit GameStart(PokerGame *game);
    void processTurn() override;

  private:
    bool queryNumPlayers(size_t& numPlayers, size_t& numCpus);
    bool queryStartingMoney(unsigned& startingMoney);
    bool queryMinimumBet(unsigned& minimumBet);
};

#endif // ASSIGNMENT12_GAMESTART_H
