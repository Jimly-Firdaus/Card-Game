#include <iostream>
#include "player.hpp"
using namespace std;

/*Class: Player : Kartu yang dimiliki, Poin Player, Action (Double, Next, Half, Ability) 
Attr: ownedCard, playerPoint, 
Method: setPlayerAction, 
*/

class player {
    protected:
    char ownedCard[2]; // Hand card yang dimiliki setiap pemain
    int playerPoint;

    public:
    // Constructor
    player(){
        playerPoint = 0;

    }

    // Setter and Getter
    void setPlayerAction(){
        
    }
    void setPlayerCard(){

    }
    void setPlayerPoint(){

    }
    
    char getPlayerCard(){

    }
    int getPlayerPoint(){

    }
};

#endif