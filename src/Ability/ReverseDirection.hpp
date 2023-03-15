#ifndef _REVERSEDIRECTION_HPP_
#define _REVERSEDIRECTION_HPP_
#include "Ability.hpp"
// #include "../GameState/GameState.hpp"
#include <algorithm>
#include <iterator>

class ReverseDirection : public Ability{
    public:
        void getCardInfo() override;
        void callCard(PlayerCollection& player, GameState& state, Deck& deck) override;
};

#endif