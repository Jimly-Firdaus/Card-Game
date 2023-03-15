#ifndef _ABILITY_HPP_
#define _ABILITY_HPP_
#include <iostream>
#include <vector>
// #include "../player/player.hpp"
#include "../Exception/Exception.hpp"
#include "../GameState/GameState.hpp"
#include "../Player/playerAction.hpp"
using namespace std;

class Ability{
    public:

        // virtual void callCard() = 0;
        virtual void callCard(vector<PlayerAction>& player, GameState& state, Deck& deck, PlayerAction currentPlayer) = 0;
        /**
         * Getting card information. (pure virtual)
         */
        virtual void getCardInfo() = 0;
};

#endif