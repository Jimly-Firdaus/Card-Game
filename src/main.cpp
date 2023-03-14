#include <iostream>
#include "GameState/GameState.hpp"
// #include "player/player.hpp"
#include "player/playerAction.hpp"
#include <bits/stdc++.h>
#include "Deck/Deck.hpp"
using namespace std;

// g++ main.cpp Gamestate/GameState.cpp player/player.cpp Deck/Deck.cpp -o out
int main()
{
    srand(time(NULL));
    bool terminateGame = false;
    GameState game;

    while (!terminateGame)
    {
        // Player + game state instantiation here
        // initiate color list
        char color[4] = {'M', 'K', 'B', 'H'};
        // initiate player
        vector<PlayerAction> player(7);
        // initiate ability list
        vector<string> ability = {"Re-Roll", "Quadruple", "Quarter", "ReverseDirection", "SwapCard", "Switch", "AbilityLess"};
        // initiate state
        GameState state;

        bool foundWinner = false;
        // game loop
        while (!foundWinner)
        {
            Deck totalDeck;
            for(int i= 0; i< 4; i++){
                for(int j= 1; j<=13; j++){
                    pair<int, char> card= make_pair(j, color[i]);
                    totalDeck + card;
                }
            }
            int currentRound = 0;
            for(int i= 0; i< 7; i++){
                player[i].getRandomCard(totalDeck);
            }
            // Round loop
            while (currentRound != 7)
            {
                if(currentRound == 2){
                    for(int i= 0; i< 7; i++){
                        player[i].getAbilityCard(ability);
                    }
                }
                int nExecute= 0;
                while(nExecute != player.size()){

                }
                currentRound++;
            }
        }
    }
    return 0;
}