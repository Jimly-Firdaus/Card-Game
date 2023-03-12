#ifndef COMPARATOR_HPP
#define COMPARATOR_HPP

#include "Deck.hpp"
#include "Exception.hpp"
#include <map>
using namespace std;

// MAX CARD SETTINGS
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

    /**
     * Give the constant valuation of given number & type (color)
     * @param number 
     * @param type 
     * @return float constant
     */
    float searchVal(int number, char type);
    /**
     * Check whether if current hand + table card is Straight Flush
     * @param tableCard table card (5 total)
     * @param playerCard player hand (2 total)
     * @return pair<bool, float> bool for Straight Flush. If true returns the valuation, else returns 0.0 
     */
    pair<bool, float> isStraightFlush(Deck tableCard, Deck playerCard);
    /**
     * Check whether if current hand + table card is Four of Kind
     * @param tableCard table card (5 total)
     * @param playerCard player hand (2 total)
     * @return pair<bool, int> bool for Four of Kind. If true returns the card number, else returns -1 
     */
    pair<bool, int> isFourKind(Deck tableCard, Deck playerCard);
    bool isFullHouse(Deck tableCard, Deck playerCard);
    /**
     * Check whether if current hand + table card is Flush
     * @param tableCard table card (5 total)
     * @param playerCard player hand (2 total)
     * @return pair<bool, char> bool for Flush. If true returns the card type (color), else returns empty char
     */
    pair<bool, char> isFlush(Deck tableCard, Deck playerCard);
    /**
     * Check whether if current hand + table card is Straight
     * @param tableCard table card (5 total)
     * @param playerCard player hand (2 total)
     * @return pair<bool, float> bool for Straight. If true returns the valuation, else returns 0.0 
     */
    pair<bool, float> isStraight(Deck tableCard, Deck playerCard);
    /**
     * Check whether if current hand + table card is Straight
     * @param mergedCard merged card (7 total)
     * @return pair<bool, float> bool for Straight. If true returns the valuation, else returns 0.0  
     */
    pair<bool, float> isStraight(Deck mergedCard);
    /**
     * Give current hand combination value if current hand + table card is Straight
     * @param mergedCard merged card (7 total)
     * @return pair<bool, float> bool for Straight. If true returns the valuation, else returns 0.0  
     */
    pair<bool, float> straightComparator(Deck mergedCard);
    /**
     * Find the biggest possibly type among the same numbers
     * @param v merged cards
     * @param number given number
     * @return pair<int, char> 
     */
    pair<int, char> findBiggest (vector<pair<int, char>> v, int number);
    /**
     * Merge 2 given Decks
     * @param firstDeck 
     * @param secondDeck 
     * @return vector<pair<int, char>> vector containing 2 merged Decks content 
     */
    vector<pair<int, char>> mergeDeck (Deck firstDeck, Deck secondDeck);
    /**
     * Merge 2 given Decks
     * @param firstDeck 
     * @param secondDeck 
     * @return vector<pair<int, char>> vector containing 2 merged Decks content 
     */
    vector<pair<int, char>> mergeDeck(vector<pair<int, char>> firstDeck, vector<pair<int, char>> secondDeck);
    vector<pair<int, char>> findPair (Deck tableCard, Deck playerCard);
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
