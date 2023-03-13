#include "SwapCard.hpp"
#include <bits/stdc++.h>
#include "lib-header/Exception.hpp"
using namespace std;

void SwapCard::getCardInfo(){
    cout << "Swap Card, menukar 1 kartu main deck milik pemain lain dengan 1 kartu main deck milik pemain lain. Tidak boleh ditukar dengan kartu main deck diri sendiri." << endl;
}

int SwapCard::getCard(string choice){
    if(choice == "left"){
        return 0;
    }else if(choice == "right"){
        return 1;
    }
}

int SwapCard::getInput(){
    int idx;
    bool validChoice = false;
    while(!validChoice){
        try{
            string currentChoice= getChoice();
            validChoice = true;
            idx = getCard(currentChoice);
        }catch(WrongChoice e){
            e.what();
            cout << endl;
        }
    }
    return idx;
}

// void SwapCard::swap(Player& target, Player& current, int idxTarget, int idxCurrent){
//     target.setPlayerCard(current.getPlayerCard()., idxTarget);
//     current.setPlayerCard(temp, idxCurrent);
// }

void SwapCard::callCard(Player& target, Player& current){
    int idxCurrent;
    int idxTarget;
    cout << "Please choose your card, input left or right (LOWERCASE MATTER)" << endl;
    idxCurrent = getInput();
    cout << "Please choose target card, input left or right (LOWERCASE MATTER)" << endl;
    idxTarget = getInput();
    swap(target, current, idxTarget, idxCurrent);
}

string SwapCard::getChoice(){
    cout << "Please include your choice: " << endl;
    string choice;
    cin >> choice;
    if(choice != "left" && choice != "right"){
        WrongChoice e;
        throw e;
    }
    return choice;
}