#include "Deck.hpp"
using namespace std;

int main()
{
    Deck d1;
    pair<vector<pair<int, char> >, vector<string> > newCards = d1.cardFromFile("testText");
    vector<pair<int, char> > deckCard = newCards.first;
    vector<string> abilityCard = newCards.second;
    d1.setCards(deckCard);
    d1.printCard();
    // d1.shuffleCard();
    d1.printCard();
    /*
    cout << "--------------------------------\n";
    Deck d2;
    pair<int, char> newElmt = make_pair(10, 'X');
    d2 = d1 + newElmt;
    d2.printCard();
    cout << "--------------------------------\n";
    Deck d3;
    newElmt = make_pair(1, 'M');
    d3 = d2 - newElmt;
    d3.printCard();
    */

    cout << "----------- Ability -------------\n";
    for (int i = 0; i < abilityCard.size(); i++)
    {
        cout << i + 1 << ". <" << abilityCard[i] << ">" << endl;
    }

    return 0;
}