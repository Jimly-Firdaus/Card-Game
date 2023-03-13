#include "Switch.hpp"
#include <iostream>
#include <string>
using namespace std;

void Switch::getCardInfo(){
    cout << "Switch, menukar 2 kartu main deck milik diri sendiri dengan 2 kartu main deck milik pemain lain. Harus bertukar milik sendiri dengan pemain lain. Tidak boleh ke 2 pemain lain." << endl;
}

void Switch::callCard(player& target, player& current) {
    pair<int, char> card1 = current.getPlayerCard().getDeckCard()[0];
    pair<int, char> card2 = current.getPlayerCard().getDeckCard()[1];
    pair<int, char> targetCard1 = target.getPlayerCard().getDeckCard()[0];
    pair<int, char> targetCard2 = target.getPlayerCard().getDeckCard()[1];
    Deck currentPlayerCard;
    currentPlayerCard.setDeckCard(targetCard1);
    currentPlayerCard.setDeckCard(targetCard2);
    Deck targetPlayerCard;
    targetPlayerCard.setDeckCard(card1);
    targetPlayerCard.setDeckCard(card2);
    current.setPlayerCard(currentPlayerCard);
    target.setPlayerCard(targetPlayerCard);
}
