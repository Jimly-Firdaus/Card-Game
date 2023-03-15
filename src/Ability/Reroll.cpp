#include "Reroll.hpp"
#include <bits/stdc++.h>
using namespace std;

void Reroll::getCardInfo()
{
    cout << "Re-Roll, membuang 2 kartu dari main deck yang dimiliki oleh diri sendiri dan mengambil ulang 2 kartu." << endl;
}

void Reroll::callCard(PlayerAction &player, Deck& newCard)
{
    player.getOwnedCard()-player.getOwnedCard().getACard(0);
    player.getOwnedCard()-player.getOwnedCard().getACard(1);
    player.getCard(newCard);
}