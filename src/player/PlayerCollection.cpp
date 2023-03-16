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

bool PlayerCollection::checkTarget(string nickNameTarget, string nickNameCurrent){
    if(nickNameTarget == nickNameCurrent){
        WrongChoice e;
        throw e;
    }else{
        for(int i= 0; i< getNeff(); i++){
            if(this->player[i].getNickName() == nickNameTarget){
                return true;
            }else{
                WrongChoice e;
                throw e;
            }
        }
    }
    return false;
}

int PlayerCollection::getTargetIdx(string targetNickName){
    for(int i= 0; i<7; i++){
        if(this->player[i].getNickName() == targetNickName){
            return i;
        }
    }
    return -1;
}

void PlayerCollection::printAllPlayer(){
    for(int i= 0; i<7; i++){
        cout << i+1 << "." << endl;
        this->player[i].printPlayerInfo();
    }
}