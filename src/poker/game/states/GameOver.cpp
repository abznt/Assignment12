#include "GameOver.h"
#include "game/states/BettingRound.h"

GameOver::GameOver(PokerGame *game) : m_game(game)
{
}
void GameOver::processTurn()
{
    unsigned newGame;
    while(!queryNewGame(newGame)) {}
    switch (newGame)
    {
    case 0:
        m_game->endGame();
        break;
    case 1:
        std::cout << "Starting a new round..." << std::endl;
        m_game->newRound();
        m_game->setState(new BettingRound(m_game, 1));
        break;
    default:
        throw std::runtime_error("Invalid case detected");
    }
}
bool GameOver::queryNewGame(unsigned int &newGame)
{
    std::cout << "Would you like to play another round? ([0] no [1] yes)" << std::endl;
    std::cin >> newGame;
    if (newGame > 1)
    {
        std::cout << "Invalid option selected. Try again." << std::endl;
        return false;
    }
    return true;
}
