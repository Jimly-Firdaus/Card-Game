#include "GameState/GameState.hpp"
// #include "player/player.hpp"
// #include "player/playerAction.hpp"
#include "player/PlayerCollection.hpp"

// g++ main.cpp Gamestate/GameState.cpp player/player.cpp Deck/Deck.cpp -o out
int main()
{
    bool terminateGame = false;
    GameState game;
    srand(time(NULL));

    while (!terminateGame)
    {
        // Player + game state instantiation here
        // initiate color list
        char color[4] = {'M', 'K', 'B', 'H'};
        // initiate player
        PlayerCollection player;
        // initiate ability list
        vector<string> ability = {"Re-Roll", "Quadruple", "Quarter", "ReverseDirection", "SwapCard", "Switch", "AbilityLess"};
        
        bool foundWinner = false;
        // game loop
        while (!foundWinner)
        {
            // initiate state
            GameState state;
            // initiate deck
            Deck totalDeck;
            // fill deck
            for(int i= 0; i< 4; i++){
                for(int j= 1; j<=13; j++){
                    pair<int, char> card= make_pair(j, color[i]);
                    totalDeck + card;
                }
            }
            // shuffle deck
            totalDeck.shuffleCard();
            // distribute card to player
            // vector<PlayerAction> tempPlayer = player.getPlayer();
            for(int i= 0; i< 7; i++){
                player.getPlayer()[i].getCard(totalDeck);
            }
            // Round loop
            int currentRound = 0;
            while (currentRound != 7)
            {
                // if round 2 then distribute ability card
                if(currentRound == 2){
                    for(int i= 0; i< 7; i++){
                        player.getPlayer()[i].getAbilityCard(ability);
                    }
                }
                // play loop
                // int nExecute= 0;
                // while(nExecute != player.getNeff()){
                //     int turnPlayer = state.getCurrentTurn();
                //     PlayerAction currentPlayer = tempPlayer[turnPlayer];
                //     // player play
                //     currentPlayer.playerPlay(state, currentRound);
                //     state.nextPlayerOrder();
                //     nExecute++;
                // }
                // if(currentRound >= 2){
                //     // plus table card
                //     // state.addTableCard(totalDeck);
                // }
                currentRound++;
            }
            
        }
    }
    return 0;
}