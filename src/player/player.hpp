#ifndef PLAYER_HPP
#define PLAYER_HPP

/*Class: Player : Kartu yang dimiliki, Poin Player, Action (Double, Next, Half, Ability) 
Attr: ownedCard, playerPoint, 
Method: setPlayerAction, 
*/

class player {
    protected:
    char ownedCard[2];
    int playerPoint;

    public:
    // Constructor
    player();

    // Setter and Getter
    void setPlayerAction();
    char getPlayerCard();
    int getPlayerPoint();
};

#endif