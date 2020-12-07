#ifndef ASSIGNMENT12_BETTINGROUND_H
#define ASSIGNMENT12_BETTINGROUND_H

#include "game/states/IState.h"
#include "game/PokerGame.h"
#include "game/AParticipant.h"
#include <queue>

class BettingRound : public IState
{
  private:
    PokerGame* m_game;
    unsigned m_round;
    std::vector<std::shared_ptr<AParticipant>> m_removeList;

  public:
    explicit BettingRound(PokerGame *game, unsigned round);
    void processTurn() override;

  private:
    void processBets(std::queue<std::shared_ptr<AParticipant>> bettingQueue);
    void removeParticipants();
};

#endif // ASSIGNMENT12_BETTINGROUND_H
