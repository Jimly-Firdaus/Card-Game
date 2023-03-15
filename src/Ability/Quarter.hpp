#ifndef _QUARTER_HPP_
#define _QUARTER_HPP_
#include "Ability.hpp"

class Quarter : public Ability{
    public:
        void getCardInfo() override;
        void callCard(PlayerAction& player, Deck& deck, GameState& state) override;
};

#endif