#ifndef ASSIGNMENT12_CPU_H
#define ASSIGNMENT12_CPU_H

#include "game/AParticipant.h"

class Cpu : public AParticipant
{
  public:
    const size_t m_cpuNum;

  public:
    explicit Cpu(PokerGame *game, size_t cpuNum, unsigned money, unsigned minBet);
    void processAnteRound() override;
    BettingResult processBettingRound() override;
    void processDrawRound() override;
    void processEvaluateRound() override;
    void winMessage() override;
};

#endif // ASSIGNMENT12_CPU_H
