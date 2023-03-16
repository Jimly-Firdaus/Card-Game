#ifndef GAME_HPP
#define GAME_HPP

#include "../GameState/GameState.hpp"
// #include "../Player/PlayerCollection.hpp"
#include "../Comparator/Comparator.hpp"
#include <ctime>

class Game {
    private:
        bool isEndGame;
        int currentRound;
        bool fileConfig;
        vector<char> baseCardColor;
        vector<string> baseAbility;
        vector<string> availableCommands;

    public:
        Game();
        void startGame();
        void endGame();
        void setBaseAbility(vector<string> baseAbility);
        void setEndGameStatus(bool status);
        void restoreAbilityCard();
        bool validateUsername(vector<PlayerAction> players, string newUsername);
        void resetRound();
        void nextRound();
        void restartGame();
        vector<char> getBaseCardColor();
        vector<string> getBaseAbility() const;
        bool endCurrentGame(vector<PlayerAction> players);
        void printGameResult(vector<PlayerAction> players);
        void getCommand(string& command);
};

#endif