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
    vector<string> abilityList;
    abilityList.push_back("AbilityLess");
    abilityList.push_back("Quadruple");
    abilityList.push_back("Quarter");
    abilityList.push_back("Reroll");
    abilityList.push_back("ReverseDirection");
    abilityList.push_back("SwapCard");
    abilityList.push_back("Switch");

    Deck fullCard(full);
    // cout << "----- Before ------- \n";
    // fullCard.printCard();

    Player p1(fullCard, abilityList);
    p1.setPlayerCard(p1.getPlayerCard());
    p1.printPlayerCard();
    // cout << "----- After ------- \n";
    // fullCard.printCard();

    return 0;
}