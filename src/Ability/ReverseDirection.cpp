#include "ReverseDirection.hpp"
// #include <bits/stdc++.h>

using namespace std;

void ReverseDirection::getCardInfo()
{
    cout << "Reverse Direction, memutar arah giliran, pemain yang sudah melakukan aksi pada giliran tersebut akan dilewati." << endl;
}

void ReverseDirection::callCard(PlayerCollection &player, GameState &state, Deck &deck, PlayerAction& currentPlayer)
{
    state.setReverseStatus(true);
    state.setReverseStatusChange(true);
}