#include "Switch.hpp"
#include <iostream>
#include <string>
using namespace std;

template <class T>
void Switch<T>::getCardInfo(){
    cout << "Switch, menukar 2 kartu main deck milik diri sendiri dengan 2 kartu main deck milik pemain lain. Harus bertukar milik sendiri dengan pemain lain. Tidak boleh ke 2 pemain lain." << endl;
}

template <class T>
void Switch<T>::callCard(player<T>& target, player<T>& current) {
    T card1 = current.getPlayerCard()[0];
    T card2 = current.getPlayerCard()[1];
    T targetCard1 = target.getPlayerCard()[0];
    T targetCard2 = target.getPlayerCard()[1];
    current.setPlayerCard(targetCard1, 0);
    current.setPlayerCard(targetCard2, 1);
    target.setPlayerCard(card1, 0);
    target.setPlayerCard(card2, 1);
}
