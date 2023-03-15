#ifndef DECK_HPP
#define DECK_HPP

#define vector Vector
#include <iostream>
#include <cstring>
#include <vector>
#include <array>
#include <algorithm>
#include <random>
#include <utility>
#include <fstream>
#include "../Exception/Exception.hpp"

using namespace std;

class Deck
{
public:
    // Constructor
    Deck();                               // Default Constructor
    Deck(vector<pair<int, char> > cards); // User-defined Constructor

    // Assignment Operator
    Deck &operator=(const Deck &otherCard);

    // Getter
    vector<pair<int, char> > getCards();

    // Setter
    void setCards(vector<pair<int, char> > newCards);

    // Getter A Card
    pair<int, char> getACard(int idx);

    // Generate Card From File
    pair<vector<pair<int, char> >, vector<string> > cardFromFile(string fileName);

    /*
    14 baris pertama pada deck card berisi DeckCard dengan format :
    C<space>N
        C berisi character M/B/K/H yang mewakili warna tiap kartu
        N berisi integer 1-13 yang mewakili nomor kartu

    7 Baris berikutnya berisi list AbilityCard dengan format :
    S
        C berisi string inisial tiap ability card

    Note : Karena deck card dan ability card masih jadi 1 vector, maka diimplementasinya nanti harus di split
    */

    // Validasi Card From File
    bool validDeckCard(pair<vector<pair<int, char> >, vector<string> > result);

    // Shuffle Card
    void shuffleCard();

    // Get Top of Cards
    pair<int, char> getTopCard();

    // Add A Card
    Deck &operator+(const pair<int, char> &otherCard);

    // Throw A Card
    Deck &operator-(const pair<int, char> &otherCard);

    // PrintCard
    void printCard();

private:
    vector<pair<int, char> > cards;
};
#endif

/*
Class: Deck : 52 Kartu, bagiKartu
Attr: array of number + ability card
Method: getCard (Husnia)
*/