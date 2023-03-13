
#include "player.hpp"
using namespace std;

/*Class: Player : Kartu yang dimiliki, Poin Player, Action (Double, Next, Half, Ability) 
Attr: ownedCard, playerPoint, 
Method: setPlayerAction, 
*/

    // Constructor
    // Default constructor
    player(); 
    // User-defined Constructor
    player(Deck ownedCard);
    // Setiap instantiate, menerima deck owned card yang dirandom secara langsung
    // Round 1 player didefine semua, round selanjutnya dapet ability card

    // Setter and Getter
    void setPlayerAction();            //
    void setPlayerCard(Deck newCard);  //
    void setPlayerPoint(int newPoint); //

    Deck getPlayerCard(); //
    int getPlayerPoint(); //