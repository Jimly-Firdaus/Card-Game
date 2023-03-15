#include "PlayerCollection.hpp"

PlayerCollection::PlayerCollection(){
    this->Neff = 7;
}

vector<PlayerAction> PlayerCollection::getPlayer(){
    return player;
}

int PlayerCollection::getNeff(){
    return Neff;
}

