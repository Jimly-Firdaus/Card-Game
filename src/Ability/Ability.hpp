#ifndef _ABILITY_HPP_
#define _ABILITY_HPP_
#include <iostream>
#include "../player/player.hpp"
#include "../Exception/Exception.hpp"
#include "../GameState/GameState.hpp"

class Ability
{
public:
    /**
     * Call card ability. (pure virtual)
     * @param {player&} user Owner of the card
     * @param {player&} target Target player
     * @param {vector<player>&} playerOrder Player turn order
     * @param {int&} tableReward Current table reward
     * those parameters is written for ability usage completion, it can be used or not according to the need of the program.
     */
    virtual void callCard(GameState) = 0;
    virtual void callCard(Player &, Player &) = 0;
    /**
     * Getting card information. (pure virtual)
     */
    virtual void getCardInfo() = 0;
};

#endif