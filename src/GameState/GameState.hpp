#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <vector>
#include <algorithm>
#include "..\Deck\Deck.hpp"
using namespace std;

class GameState {
    private:
        int rewardPoint;
        Deck tableCard;
        int playerOrder[7];
        int nTurn;
        int next;
        int currentTurn;

    public:
        // Ctor
        GameState();

        // Getter & Setter
        int getRewardPoint(); // Get game's current reward point
        void setRewardPoint(int); // Set game's current reward point with desired value

        void showTableCard(); // Print Table Card
        void showPlayerOrder(); // Print Player Order
        
        void fourtimesRewardPoint(); // Quadruple game's current reward point
        void doubleRewardPoint(); // Double game's current reward point
        void halfRewardPoint(); // Halve game's current reward point
        void quarterRewardPoint(); // Quarter game's current reward point

        void nextPlayerOrder(); // Player Order Rotation

        void setPlayerOrder(int[]);
        int* getOrder();
        
        int getNTurn();
        void setNTurn(int);

        int getNext();
        void setNext(int);

        int getCurrentTurn();
        void setCurrentTurn(int);
        // bool isWin();
        // Wait for Player
};
#endif