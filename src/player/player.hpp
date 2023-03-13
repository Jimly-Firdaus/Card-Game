#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Deck.hpp"

/*Class: Player : Kartu yang dimiliki, Poin Player, Action (Double, Next, Half, Ability) 
Attr: ownedCard, playerPoint, 
Method: setPlayerAction, 
*/

class player {
    protected:
    Deck ownedCard; // hand card yang dimiliki oleh hsetiap pemain
    int playerPoint;

    public:
    // Constructor
    player(); // De
    player(Deck ownedCard); 
    // Setiap instantiate, menerima deck owned card yang dirandom secara langsung 
    // Round 1 player didefine semua, round selanjutnya dapet ability card

    // Setter and Getter
    void setPlayerAction(); //
    void setPlayerCard(Deck newCard); //
    void setPlayerPoint(int newPoint); //
    
    Deck getPlayerCard(); //
    int getPlayerPoint(); //
};

#endif