#ifndef _REVERSEDIRECTION_HPP_
#define _REVERSEDIRECTION_HPP_
#include "Ability.hpp"
#include "../GameState/GameState.hpp"

class ReverseDirection : public Ability{
    public:
        void getCardInfo() override;
        void callCard(PlayerAction& player, Deck& deck, GameState& state) override;
};

#endif