#include "player.hpp"
using namespace std;

int main()
{
    Deck d1;
    d1.setCards(d1.cardFromFile("testText"));
    vector<pair<int, char> > full;
    for (int i = 0; i < 52; i++)
    {
        full.push_back(d1.getACard(i));
    }
    Deck fullCard(full);
    cout << "----- Before ------- \n";
    d1.printCard();

    Player p1(fullCard);
    p1.printPlayerCard();
    cout << "----- After ------- \n";
    d1.printCard();

    return 0;
}