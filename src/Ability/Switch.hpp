#ifndef _SWITCH_HPP_
#define _SWITCH_HPP_
#include "Ability.hpp"
#include <string>

class Switch : public Ability{
    public:
        void getCardInfo();
        void callCard(PlayerCollection& player, GameState& state, Deck& deck);
        string getTarget(PlayerCollection& player);
        void printTarget(PlayerCollection& player);
};

#endif