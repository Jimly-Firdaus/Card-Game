#include "ReverseDirection.hpp"
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

template <class T>
void ReverseDirection<T>::getCardInfo(){
    cout << "Reverse Direction, memutar arah giliran, pemain yang sudah melakukan aksi pada giliran tersebut akan dilewati." << endl;
}

template <class T>
void ReverseDirection<T>::callCard(GameState& state){
    int arr[] = state.getOrder();
    reverse(begin(arr), end(arr));
    state.setPlayerOrder(arr);
    int nextTurn = state.getNext();
    int currentTurn = state.getCurrentTurn();
    int nTurn = state.getNTurn();
    if(nextTurn > currentTurn){
        if(currentTurn-nTurn <= 0){
            state.setNext(currentTurn-nTurn+7);
        }else{
            state.setNext(currentTurn-nTurn);
        }
    }else{
        if(currentTurn+nTurn > 7){
            state.setNext(currentTurn+nTurn-7);
        }else{
            state.setNext(currentTurn+nTurn);
        }
    }
}