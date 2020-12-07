#ifndef ASSIGNMENT12_APARTICIPANT_H
#define ASSIGNMENT12_APARTICIPANT_H

#include "framework/Hand.h"
#include "game/PokerGame.h"
#include "game/BettingResult.h"
#include <stdexcept>

class PokerGame;

class AParticipant
{
  protected:
    Hand m_hand;
    unsigned m_money;
    PokerGame *m_game;
    const unsigned m_minBet;

  protected:
    explicit AParticipant(PokerGame *game, unsigned money, unsigned minBet)
        : m_hand{}, m_money{money}, m_game(game), m_minBet{minBet} {};

  public:
    virtual void processAnteRound() = 0;
    virtual BettingResult processBettingRound() = 0;
    virtual void processDrawRound() = 0;
    virtual void processEvaluateRound() = 0;
    virtual void winMessage() = 0;
    Hand &hand()
    {
        return m_hand;
    };
    void addMoney(unsigned amount)
    {
        m_money += amount;
    }
    unsigned removeMoney(unsigned amount)
    {
        if (amount > m_money)
        {
            throw std::runtime_error("Cannot remove money, balance too low.");
        }
        m_money -= amount;
        return amount;
    }
};

#endif // ASSIGNMENT12_APARTICIPANT_H
