#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../Deck/Deck.hpp"

/*Class: Player : Kartu yang dimiliki, Poin Player, Action (Double, Next, Half, Ability)
Attr: ownedCard, playerPoint,
Method: setPlayerAction,
*/

class Player : Deck
{
protected:
    enum abilityCard{}
    Deck ownedCard; // Hand card yang dimiliki oleh setiap pemain (termasuk ability card)
    
    int playerPoint;

public:
    // Constructor
    Player(Deck &fullCard);                  // Default Constructor
    Player(Deck ownedCard, int playerPoint); // User-defined Constructor
    // Setiap instantiate, menerima deck owned card yang dirandom secara langsung
    // Round 1 player didefine semua, round selanjutnya mendapatkan ability card

    // Setter and Getter
    virtual void setPlayerAction() = 0;     // Aksi (next/double/half) yang dilakukan oleh pemain
    void setPlayerCard(Deck newCard);       // Membagikan kartu secara random kepada pemain
    void setPlayerPoint(int newPoint);      // Memperbarui poin pemain berdasarkan hasil kombinasi terbesar pada suatu ronde

    Deck getPlayerCard(); // Mengembalikan hasil random kartu yang dimiliki oleh setiap pemain
    int getPlayerPoint(); // Mengembalikan poin yang dimiliki oleh pemain

    void setAPlayerCard(int idx, pair<int, char> newCard); // Menukar kartu pada index ke idx dengan kartu baru newCard
    void printPlayerCard();                                // Mencetak player card untuk testing
};

#endif