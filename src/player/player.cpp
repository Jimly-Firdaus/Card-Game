
#include "player.hpp"
using namespace std;

/*Class: Player : Kartu yang dimiliki, Poin Player, Action (Double, Next, Half, Ability) 
Attr: ownedCard, playerPoint, 
Method: setPlayerAction, 
*/

// Constructor
// Default constructor
Player::Player(){
    playerPoint = 0;
    
}
// User-defined Constructor
Player::Player(Deck ownedCard){}
// Setiap instantiate, menerima deck owned card yang dirandom secara langsung
// Round 1 player didefine semua, round selanjutnya dapet ability card

// Setter and Getter
void Player::setPlayerAction(){}
void Player::setPlayerCard(Deck newCard){}
void Player::setPlayerPoint(int newPoint){}

Deck Player::getPlayerCard(){}
int Player::getPlayerPoint(){}