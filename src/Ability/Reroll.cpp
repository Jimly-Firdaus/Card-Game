#include "Reroll.hpp"
#include <bits/stdc++.h>
using namespace std;

void Reroll::getCardInfo()
{
    cout << "Re-Roll, membuang 2 kartu dari main deck yang dimiliki oleh diri sendiri dan mengambil ulang 2 kartu." << endl;
}

void Reroll::callCard(Player &player, Deck newCard)
{
    player.setPlayerCard(newCard);
}