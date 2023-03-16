#ifndef _QUARTER_HPP_
#define _QUARTER_HPP_
#include "Ability.hpp"

class Quarter : public Ability{
    public:
        void getCardInfo();
        void callCard(PlayerCollection& player, GameState& state, Deck& deck, PlayerAction& currentPlayer);
};

#endif