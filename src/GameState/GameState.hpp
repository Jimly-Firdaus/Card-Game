#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

class GameState {
    private:
        int rewardPoint;
        char tableCard[5];
        int playerOrder[7];

    public:
        GameState();

        int getRewardPoint();
        void setRewardPoint(int);

        void showTableCard();
        void setTableCard(char *arrayOfCard);

        void showPlayerOrder();
        void setPlayerOrder(int *arrayOfOrder);

        void fourtimesRewardPoint();
        void doubleRewardPoint();
        void halfRewardPoint();
        void quarterRewardPoint();

        void nextPlayerOrder(); // Player Order Rotation
        
        // bool isWin(); Wait for Player
};

#endif