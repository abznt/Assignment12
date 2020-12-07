#ifndef ASSIGNMENT12_PLAYER_H
#define ASSIGNMENT12_PLAYER_H

#include "game/AParticipant.h"

class Player : public AParticipant
{
  public:
    const size_t m_playerNum;

  public:
    explicit Player(PokerGame *game, size_t playerNum, unsigned money, unsigned minBet);
    void processAnteRound() override;
    BettingResult processBettingRound() override;
    void processDrawRound() override;
    void processEvaluateRound() override;
    void winMessage() override;

  private:
    bool queryOption(unsigned &option);
    bool queryBet(unsigned &bet);
    bool queryReplaceCards(unsigned &numCards);
    bool queryReplacementCard();
};

#endif // ASSIGNMENT12_PLAYER_H
