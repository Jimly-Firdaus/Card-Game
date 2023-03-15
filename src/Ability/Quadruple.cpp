#include "Quadruple.hpp"
// #include <bits/stdc++.h>

void Quadruple::getCardInfo()
{
    cout << "Quadruple, sama seperti aksi double hanya saja multipliernya menjadi 4x." << endl;
}

void Quadruple::callCard(PlayerCollection &player, GameState &state, Deck &deck)
{
    state.fourtimesRewardPoint();
}