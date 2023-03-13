#ifndef _ABILITY_HPP_
#define _ABILITY_HPP_
#include <iostream>
#include "player/player.hpp"
#include "lib-header/Exception.hpp"
#include "Deck/Deck.hpp"

class Ability{
    public:
        /**
        * Call card ability. (pure virtual)
        * @param {player&} user Owner of the card
        * @param {player&} target Target player
        * @param {vector<player>&} playerOrder Player turn order
        * @param {int&} tableReward Current table reward
        * those parameters is written for ability usage completion, it can be used or not according to the need of the program.
        */
        virtual void callCard() = 0;
        /**
         * Getting card information. (pure virtual)
         */
        virtual void getCardInfo() = 0;
};

#endif