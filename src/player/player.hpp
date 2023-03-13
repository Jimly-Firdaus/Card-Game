#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <vector>

/*Class: Player : Kartu yang dimiliki, Poin Player, Action (Double, Next, Half, Ability) 
Attr: ownedCard, playerPoint, 
Method: setPlayerAction, 
*/

template <class T>
class player {
    protected:
    int playerOrder[7];
    T ownedCard[2];
    int playerPoint;

    public:
    // Constructor
    player();

    // Setter and Getter
    void setPlayerAction();
    void setPlayerCard(T, int);
    void setPlayerPoint();
    
    char getPlayerCard();
    int getPlayerPoint();
};

#endif