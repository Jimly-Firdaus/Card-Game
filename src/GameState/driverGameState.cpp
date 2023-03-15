#include <iostream>
#include <vector>
#include <utility>
#include "GameState.hpp"

int main()
{
    GameState x;
    Player a1, a2, a3, a4, a5, a6, a7;

    a1.setPlayerPoint(20000);
    a2.setPlayerPoint(20000);
    a3.setPlayerPoint(20000);
    a4.setPlayerPoint(4300000050);
    a5.setPlayerPoint(20000);
    a6.setPlayerPoint(20000);
    a7.setPlayerPoint(20000);

    vector<Player> x1;
    x1.push_back(a1);
    x1.push_back(a2);
    x1.push_back(a3);
    x1.push_back(a4);
    x1.push_back(a5);
    x1.push_back(a6);
    x1.push_back(a7);

    if (x.isWin(x1)) {
        cout << "Win" << endl;
    } else {
        cout << "Lose" << endl;
    }

    a1.setPlayerPoint(20000);
    a2.setPlayerPoint(20000);
    a3.setPlayerPoint(20000);
    a4.setPlayerPoint(20000);
    a5.setPlayerPoint(20000);
    a6.setPlayerPoint(20000);
    a7.setPlayerPoint(20000);

    vector<Player> x2;
    x2.push_back(a1);
    x2.push_back(a2);
    x2.push_back(a3);
    x2.push_back(a4);
    x2.push_back(a5);
    x2.push_back(a6);
    x2.push_back(a7);

    if (x.isWin(x2)) {
        cout << "Win" << endl;
    } else {
        cout << "Lose" << endl;
    }

    for (int i = 0; i < 7; i++) {
        cout << x.getCurrentTurn() << " ";
        x.nextPlayerOrder();
        
        if (i == 2) {
            x.setReverseStatus(true);
            x.setReverseStatusChange(true);
        }
    }
    cout << endl;
    x.showPlayerOrder();
    // cout << endl;
    // x.showPlayerOrder();

    for (int i = 0; i < 7; i++) {
        cout << x.getCurrentTurn() << " ";
        x.nextPlayerOrder();
        if (i == 2) {
            x.setReverseStatus(false);
            x.setReverseStatusChange(true);
        }
    }  

    cout << endl;
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 7; i++) {
            x.nextPlayerOrder();
        }
        x.showPlayerOrder();
    }
    cout << x.getGameNumber() << endl;  
}