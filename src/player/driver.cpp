#include "player.hpp"

int main(){
    Player player;
    Deck deck;
    char color[4] = {'M', 'K', 'B', 'H'};
    for(int i= 0; i< 4; i++){
        for(int j= 1; j<=13; j++){
            pair<int, char> card= make_pair(j, color[i]);
            deck + card;
        }
    }
    // deck.printCard(); // true
    deck.shuffleCard();
    deck.printCard();
    cout << "===================" << endl;
    player.getCard(deck);
    player.getOwnedCard().printCard();
    cout << "===================" << endl;
    deck.printCard();
}