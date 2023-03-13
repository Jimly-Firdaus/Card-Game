#include "Quarter.hpp"
#include <bits/stdc++.h>
using namespace std;

void Quarter::getCardInfo(){
    cout << "Quarter, sama seperti aksi half hanya saja multipliernya menjadi 0.25x." << endl;
}

void Quarter::callCard(GameState state){
    state.quarterRewardPoint();
}