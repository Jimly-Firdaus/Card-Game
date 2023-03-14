#ifndef COMBINATION_HPP
#define COMBINATION_HPP

#include "../Deck/Deck.hpp"
#include "../Exception/Exception.hpp"
#include <map>
using namespace std;

// MAX CARD SETTINGS
const int MAX_AVAIL_NUMBER = 13;
const int MAX_AVAIL_CHAR = 4;
const int MAX_PLAYER_CARD = 7;

// COMBO CARD EXTRA POINTS
const double PAIR_POINT = 1.39;
const double TWO_PAIR_POINT = 4.17;
const double THREEKIND_POINT = 9.53;
const double STRAIGHT_POINT = 13.7;
const double FLUSH_POINT = 19.65;
const double FULLHOUSE_POINT = 25.6;
const double FOURKIND_POINT = 31.55;
const double STRAIGHTFLUSH_POINT = 37.11;

class Combination
{
public:
    // Constructor
    Combination(Deck tableCard, Deck playerCard, string nickname);
    Combination(const Combination& other);
    Combination& operator=(const Combination& other);
    // Getter
    Deck getPlayerCard() const; // return current player card
    Deck getTableCard() const; // return table card
    string getOwnerCard() const;
    /**
     * Get the strongest combination deck
     * @return float value of the strongest combination in playerCards
     */
    pair<float, string> getStrongestCombination();
    /**
     * Compare function for sorting lambda function
     * @param p1
     * @param p2
     * @return true if comparison right
     * @return false otherwise
     */
    virtual bool compare(const pair<int, char> &p1, const pair<int, char> &p2);
    /**
     * Give the constant valuation of given number & type (color)
     * @param number
     * @param type
     * @return float constant
     */
    float searchVal(int number, char type) const;
    /**
     * Give the constant valuation of given number & type (color)
     * @param card card in vector
     * @return float constant
     */
    float searchVal(pair<int, char> card) const;
    /**
     * Check whether if current hand + table card is Straight Flush
     * @return pair<bool, float> bool for Straight Flush. If true returns the valuation, else returns 0.0
     */
    pair<bool, float> isStraightFlush();
    /**
     * Check whether if current hand + table card is Four of Kind
     * @return pair<bool, int> bool for Four of Kind. If true returns the card number, else returns -1
     */
    pair<bool, int> isFourKind();
    /**
     * Check whether if current hand + table card is Full House
     * @return * pair<bool, int> bool for Full House. If true returns the card number, else returns -1
     */
    pair<bool, int> isFullHouse();
    /**
     * Check whether if current hand + table card is Flush
     * @return pair<bool, pair<int, char>> bool for Flush. If true returns card, else returns empty card (0, ' ')
     */
    pair<bool, pair<int, char>> isFlush();
    /**
     * Check whether if current hand + table card is Straight
     * @return pair<bool, float> bool for Straight. If true returns the valuation, else returns 0.0
     */
    pair<bool, float> isStraight();
    /**
     * Give current hand combination value if current hand + table card is Straight
     * @param mergedCard merged card (7 total)
     * @return pair<bool, float> bool for Straight. If true returns the valuation, else returns 0.0
     */
    pair<bool, float> straightCombination(Deck mergedDeck);
    /**
     * Find the biggest possibly type among the same numbers
     * @param v merged cards
     * @param number given number
     * @return pair<int, char>
     */
    pair<int, char> findBiggest(vector<pair<int, char>> v, int number);
    /**
     * Merge 2 given Decks
     * @param firstDeck
     * @param secondDeck
     * @return vector<pair<int, char>> vector containing 2 merged Decks content
     */
    vector<pair<int, char>> mergeDeck(Deck firstDeck, Deck secondDeck);
    /**
     * Merge 2 given Decks
     * @param firstDeck
     * @param secondDeck
     * @return vector<pair<int, char>> vector containing 2 merged Decks content
     */
    vector<pair<int, char>> mergeDeck(vector<pair<int, char>> firstDeck, vector<pair<int, char>> secondDeck);
    /**
     * Find all pair in hand + table decks
     * @return * vector<pair<int, char>> vector containing all pairs from given decks
     */
    vector<pair<int, char>> findPair();
    /**
     * Receive sorted merged deck and find all numbers that appear more than once
     * @param mergedDeck
     * @return * vector<pair<int, char>> multiset
     */
    vector<pair<int, char>> getNonSingle(Deck mergedDeck);
    /**
     * Check whether if current hand + table card is Three of Kind
     * @return * pair<bool, int> bool for Three of Kind. If true returns the card number, else returns -1
     */
    pair<bool, int> isThreeKind();
    /**
     * Check whether if current hand + table card is Two Pair
     * @param tableCard
     * @param playerCard
     * @return * pair<bool, int> bool for Two Pair. If true returns the Two Pair, else returns empty array
     */
    pair<bool, vector<pair<int, char>>> isTwoPair();
    /**
     * Check whether if current hand + table card is Pair
     * @return * pair<bool, int> bool for Pair. If true returns the valuation, else returns -1
     */
    pair<bool, float> isPair();
    /**
     * Get the highest card from given decks
     * @return pair<int, char> highest card
     */
    pair<int, char> getHighCard();
    /**
     * Sort the given deck in ascending order
     * @param mergedDeck
     * @return * vector<pair<int, char>> sorted deck
     */
    vector<pair<int, char>> sortDeck(Deck mergedDeck);
    /**
     * Sort the given deck in ascending order
     * @param mergedDeck
     * @return * vector<pair<int, char>> sorted deck
     */
    vector<pair<int, char>> sortDeck(vector<pair<int, char>> mergedDeck);
    // Operator overloads
    bool operator<(Combination &other);
    bool operator>(Combination &other);
    bool operator==(Combination &other);

private:
    string cardOwner;
    Deck tableCard, playerCard;
    // look up table for constants
    map<pair<int, char>, float> valueTable;
    map<char, int> color;
    char avail_chars[4];
    float baseValue = 0.1;
};

#endif
