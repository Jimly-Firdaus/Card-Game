#ifndef _REVERSEDIRECTION_HPP_
#define _REVERSEDIRECTION_HPP_
#include "Ability.hpp"
#include "GameState/GameState.hpp"

template <class T>
class ReverseDirection : public Ability{
    public:
        void getCardInfo();
        void callCard(GameState&);
};

#endif