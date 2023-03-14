#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

// #include <vector>
#include <algorithm>
#include "..\Deck\Deck.hpp"
#include "..\player\Player.hpp"
using namespace std;

class GameState {
    private:
        int rewardPoint;
        // Deck tableCard;
        int currentTurn;
        bool reverseStatus;
        bool reverseStatusChange;
        static int totalTurn;

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

        void setCurrentTurn(int); // Set game's current turn
        void setReverseStatus(bool); // Set game's reverse status (true: reversed, false: not reversed)
        void setReverseStatusChange(bool); // Set true if player do the reverse action
        void setTotalTurn(int); // Set total turns (number of turns before reverse)

        // void showTableCard(); // Print Table Card
        
        void fourtimesRewardPoint(); // Quadruple game's current reward point
        void doubleRewardPoint(); // Double game's current reward point
        void halfRewardPoint(); // Halve game's current reward point
        void quarterRewardPoint(); // Quarter game's current reward point

        void nextPlayerOrder(); // Current Turn Rotation
        
        bool isWin(vector<Player>); // Check if there is a player whose point is >= 2^32
};
#endif