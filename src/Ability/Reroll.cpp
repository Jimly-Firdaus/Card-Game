#include "Reroll.hpp"
#include <bits/stdc++.h>
using namespace std;

void Reroll::getCardInfo()
{
    cout << "Re-Roll, membuang 2 kartu dari main deck yang dimiliki oleh diri sendiri dan mengambil ulang 2 kartu." << endl;
}

void Reroll::callCard(PlayerCollection& player, GameState& state, Deck& deck) 
{
    this->getOwnedCard()-this->getOwnedCard().getACard(0);
    this->getOwnedCard()-this->getOwnedCard().getACard(1);
    this->getCard(deck);
}