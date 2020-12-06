#include "framework/Card.h"
#include <iostream>

/**
 * @brief Main entry point for the program
 */
int main()
{
    Card card{Face::FIVE, Suit::SPADES};
    std::cout << "Card: " << card;
    return 0;
}
