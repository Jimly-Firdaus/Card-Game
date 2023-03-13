#include "player.hpp"
#include "../Deck/Deck.hpp"
#include <iostream>
using namespace std;

/*Class: Player : Kartu yang dimiliki, Poin Player, Action (Double, Next, Half, Ability)
Attr: ownedCard, playerPoint,
Method: setPlayerAction,
*/

// Constructor
// Default Constructor
Player::Player(Deck &fullCard) : Deck()
{
    Deck ownedCard;
    int idx;
    pair<int, char> card;
    for (int i = 0; i < 2; i++)
    {
        idx = rand() % (fullCard.getCards().size());
        card = fullCard.getACard(idx);
        cout << "--- " << card.first << ", " << card.second << " ----\n";
        ownedCard = ownedCard + card;
        fullCard = fullCard - card;
    }
    playerPoint = 0;
}
// User-defined Constructor
Player::Player(Deck ownedCard, int playerPoint) : Deck()
{
    this->ownedCard = ownedCard;
    this->playerPoint = playerPoint;
}
// Setiap instantiate, menerima deck owned card yang dirandom secara langsung
// Round 1 player didefine semua, round selanjutnya mendapatkan ability card

// Setter and Getter
// Membagikan kartu secara random kepada pemain
void Player::setPlayerCard(Deck newCard)
{
    ownedCard = newCard;
}
// Memperbarui poin pemain berdasarkan hasil kombinasi terbesar pada suatu ronde
void Player::setPlayerPoint(int newPoint)
{
    playerPoint = newPoint;
}

// Mengembalikan hasil random kartu yang dimiliki oleh setiap pemain
Deck Player::getPlayerCard()
{
    return ownedCard;
}
// Mengembalikan poin yang dimiliki oleh pemain
int Player::getPlayerPoint()
{
    return playerPoint;
}

// Menukar kartu pada index ke idx dengan kartu baru newCard
void Player::setAPlayerCard(int idx, pair<int, char> newCard)
{
    pair<int, char> exchangeCard = ownedCard.getACard(idx);
    ownedCard = ownedCard - exchangeCard;
    ownedCard = ownedCard + newCard;
}

// Mencetak player card untuk testing
void Player::printPlayerCard()
{
    cout << "Kartu milik player" << endl;
    cout << "1. <" << ownedCard.getCards()[0].first << ", " << ownedCard.getCards()[0].second << ">" << endl;
    cout << "2. <" << ownedCard.getCards()[1].first << ", " << ownedCard.getCards()[1].second << ">" << endl;
}
