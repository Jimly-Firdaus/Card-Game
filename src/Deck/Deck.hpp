#ifndef DECK_HPP
#define DECK_HPP

#include <iostream>
#include <utility>
using namespace std;

class Deck
{
private:
    pair<int, char> deckCard[52];
    pair<int, char> tableCard[5];
    char abilityCard[7];

public:
    // Constructor
    Deck();

    // Setter Deck Card
    void setDeckCard(pair<int, char> *arrayOfCard);
    pair<int, char> *getRandomCard();
    pair<int, char> *getCardFromFile();

    // Randomize while
    // Getter Deck Card
    pair<int, char> *getDeckCard();

    // Show top deck card
    void showTopDeckCard();

    // Swap Deck Card and Player Card
    pair<int, char> takeADeckCard();
    void returnADeckCard(pair<int, char>);
    void shuffleDeckCard(); // Perlu ga? waktu kembaliin kartu habis swap taruh paling bawah aja atau shuffle lagi
};

#endif

/*
Class: Deck : 52 Kartu, bagiKartu
Attr: array of number + ability card
Method: getCard (Husnia)
*/