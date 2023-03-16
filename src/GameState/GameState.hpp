#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <cmath>
#include "../Deck/Deck.hpp"

const int PLAYERORDER_LENGTH = 7;

class GameState
{
private:
    long long rewardPoint;
    Deck tableCard;
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
    long long getRewardPoint();     // Get game's current reward point
    void setRewardPoint(long long); // Set game's current reward point with desired value

    int getCurrentTurn();          // Get game's current turn
    bool getReverseStatus();       // Get game's reverse status
    bool getReverseStatusChange(); // Get game's reverse status change
    int getTotalTurn();            // Get game's total turn
    int getGameNumber();           // Get game number;

    void setCurrentTurn(int);          // Set game's current turn
    void setReverseStatus(bool);       // Set game's reverse status (true: reversed, false: not reversed)
    void setReverseStatusChange(bool); // Set true if player do the reverse action
    void setTotalTurn(int);            // Set total turns (number of turns before reverse)
    void setGameNumber(int);           // Set Game Number
    void addTableCard(Deck &);

    void showTableCard(); // Print Table Card
    Deck getTableCard();  // Get Table Card

    void fourtimesRewardPoint(); // Quadruple game's current reward point
    void doubleRewardPoint();    // Double game's current reward point
    void halfRewardPoint();      // Halve game's current reward point
    void quarterRewardPoint();   // Quarter game's current reward point

    void nextPlayerOrder(); // Player Change In One Round
    void showPlayerOrder(); // Print PlayerOrder in OneRound

    void reset(); // Reset GameState
};
#endif
