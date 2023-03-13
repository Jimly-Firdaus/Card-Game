#include <iostream>
#include "GameState.hpp"

int main()
{
    GameState x;
    cout << x.getRewardPoint() << endl;
    // x.showTableCard();
    cout << x.getCurrentTurn() << endl;

    for (int i = 0; i < 10; i++) {
        x.nextPlayerOrder();
        cout << x.getCurrentTurn() << endl;
    }
    
    x.setReverseStatus(true);
    x.setReverseStatusChange(true);
    
    for (int i = 0; i < 10; i++) {
        x.nextPlayerOrder();
        cout << x.getCurrentTurn() << endl;
    }

    x.setReverseStatus(false);
    x.setReverseStatusChange(true);
    for (int i = 0; i < 10; i++) {
        x.nextPlayerOrder();
        cout << x.getCurrentTurn() << endl;
    }
}