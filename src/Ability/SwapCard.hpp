#ifndef _SWAPCARD_HPP_
#define _SWAPCARD_HPP_
#include "Ability.hpp"

class SwapCard : public Ability{
    public:
        void getCardInfo();
        int getCard(string);
        int getInput();
        string getChoice();
        string getTarget(PlayerCollection& player);
        void callCard(PlayerCollection& player, GameState& state, Deck& deck);
        void printTarget(PlayerCollection& player);
};

#endif