#ifndef ASSIGNMENT12_POKERGAME_H
#define ASSIGNMENT12_POKERGAME_H

#include "framework/Deck.h"
#include "game/AParticipant.h"
#include "game/states/IState.h"
#include "game/BettingOptions.h"
#include <memory>
#include <vector>

class AParticipant;

class PokerGame
{
  public:
    static constexpr size_t MAX_PLAYERS = 7;
    static constexpr size_t MIN_PLAYERS = 2;

  private:
    bool m_playing;
    IState* m_state;
    std::vector<std::shared_ptr<AParticipant>> m_participants;
    std::vector<std::shared_ptr<AParticipant>> m_curParticipants;
    Deck m_deck;
    BettingOptions m_bettingOptions;

    unsigned m_pot;
    unsigned m_curBet;

  public:
    PokerGame();
    void addParticipant(std::shared_ptr<AParticipant> p);
    void processTurn();
    void setState(IState* state);
    [[nodiscard]] bool playing() const;
    std::vector<std::shared_ptr<AParticipant>> getParticipants();
    std::vector<std::shared_ptr<AParticipant>> getCurParticipants();
    bool removeCurParticipant(std::shared_ptr<AParticipant> p);
    void deal(size_t numCards, std::shared_ptr<AParticipant> p);
    void deal(size_t numCards, AParticipant* p);
    void newRound();
    void addToPot(unsigned amount);
    [[nodiscard]] unsigned flushPot();
    [[nodiscard]] unsigned getPot() const;
    [[nodiscard]] unsigned getCurBet() const
    {
        return m_curBet;
    }
    void setCurBet(unsigned amount)
    {
        m_curBet = amount;
    }
    BettingOptions &getBettingOptions()
    {
        return m_bettingOptions;
    }
    void endGame()
    {
        m_playing = false;
    }
};

#endif // ASSIGNMENT12_POKERGAME_H
