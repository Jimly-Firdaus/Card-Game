#ifndef _ABILITY_HPP_
#define _ABILITY_HPP_
#include <iostream>

class Ability{
    public:
        virtual void callCard() = 0;
        virtual void cardInfo() = 0;
};

#endif