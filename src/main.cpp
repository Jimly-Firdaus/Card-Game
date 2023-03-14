#include <iostream>
#include "Gamestate/GameState.hpp"
#include "player/player.hpp"
#include "player/playerAction.hpp"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool terminateGame = false;

    while (!terminateGame)
    {
        // Player + game state instantiation here
        Deck mainDeck;
        mainDeck.setCards({{}});
        vector <Player> playerComb;

        // Game loop
        bool foundWinner = false;
        while (!foundWinner)
        {
            int currentRound = 0;

            // Round loop
            while (currentRound != 7)
            {

                currentRound++;
            }
        }
    }

    return 0;
}