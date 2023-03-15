#include "Quarter.hpp"
// #include <bits/stdc++.h>

void Quarter::getCardInfo(){
    cout << "Quarter, sama seperti aksi half hanya saja multipliernya menjadi 0.25x." << endl;
}

void Quarter::callCard(PlayerCollection& player, GameState& state, Deck& deck){
    state.quarterRewardPoint();
}