#ifndef PLAYER_HPP
#define PLAYER_HPP

// #include "../Deck/Deck.hpp"
#include "../GameState/GameState.hpp"
// #include <ctime>
// #include <cstdlib>
// #include <bits/stdc++.h>
#include <vector>

/*Class: Player : Kartu yang dimiliki, Poin Player, Action (Double, Next, Half, Ability)
Attr: ownedCard, playerPoint,
Method: setPlayerAction,
*/

class Player
{
protected:
    Deck ownedCard; // Hand card yang dimiliki oleh setiap pemain (termasuk ability card)
    int playerPoint;
    string nickName;
    // int idPlayer;

public:
    // Constructor
    Player();
    void getCard(Deck& Deck);
    void printPlayerOption();
    int getPlayerPoint();
    void setPlayerPoint(int playerPoint);
    void setNickName(string nickName);
    string getNickName();
    Deck getOwnedCard();
    // Player(Deck &fullCard);        // Default Constructor
    // Player(Deck ownedCard, int playerPoint, string ability, string nickName, int idPlayer); // User-defined Constructor
    // // Setiap instantiate, menerima deck owned card yang dirandom secara langsung
    // // Round 1 player didefine semua, round selanjutnya mendapatkan ability card

    // // Setter and Getter
    // void setPlayerCard(Deck newCard);       // Membagikan kartu secara random kepada pemain
    // void setPlayerPoint(int newPoint);      // Memperbarui poin pemain berdasarkan hasil kombinasi terbesar pada suatu ronde

    // Deck getPlayerCard(); // Mengembalikan hasil random kartu yang dimiliki oleh setiap pemain
    // int getPlayerPoint(); // Mengembalikan poin yang dimiliki oleh pemain

    // void setAPlayerCard(int idx, pair<int, char> newCard); // Menukar kartu pada index ke idx dengan kartu baru newCard
    // void printPlayerCard();                                // Mencetak player card untuk testing
};

#endif