#include "game/PokerGame.h"
#include <iostream>

/**
 * @brief Main entry point for the program
 */
int main()
{
    std::cout << "Welcome to the Assignment12 Poker Game!\n";
    PokerGame game{};
    while (game.playing())
    {
        game.processTurn();
    }
    std::cout << "Thank you for playing!\n";
    return 0;
}
