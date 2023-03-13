#ifndef _QUADRUPLE_HPP_
#define _QUADRUPLE_HPP_
#include "Ability.hpp"

class Quadruple : public Ability{
    public:
        void getCardInfo();
        void callCard(GameState);
};

#endif