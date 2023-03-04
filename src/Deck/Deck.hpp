#ifndef DECK_HPP
#define DECK_HPP

#include <iostream>
#include <utility>
#include <string>
using namespace std;

class Deck
{
public:
    // Constructor
    Deck();

    // Setter Deck Card
    void setDeckCard();
    pair<int, char> *getRandomCard(pair<int, char> *card);
    pair<int, char> *getCardFromFile(string fileName);

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
    const string abilityCard[7] = {"Re-Roll", "Quadruple", "Quarter", "Reverse", "Swap", "Switch", "Abilityless"};
    pair<int, char> *card;
    /*
    make_pair(1,'M'), make_pair(2,'M'), make_pair(3,'M'), make_pair(4,'M'), make_pair(5,'M'), make_pair(6,'M'), make_pair(7,'M'), make_pair(8,'M'), make_pair(9,'M'), make_pair(10,'M'), make_pair(11,'M'), make_pair(12,'M'), make_pair(13,'M'),
    make_pair(1,'B'), make_pair(2,'B'), make_pair(3,'B'), make_pair(4,'B'), make_pair(5,'B'), make_pair(6,'B'), make_pair(7,'B'), make_pair(8,'B'), make_pair(9,'B'), make_pair(10,'B'), make_pair(11,'M'), make_pair(12,'M'), make_pair(13,'M'),
    make_pair(1,'M'), make_pair(2,'M'), make_pair(3,'M'), make_pair(4,'M'), make_pair(5,'M'), make_pair(6,'M'), make_pair(7,'M'), make_pair(8,'M'), make_pair(9,'M'), make_pair(10,'M'), make_pair(11,'M'), make_pair(12,'M'), make_pair(13,'M'),
    make_pair(1,'M'), make_pair(2,'M'), make_pair(3,'M'), make_pair(4,'M'), make_pair(5,'M'), make_pair(6,'M'), make_pair(7,'M'), make_pair(8,'M'), make_pair(9,'M'), make_pair(10,'M'), make_pair(11,'M'), make_pair(12,'M'), make_pair(13,'M')
    */
};

#endif

/*
Class: Deck : 52 Kartu, bagiKartu
Attr: array of number + ability card
Method: getCard (Husnia)
*/