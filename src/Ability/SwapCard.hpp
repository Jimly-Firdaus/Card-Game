#ifndef _SWAPCARD_HPP_
#define _SWAPCARD_HPP_
#include "Ability.hpp"
#include "../Exception/Exception.hpp"

class SwapCard : public Ability{
    public:
        void getCardInfo();
        int getCard(string);
        int getInput();
        string getChoice();
        string getTarget(PlayerCollection& player, PlayerAction& currentPlayer);
        void callCard(PlayerCollection& player, GameState& state, Deck& deck, PlayerAction& currentPlayer);
        void printTarget(PlayerCollection& player, PlayerAction& currentPlayer);
};

#endif