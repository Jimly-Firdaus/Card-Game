#include "Switch.hpp"
#include <iostream>
#include <string>
using namespace std;

void Switch::getCardInfo(){
    cout << "Switch, menukar 2 kartu main deck milik diri sendiri dengan 2 kartu main deck milik pemain lain. Harus bertukar milik sendiri dengan pemain lain. Tidak boleh ke 2 pemain lain." << endl;
}

void Switch::callCard(PlayerCollection& player, GameState& state, Deck& deck) {
    cout << "Here are the target" << endl;
    printTarget(player);
    bool inputValid = false;
    string targetNickName;
    while(!inputValid){
        try{
            targetNickName = getTarget(player);
        }catch(WrongChoice e){
            e.what();
        }
    }
    int idxTargetNickName = player.getTargetIdx(targetNickName);
    Deck temp = player.getPlayer()[idxTargetNickName].getOwnedCard();
    player.getPlayer()[idxTargetNickName].getOwnedCard() = this->getOwnedCard();
    this->getOwnedCard() = temp;

}

string Switch::getTarget(PlayerCollection& player){
    cout << "Please include your choice (nickname) : ";
    string choice;
    cin >> choice;
    if(player.checkTarget(choice, this->nickName)){
        return choice;
    }else{
        WrongChoice e;
        throw e;
    }
}

void Switch::printTarget(PlayerCollection& player){
    int n= 1;
    for(int i= 0; i< 7; i++){
        if(player.getPlayer()[i].getNickName() != this->nickName){
            cout << n << ". " << player.getPlayer()[i].getNickName();
            n++;
        }
    }
}