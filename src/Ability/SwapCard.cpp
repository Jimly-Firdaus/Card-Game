#include "SwapCard.hpp"
#include <bits/stdc++.h>
#include "lib-header/Exception.hpp"
using namespace std;

template <class T>
void SwapCard<T>::getCardInfo(){
    cout << "Swap Card, menukar 1 kartu main deck milik pemain lain dengan 1 kartu main deck milik pemain lain. Tidak boleh ditukar dengan kartu main deck diri sendiri." << endl;
}

template <class T>
int SwapCard<T>::getCard(string choice){
    if(choice == "left"){
        return 0;
    }else if(choice == "right"){
        return 1;
    }
}

template <class T>
int SwapCard<T>::getInput(){
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

template <class T>
void SwapCard<T>::swap(player<T>& target, player<T>& current, int idxTarget, int idxCurrent){
    T temp = target.getPlayerCard()[idxTarget];
    target.setPlayerCard(current.getPlayerCard()[idxCurrent], idxTarget);
    current.setPlayerCard(temp, idxCurrent);
}

template <class T>
void SwapCard<T>::callCard(player<T>& target, player<T>& current){
    int idxCurrent;
    int idxTarget;
    cout << "Please choose your card, input left or right (LOWERCASE MATTER)" << endl;
    idxCurrent = getInput();
    cout << "Please choose target card, input left or right (LOWERCASE MATTER)" << endl;
    idxTarget = getInput();
    swap(target, current, idxTarget, idxCurrent);
}

template <class T>
string SwapCard<T>::getChoice(){
    cout << "Please include your choice: " << endl;
    string choice;
    cin >> choice;
    if(choice != "left" && choice != "right"){
        WrongChoice e;
        throw e;
    }
    return choice;
}