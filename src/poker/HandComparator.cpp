#include "HandComparator.h"
int HandComparator::compare(const Hand &hand1, const Hand &hand2, unsigned int (*evaluateFcn)(const Hand &))
{
    unsigned hand1Value = evaluateFcn(hand1);
    unsigned hand2Value = evaluateFcn(hand2);
    if (hand1Value > hand2Value)
    {
        return 1;
    }
    else if (hand2Value > hand1Value)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
