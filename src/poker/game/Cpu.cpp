#include "Cpu.h"
#include <iostream>

Cpu::Cpu(PokerGame *game, size_t cpuNum, unsigned money, unsigned minBet)
    : AParticipant(game, money, minBet), m_cpuNum(cpuNum)
{
}
BettingResult Cpu::processBettingRound()
{
    std::cout << "CPU " << m_cpuNum << "'s turn..." << std::endl;
    return BettingResult::CHECK;
}
void Cpu::processDrawRound()
{
}
void Cpu::processAnteRound()
{
    std::cout << "CPU " << m_cpuNum << " bet $" << m_minBet << std::endl;
    m_game->addToPot(removeMoney(m_minBet));
}
void Cpu::processEvaluateRound()
{
    std::cout << "CPU " << m_cpuNum << "'s hand: " << m_hand << std::endl;
}
void Cpu::winMessage()
{
    std::cout << "CPU " << m_cpuNum << " won!" << std::endl;
}
