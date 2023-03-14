#ifndef _ABILITYLESS_HPP_
#define _ABILITYLESS_HPP_
#include "Ability.hpp"

class AbilityLess : public Ability
{
public:
    void callCard(PlayerAction&);
    void getCardInfo();
};

#endif