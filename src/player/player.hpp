#ifndef PLAYER_HPP
#define PLAYER_HPP

/*Class: Player : Kartu yang dimiliki, Poin Player, Action (Double, Next, Half, Ability) 
Attr: ownedCard, playerPoint, 
Method: setPlayerAction, 
*/

class player {
    protected:
    Deck ownedCard;
    int playerPoint;

    public:
    // Constructor
    player();

    // Setter and Getter
    void setPlayerAction();
    void setPlayerCard(Deck);
    void setPlayerPoint();
    
    Deck getPlayerCard();
    int getPlayerPoint();
};

#endif