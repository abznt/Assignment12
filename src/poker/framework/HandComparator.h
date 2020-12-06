#ifndef ASSIGNMENT12_HANDCOMPARATOR_H
#define ASSIGNMENT12_HANDCOMPARATOR_H

#include "Hand.h"
#include "HandEvaluator.h"

struct HandComparator
{
    static int compare(const Hand &hand1, const Hand &hand2,
                       unsigned (*evaluateFcn)(const Hand &) = HandEvaluator::evaluate);
};

#endif // ASSIGNMENT12_HANDCOMPARATOR_H
