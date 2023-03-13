#ifndef _SWAPCARD_HPP_
#define _SWAPCARD_HPP_
#include "Ability.hpp"

class SwapCard : public Ability
{
public:
    void getCardInfo();
    int getCard(string);
    int getInput();
    void swap(Player &, Player &, int, int);
    string getChoice();
    void callCard(Player &, Player &);
};

#endif