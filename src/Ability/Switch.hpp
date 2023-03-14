#ifndef _SWITCH_HPP_
#define _SWITCH_HPP_
#include "Ability.hpp"

class Switch : public Ability{
    public:
        void getCardInfo();
        void callCard(player&, player&);
};

#endif