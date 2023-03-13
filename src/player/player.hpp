#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../Deck/Deck.hpp"

/*Class: Player : Kartu yang dimiliki, Poin Player, Action (Double, Next, Half, Ability) 
Attr: ownedCard, playerPoint, 
Method: setPlayerAction, 
*/

class Player {
    protected:
    Deck ownedCard; // Hand card yang dimiliki oleh setiap pemain (termasuk ability card)
    int playerPoint;

    public:
    // Constructor
    Player(); //
    Player(Deck ownedCard); 
    // Setiap instantiate, menerima deck owned card yang dirandom secara langsung 
    // Round 1 player didefine semua, round selanjutnya dapet ability card

    // Setter and Getter
    void setPlayerAction(); // Aksi (next/double/half) yang dilakukan oleh pemain
    void setPlayerCard(Deck newCard); // Membagikan kartu secara random kepada pemain
    void setPlayerPoint(int newPoint); // Memperbarui poin pemain berdasarkan hasil kombinasi terbesar pada suatu ronde
    
    Deck getPlayerCard(); // Mengembalikan hasil random kartu yang dimiliki oleh setiap pemain
    int getPlayerPoint(); // Mengembalikan poin yang dimiliki oleh pemain
};

#endif