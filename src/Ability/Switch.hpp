#ifndef _SWITCH_HPP_
#define _SWITCH_HPP_
#include "Ability.hpp"
#include <string>

class Switch : public Ability{
    public:
        void getCardInfo();
        void callCard(vector<PlayerAction>& player, GameState& state, Deck& deck, PlayerAction& currentPlayer);
        string getTarget(vector<PlayerAction>& player, PlayerAction& currentPlayer);
        void printTarget(vector<PlayerAction>& player, PlayerAction& currentPlayer);
};

#endif