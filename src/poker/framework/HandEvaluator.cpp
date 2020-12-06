#include "HandEvaluator.h"
#include "Card.h"
#include "CardConversions.h"
#include <algorithm>
#include <array>
#include <stdexcept>
#include <vector>

unsigned HandEvaluator::evaluate(const Hand &hand)
{
    if (!hand.full())
    {
        throw std::runtime_error("Cannot evaluate a hand that isn't full");
    }
    std::vector<Card> cards = hand.viewCards();
    // Count the occurrences of each card rank
    std::array<int, 13> countByRank{0};
    for (const auto& card : cards)
    {
        countByRank[CardConversions::faceToIndexMap.at(card.face)]++;
    }
    // Test for the various hand types
    std::array<int, 5> straight{1, 1, 1, 1, 1};
    bool isFlush = (cards[0].suit == cards[1].suit) &&
                   (cards[1].suit == cards[2].suit) &&
                   (cards[2].suit == cards[3].suit) &&
                   (cards[3].suit == cards[4].suit);
    auto isStraight = std::search(countByRank.begin(), countByRank.end(), straight.begin(), straight.end());
    auto isFourOfKind = std::find(countByRank.begin(), countByRank.end(), 4);
    auto isTriple = std::find(countByRank.begin(), countByRank.end(), 3);
    auto firstPair = std::find(countByRank.begin(), countByRank.end(), 2);
    std::array<int, 13>::iterator secondPair;
    if (firstPair != countByRank.end()) {
        secondPair = std::find(firstPair + 1, countByRank.end(), 2);
    }
    else {
        secondPair = countByRank.end();
    }
    // Evaluate the hand type and score it
    if ((isStraight != countByRank.end()) && isFlush) {
        // Straight flush
        unsigned int handValue = 8;
        for (int i = countByRank.size() - 1; i >= 0; --i) {
            if (countByRank.at(i) == 1) {
                handValue = (handValue << 4) + i;
            }
        }
        return handValue;
    }
    else if (isFourOfKind != countByRank.end()) {
        // Four of a kind
        unsigned int handValue = 7;
        int fourIndex = int(isFourOfKind - countByRank.begin());
        for (int i = 0; i < 4; ++i) { handValue = (handValue << 4) + fourIndex; }
        for (int i = countByRank.size() - 1; i >= 0; --i) {
            if (countByRank.at(i) == 1) {
                handValue = (handValue << 4) + i;
            }
        }
        return handValue;
    }
    else if ((isTriple != countByRank.end()) && (firstPair != countByRank.end())) {
        // Full house
        unsigned int handValue = 6;
        int tripleIndex = int(isTriple - countByRank.begin());
        int pairIndex = int(firstPair - countByRank.begin());
        for (int i = 0; i < 3; ++i){ handValue = (handValue << 4) + tripleIndex; }
        for (int i = 0; i < 2; ++i){ handValue = (handValue << 4) + pairIndex; }
        return handValue;
    }
    else if (isFlush) {
        // Flush
        unsigned int handValue = 5;
        for (int i = countByRank.size() - 1; i >= 0; --i) {
            if (countByRank.at(i) == 1) {
                handValue = (handValue << 4) + i;
            }
        }
        return handValue;
    }
    else if (isStraight != countByRank.end()) {
        // Straight
        unsigned int handValue = 4;
        for (int i = countByRank.size() - 1; i >= 0; --i) {
            if (countByRank.at(i) == 1) {
                handValue = (handValue << 4) + i;
            }
        }
        return handValue;
    }
    else if (isTriple != countByRank.end()) {
        // Three of a kind
        unsigned int handValue = 3;
        int tripleIndex = int(isTriple - countByRank.begin());
        for (int i = 0; i < 3; ++i){ handValue = (handValue << 4) + tripleIndex; }
        for (int i = countByRank.size() - 1; i >= 0; --i) {
            if (countByRank.at(i) == 1) {
                handValue = (handValue << 4) + i;
            }
        }
        return handValue;
    }
    else if ((firstPair != countByRank.end()) && (secondPair != countByRank.end())) {
        // Two pair
        unsigned int handValue = 2;
        int pair1Index = int(firstPair - countByRank.begin());
        int pair2Index = int(secondPair - countByRank.begin());
        for (int i = 0; i < 2; ++i) { handValue = (handValue << 4) + pair2Index; }
        for (int i = 0; i < 2; ++i) { handValue = (handValue << 4) + pair1Index; }
        for (int i = countByRank.size() - 1; i >= 0; --i) {
            if (countByRank.at(i) == 1) {
                handValue = (handValue << 4) + i;
            }
        }
        return handValue;
    }
    else if (firstPair != countByRank.end()) {
        // One pair
        unsigned int handValue = 1;
        int pairIndex = int(firstPair - countByRank.begin());
        for (int i = 0; i < 2; ++i) { handValue = (handValue << 4) + pairIndex; }
        for (int i = countByRank.size() - 1; i >= 0; --i) {
            if (countByRank.at(i) == 1) {
                handValue = (handValue << 4) + i;
            }
        }
        return handValue;
    }
    else {
        // High card
        unsigned int handValue = 0;
        for (int i = countByRank.size() - 1; i >= 0; --i) {
            if (countByRank.at(i) == 1) {
                handValue = (handValue << 4) + i;
            }
        }
        return handValue;
    }
}
