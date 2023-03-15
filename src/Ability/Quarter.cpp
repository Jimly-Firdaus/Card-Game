#include "Quarter.hpp"
using namespace std;
#include <bits/stdc++.h>

void Quarter::getCardInfo(){
    cout << "Quarter, sama seperti aksi half hanya saja multipliernya menjadi 0.25x." << endl;
}

void Quarter::callCard(PlayerAction& player, Deck& deck, GameState& state){
    state.quarterRewardPoint();
}