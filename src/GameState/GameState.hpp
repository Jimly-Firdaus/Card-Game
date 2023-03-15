#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

// #include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
// #include "..\Deck\Deck.hpp"
// #include "..\player\playerAction.hpp"
using namespace std;

const int PLAYERORDER_LENGTH = 7;

class GameState {
    private:
        int rewardPoint;
        // Deck tableCard;
        int playerOrder[PLAYERORDER_LENGTH];
        int currentTurn;
        bool reverseStatus;
        bool reverseStatusChange;
        static int totalTurn;
        static int round;
        static int gameNumber;

    public:
        // Ctor
        GameState();

        // Getter & Setter
        int getRewardPoint(); // Get game's current reward point
        void setRewardPoint(int); // Set game's current reward point with desired value

        int getCurrentTurn(); // Get game's current turn
        bool getReverseStatus(); // Get game's reverse status
        bool getReverseStatusChange(); // Get game's reverse status change
        int getTotalTurn(); // Get game's total turn
        int getGameNumber(); // Get game number;

        void setCurrentTurn(int); // Set game's current turn
        void setReverseStatus(bool); // Set game's reverse status (true: reversed, false: not reversed)
        void setReverseStatusChange(bool); // Set true if player do the reverse action
        void setTotalTurn(int); // Set total turns (number of turns before reverse)
        void setGameNumber(int); // Set Game Number
        // void addTableCard(Deck&);

        // void showTableCard(); // Print Table Card
        
        void fourtimesRewardPoint(); // Quadruple game's current reward point
        void doubleRewardPoint(); // Double game's current reward point
        void halfRewardPoint(); // Halve game's current reward point
        void quarterRewardPoint(); // Quarter game's current reward point

        void nextPlayerOrder(); // Player Change In One Round
        void showPlayerOrder(); // Print PlayerOrder in OneRound

        // bool isWin(vector<Player>); // Check if there is a player whose point is >= 2^32
        void reset(); // Reset GameState
};
#endif