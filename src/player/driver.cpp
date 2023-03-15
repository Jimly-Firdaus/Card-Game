#include "playerAction.hpp"
#include <ctime>
#include <cstdlib>

void printAbility(vector<string> abilities){
    for(int i= 0; i< abilities.size(); i++){
        cout << abilities[i] << endl;
    }
}

int main(){
    srand(time(NULL));
    GameState state;
    PlayerAction player;
    Deck deck;
    char color[4] = {'M', 'K', 'B', 'H'};
    vector<string> abilities = {"Re-Roll", "Quadruple", "Quarter", "ReverseDirection", "SwapCard", "Switch", "AbilityLess"};
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
    cout << "===================" << endl;
    player.printPlayerInfo();
    cout << "===================" << endl;
    printAbility(abilities);
    cout << "===================" << endl;
    player.getAbilityCard(abilities);
    player.printPlayerInfo();
    cout << "===================" << endl;
    printAbility(abilities);
    cout << "This is reward point :" << state.getRewardPoint() << endl;
    cout << "===================" << endl;
    player.DOUBLE(state);
    cout << "This is reward point :" << state.getRewardPoint() << endl;
    cout << "===================" << endl;
    player.NEXT();
    cout << "This is reward point :" << state.getRewardPoint() << endl;
    cout << "===================" << endl;
    player.HALF(state);
    cout << "This is reward point :" << state.getRewardPoint() << endl;
}