#ifndef _REROLL_HPP_
#define _REROLL_HPP_
#include "Ability.hpp"

template <class T>
class Reroll : public Ability{
    public:
        void getCardInfo();
        void callCard();
};

#endif