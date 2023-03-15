#ifndef _ABILITYLESS_HPP_
#define _ABILITYLESS_HPP_
#include "Ability.hpp"

class AbilityLess : public Ability
{
public:
    void callCard(PlayerCollection& player, GameState& state, Deck& deck);
    void getCardInfo();
    void setCardOff(PlayerAction& chosenPlayer);
    string getInput(PlayerCollection& player);
    void printTarget(PlayerCollection& player);
};

#endif