#include "Deck.hpp"
#include <iostream>
#include <utility>

using namespace std;

// Constructor
Deck::Deck()
{
    this->deckCard = new pair<int, char>[52];
    this->tableCard = new pair<int, char>[5];
    this->card = new pair<int, char>[52];
    char color[4] = {'M', 'B', 'H', 'K'};
    int itr = 0;
    for (int i = 1; i < 53; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            card[itr] = make_pair(i, color[j]);
            itr++;
        }
    }
}

// Setter Deck Card
void Deck::setDeckCard()
{
    int generateCard;
    cout << "Opsi Generate Kartu Pada Deck : " << endl;
    cout << "   [1] Randomize Card" << endl;
    cout << "   [2] Read From File" << endl;
    cout << "Answer : ";
    cin >> generateCard;
    if (generateCard == 1)
        deckCard = getRandomCard(card);
    else
    {
        string fileName;
        cout << "Masukkan nama file : ";
        cin >> fileName;
        deckCard = getCardFromFile(fileName);
    }
}

pair<int, char> *Deck::getRandomCard(pair<int, char> *card) {}

pair<int, char> *Deck::getCardFromFile(string fileName) {}

// Getter Deck Card
pair<int, char> *Deck::getDeckCard()
{
    return deckCard;
}

/*
Class: Deck : 52 Kartu, bagiKartu
Attr: array of number + ability card
Method: getCard (Husnia)
*/