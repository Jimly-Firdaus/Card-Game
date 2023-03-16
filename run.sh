#!/bin/bash
clear
cd src
g++ main.cpp Game/Game.cpp player/playerAction.cpp player/player.cpp GameState/GameState.cpp Deck/Deck.cpp Comparator/Comparator.cpp Comparator/Handler.cpp Combination/Combination.cpp -o ../bin/a
cd ..
cd bin
./a
cd ..