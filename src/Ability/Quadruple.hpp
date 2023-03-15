#ifndef _QUADRUPLE_HPP_
#define _QUADRUPLE_HPP_
#include "Ability.hpp"

class Quadruple : public Ability{
    public:
        void getCardInfo() override;
        void callCard(PlayerCollection& player, GameState& state, Deck& deck) override;
};

#endif