#include "Switch.hpp"
#include <iostream>
#include <string>
using namespace std;

void Switch::getCardInfo()
{
    cout << "Switch, menukar 2 kartu main deck milik diri sendiri dengan 2 kartu main deck milik pemain lain. Harus bertukar milik sendiri dengan pemain lain. Tidak boleh ke 2 pemain lain." << endl;
}

void Switch::callCard(Player &target, Player &current)
{
    pair<int, char> card1 = current.getPlayerCard().getCards()[0];
    pair<int, char> card2 = current.getPlayerCard().getCards()[1];
    pair<int, char> targetCard1 = target.getPlayerCard().getCards()[0];
    pair<int, char> targetCard2 = target.getPlayerCard().getCards()[1];
    Deck currentPlayerCard({targetCard1, targetCard2});
    Deck targetPlayerCard({card1, card2});
    current.setPlayerCard(currentPlayerCard);
    target.setPlayerCard(targetPlayerCard);
}
