#ifndef _SWAPCARD_HPP_
#define _SWAPCARD_HPP_
#include "Ability.hpp"

class SwapCard : public Ability{
    public:
        void getCardInfo();
        void callCard();
};

#endif