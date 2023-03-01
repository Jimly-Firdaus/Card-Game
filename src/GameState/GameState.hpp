#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

class GameState {
    private:
        int rewardPoint;
        char tableCard[5];
        int playerOrder[7];

    public:
        // Ctor
        GameState();

        // Getter & Setter
        int getRewardPoint(); // Get game's current reward point
        void setRewardPoint(int); // Set game's current reward point with desired value
        void setTableCard(char *arrayOfCard); // Set tableCard with values from arrayOfCard
        void setPlayerOrder(int *arrayOfOrder); // Set playerOrder with values from arrayOfCard

        void showTableCard(); // Print Table Card
        void showPlayerOrder(); // Print Player Order
        
        void fourtimesRewardPoint(); // Quadruple game's current reward point
        void doubleRewardPoint(); // Double game's current reward point
        void halfRewardPoint(); // Halve game's current reward point
        void quarterRewardPoint(); // Quarter game's current reward point

        void nextPlayerOrder(); // Player Order Rotation
        
        // bool isWin();
        // Wait for Player
};

#endif