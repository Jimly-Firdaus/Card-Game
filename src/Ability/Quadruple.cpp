#include "Quadruple.hpp"
#include <bits/stdc++.h>
using namespace std;

void Quadruple::getCardInfo(){
    cout << "Quadruple, sama seperti aksi double hanya saja multipliernya menjadi 4x." << endl;
}

void Quadruple::callCard(PlayerAction& player, Deck& deck, GameState& state){
    state.fourtimesRewardPoint();
}