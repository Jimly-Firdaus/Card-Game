#ifndef COMPARATOR_HPP
#define COMPARATOR_HPP

#include "Deck.hpp"
#include "Exception.hpp"
#include <map>
using namespace std;

const int MAX_AVAIL_NUMBER = 13;
const int MAX_AVAIL_CHAR = 4;
const int MAX_PLAYER_CARD = 7;

class Comparator
{
public:
    // Constructor
    Comparator();

    // Getter & Setter
    void setIndex();
    void setCombinationType();

    // TODO: complete methods args (missing Deck type)
    /**
     * Get the strongest combination deck
     * @param Deck game cards
     * @param Deck corresponding player cards
     * @return float value of the strongest combination in playerCards
     */
    float getStrongestCombination(Deck gameCard, Deck playerCard);

    /**
     * Get the strongest combination deck
     * @param Deck game cards
     * @param Deck* player cards
     * @return float constant of the strongest combination in arr_of_deck
     */
    float getStrongestCombinationType();

    /**
     * Get the strongest combination deck
     * @param Deck* arr_of_deck
     * @return Comparator object contain index of the strongest combination & combinationConstant
     */
    Comparator compare();

    float searchVal(int number, char type);

    pair<bool, float> isStraightFlush(Deck tableCard, Deck playerCard);
    pair<bool, int> isFourKind(Deck tableCard, Deck playerCard);
    bool isFullHouse(Deck tableCard, Deck playerCard);
    pair<bool, char> isFlush(Deck tableCard, Deck playerCard);
    pair<bool, float> isStraight(Deck tableCard, Deck playerCard);
    pair<bool, float> isStraight(Deck mergedCard);
    pair<bool, float> straightComparator(Deck mergedCard);
    bool isThreeKind(Deck tableCard, Deck playerCard);
    bool isTwoPair(Deck tableCard, Deck playerCard);
    bool isPair(Deck tableCard, Deck playerCard);
    // Just in case this class needs to be extends
protected:
    int index;
    int combinationConstant;

    // look up table for constants
    map<pair<int, char>, float> valueTable;
    char avail_chars[4];
    float baseValue = 0.1;
};

#endif
