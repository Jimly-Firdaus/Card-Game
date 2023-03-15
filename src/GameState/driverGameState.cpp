#include <iostream>
#include <vector>
#include <utility>
#include "GameState.hpp"

int main()
{
    GameState x;
    // cout << x.getRewardPoint() << endl;
    // // x.showTableCard();
    // cout << x.getCurrentTurn() << endl;

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