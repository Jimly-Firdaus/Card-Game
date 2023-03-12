#include "Deck.hpp"
using namespace std;

int main()
{
    Deck d1;
    vector<pair<int, char> > newCards = d1.cardFromFile("testText");
    d1.setCards(newCards);
    d1.printCard();
    d1.shuffleCard();
    d1.printCard();

    return 0;
}