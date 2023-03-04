#ifndef DECK_HPP
#define DECK_HPP

#include <iostream>
#include <utility>
using namespace std;

class Deck
{
public:
    // Constructor
    Deck();

    // Setter Deck Card
    void setDeckCard();
    pair<int, char> *getRandomCard();
    pair<int, char> *getCardFromFile();

    // Getter Deck Card
    pair<int, char> *getDeckCard();

    /*
    // Swap Deck Card and Player Card
    pair<int, char> takeADeckCard();
    void returnADeckCard(pair<int, char>);
    void shuffleDeckCard(); // Perlu ga? waktu kembaliin kartu habis swap taruh paling bawah aja atau shuffle lagi
    */

private:
    pair<int, char> *deckCard;
    pair<int, char> *tableCard;
    char *abilityCard;
};

#endif

/*
Class: Deck : 52 Kartu, bagiKartu
Attr: array of number + ability card
Method: getCard (Husnia)
*/