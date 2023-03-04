#ifndef PLAYERACTION_HPP
#define PLAYERACTION_HPP

#include "player.hpp"

/*Function overriding here
Class: PlayerAction extends dari Player buatKombinasi
Attr: abilityCard
Method: getCombination, (double, next, half, useAbility (pure virtual)) 
*/

class playerAction : public player {
    private:
    char abilityCard;

    public:
    // Getter
    int getCombination();
    

    void nextAction();
    void doubleAction();
    void halfAction();

    virtual void useAbility() = 0; //
};

#endif