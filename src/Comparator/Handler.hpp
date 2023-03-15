#ifndef HANDLER_HPP
#define HANDLER_HPP

#include "../Combination/Combination.hpp"
#include "../Exception/Exception.hpp"

class Handler
{
public:
    // takes array of Combination (if player >= 2 that have the same max combination value)
    // deep compare for each of the player card (using Combination getters)
    /**
     * takes in filtered arr of player card combination
     * @param arrOfPlayerCombination
     * @return pair<string, string> <nickname, combo>
     */
    pair<string, string> deepCompare(vector<Combination> arrOfPlayerCombination); // returns <nickname, combo> that win the round
    /**
     * takes in filtered arr of player card combination if case is straight flush
     * @param arrOfPlayerCombination
     * @return pair<string, string> <nickname, combo>
     */
    pair<string, string> straightFlushHandler(vector<Combination> arrOfPlayerCombination); // returns <nickname, combo> that win straight flush table
    /**
     * takes in filtered arr of player card combination if case is four of kind
     * Prereq : table cards must have four of kind
     * @param arrOfPlayerCombination
     * @return pair<string, string> <nickname, combo>
     */
    pair<string, string> fourKindHandler(vector<Combination> arrOfPlayerCombination);
    /**
     * takes in filtered arr of player card combination if case is full house
     * @param arrOfPlayerCombination
     * @return pair<string, string> <nickname, combo>
     */
    pair<string, string> fullHouseHandler(vector<Combination> arrOfPlayerCombination);
    /**
     * takes in filtered arr of player card combination if case is flush
     * Prereq : table cards must have flush
     * @param arrOfPlayerCombination
     * @return pair<string, string> <nickname, combo>
     */
    pair<string, string> flushHandler(vector<Combination> arrOfPlayerCombination);
    /**
     * takes in filtered arr of player card combination if case is three of kind
     * @param arrOfPlayerCombination
     * @return pair<string, string> <nickname, combo>
     */
    pair<string, string> threeKindHandler(vector<Combination> arrOfPlayerCombination);
    /**
     * takes in filtered arr of player card combination if case is two pair
     * Prereq : table cards must have two pair
     * @param arrOfPlayerCombination
     * @return pair<string, string> <nickname, combo>
     */
    pair<string, string> twoPairHandler(vector<Combination> arrOfPlayerCombination);
    /**
     * takes in filtered arr of player card combination if case is pair
     * Prereq : table cards must have pair
     * @param arrOfPlayerCombination
     * @return pair<string, string> <nickname, combo>
     */
    pair<string, string> pairHandler(vector<Combination> arrOfPlayerCombination);
    /**
     * Find the single card
     * @param arrOfPlayerCombination 
     * @return pair<int, char> 
     */
    pair<int, char> getSingleCard(vector<Combination> arrOfPlayerCombination);
    /**
     * takes in filtered arr of player card combination
     * Returns by finding all possible combination for single card on the table & hand
     * if no single card in table, look for strongest combination on hand
     * @param arrOfPlayerCombination
     * @return pair<string, string> <nickname, combo>
     */
    pair<string, string> getPossibleOfOne(vector<Combination> arrOfPlayerCombination);
    /**
     * Takes in player combination and compare the combination value
     * @return * pair<string, string> winner
     */
    virtual pair<string, string> compare(const vector<Combination>&) = 0;

};

#endif