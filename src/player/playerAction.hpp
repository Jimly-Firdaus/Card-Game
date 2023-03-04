#ifndef PLAYERACTION_HPP
#define PLAYERACTION_HPP

/*Function overriding here
Class: PlayerAction extends dari Player buatKombinasi
Attr: abilityCard
Method: getCombination, (double, next, half, useAbility (pure virtual)) 
*/

class player {
    private:
    char abilityCard;

    public:
    int getCombination(); //
    
    void nextAction(); //
    void doubleAction(); //
    void halfAction(); //

    virtual void useAbility() = 0; //
};

#endif