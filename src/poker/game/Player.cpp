#include "Player.h"
Player::Player(PokerGame *game, size_t playerNum, unsigned money, unsigned minBet)
    : AParticipant(game, money, minBet), m_playerNum(playerNum)
{
}
void Player::processAnteRound()
{
    std::cout << "Player " << m_playerNum << " bet $" << m_minBet << std::endl;
    m_game->addToPot(removeMoney(m_minBet));
}
BettingResult Player::processBettingRound()
{
    std::cout << "Player " << m_playerNum << "'s turn..." << std::endl;
    std::cout << "Current pot amount: " << m_game->getPot() << std::endl;
    std::cout << "Current bet amount: " << m_game->getCurBet() << std::endl;
    std::cout << "Current money: $" << m_money << std::endl;
    std::cout << "Hand: " << m_hand << std::endl;
    unsigned option;
    while(!queryOption(option)) {}
    switch (option)
    {
    case 0:
        std::cout << "Player " << m_playerNum << " checked" << std::endl;
        m_game->addToPot(removeMoney(m_game->getCurBet()));
        return BettingResult::CHECK;
    case 1:
        unsigned bet;
        while(!queryBet(bet)) {}
        std::cout << "Player " << m_playerNum << " opened with a bet of $" << bet << std::endl;
        m_game->addToPot(removeMoney(bet));
        m_game->setCurBet(bet);
        m_game->getBettingOptions().open();
        return BettingResult::BET;
    case 2:
        std::cout << "Player " << m_playerNum << " folded" << std::endl;
        return BettingResult::FOLD;
    case 3:
        unsigned bet1;
        while(!queryBet(bet1)) {}
        std::cout << "Player " << m_playerNum << " raised the bet to $" << bet1 << std::endl;
        m_game->addToPot(removeMoney(bet1));
        m_game->setCurBet(bet1);
        return BettingResult::BET;
    default:
        throw std::runtime_error("Unhandled betting option");
    }
}
void Player::processDrawRound()
{
    std::cout << "Player " << m_playerNum << "'s turn..." << std::endl;
    std::cout << "Hand: " << m_hand << std::endl;
    unsigned numCards;
    while(!queryReplaceCards(numCards)) {}
    if (numCards > 0)
    {
        for (unsigned i = 0; i < numCards; ++i)
        {
            while (!queryReplacementCard());
        }
        m_game->deal(numCards, this);
    }
    std::cout << "New hand: " << m_hand << std::endl;
}
void Player::processEvaluateRound()
{
    std::cout << "Player " << m_playerNum << "'s hand: " << m_hand << std::endl;
}
void Player::winMessage()
{
    std::cout << "Player " << m_playerNum << " won!" << std::endl;
}
bool Player::queryOption(unsigned int &option)
{
    BettingOptions b = m_game->getBettingOptions();
    std::cout << b << std::endl;
    std::cin >> option;
    if (!b.isValidOption(option))
    {
        std::cout << "Invalid option selected. Try again." << std::endl;
        return false;
    }
    return true;
}
bool Player::queryBet(unsigned int &bet)
{
    std::cout << "How much would you like to bet? " << std::endl;
    std::cin >> bet;
    if (bet > m_money)
    {
        std::cout << "Invalid bet amount, not enough money. Try again." << std::endl;
        return false;
    }
    if (bet <= m_game->getCurBet())
    {
        std::cout << "Invalid bet amount, not greater than the current bet. Try again." << std::endl;
        return false;
    }
    return true;
}
bool Player::queryReplaceCards(unsigned int &numCards)
{
    std::cout << "How many cards would you like to replace? (enter and integer number between 0 and 3): ";
    std::cin >> numCards;
    if (numCards > 3)
    {
        std::cout << "Invalid number of cards. Try again." << std::endl;
        return false;
    }
    return true;
}
bool Player::queryReplacementCard()
{
    std::cout << "Hand: " << m_hand << std::endl;
    std::cout << "Enter the index of the card you would like to replace: ";
    unsigned cardIndex;
    std::cin >> cardIndex;
    if (cardIndex >= m_hand.numCards())
    {
        std::cout << "Invalid index. Try again." << std::endl;
        return false;
    }
    m_hand.removeCard(cardIndex);
    return true;
}
