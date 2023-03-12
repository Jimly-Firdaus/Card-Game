#include "Deck.hpp"
using namespace std;

int main()
{
    Deck d1;
    vector<pair<int, char> > newCards = d1.cardFromFile("testText");
    d1.setCards(newCards);
    d1.printCard();
    // d1.shuffleCard();
    d1.printCard();
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

    return 0;
}