#include "GameStart.h"
#include "game/Player.h"
#include "game/Cpu.h"
#include "game/states/BettingRound.h"
#include <iostream>

GameStart::GameStart(PokerGame *game) : m_game(game)
{
}
void GameStart::processTurn()
{
    std::cout << "--------------\n";
    std::cout << "| Game Setup |\n";
    std::cout << "--------------\n";
    size_t numPlayers;
    size_t numCpus;
    unsigned startingMoney;
    unsigned minimumBet;
    while (!queryNumPlayers(numPlayers, numCpus)) {}
    while (!queryStartingMoney(startingMoney)) {}
    while (!queryMinimumBet(minimumBet)) {}
    for (size_t i = 0; i < numPlayers; ++i)
    {
        m_game->addParticipant(std::make_shared<Player>(m_game, i, startingMoney, minimumBet));
    }
    for (size_t i = 0; i < numCpus; ++i)
    {
        m_game->addParticipant(std::make_shared<Cpu>(m_game, i, startingMoney, minimumBet));
    }
    m_game->setState(new BettingRound(m_game, 1));
}
bool GameStart::queryNumPlayers(size_t &numPlayers, size_t &numCpus)
{
    std::cout << "Enter the number of human players: ";
    std::cin >> numPlayers;
    std::cout << "Enter the number of CPU players: ";
    std::cin >> numCpus;
    if (numPlayers < 1)
    {
        std::cout << "There must be at least 1 human player. Please try again.\n";
        return false;
    }
    if (numPlayers + numCpus < PokerGame::MIN_PLAYERS)
    {
        std::cout << "Total number of players is less than the minimum allowed (2). Please try again.\n";
        return false;
    }
    if (numPlayers + numCpus > PokerGame::MAX_PLAYERS)
    {
        std::cout << "Total number of players is greater than the maximum allowed (7). Please try again.\n";
        return false;
    }
    return true;
}
bool GameStart::queryStartingMoney(unsigned int &startingMoney)
{
    std::cout << "Enter the starting amount of money for each participant ($1000 minimum): ";
    std::cin >> startingMoney;
    if (startingMoney < 1000)
    {
        std::cout << "Starting money is less than the minimum allowed ($1000). Please try again.\n";
        return false;
    }
    return true;
}
bool GameStart::queryMinimumBet(unsigned int &minimumBet)
{
    std::cout << "Enter the minimum bet amount ($5 minimum): ";
    std::cin >> minimumBet;
    if (minimumBet < 5)
    {
        std::cout << "Minimum bet amount is less than the minimum allowed ($5). Please try again.\n";
        return false;
    }
    return true;
}
