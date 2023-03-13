#ifndef _SWITCH_HPP_
#define _SWITCH_HPP_
#include "Ability.hpp"

template <class T>
class Switch : public Ability{
    public:
        void getCardInfo();
        void callCard(player<T>&, player<T>&) 
};

#endif