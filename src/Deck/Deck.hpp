#ifndef DECK_HPP
#define DECK_HPP

#define vector Vector
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>

using namespace std;

class Deck
{
public:
    // Constructor
    Deck();                                                                                                     // Default Constructor
    Deck(vector<pair<int, char> > deckCards, vector<pair<int, char> > tableCards, vector<string> abilityCards); // User-defined Constructor
    /* NOTE :
        Boleh ga ya kalo Default Constructor buat Random Shuffle &&
        User-defined Constructor untuk Read Deck Card Form File
    */

    // Getter
    vector<pair<int, char> > getDeckCard();
    vector<pair<int, char> > getTableCard();
    vector<string> getAbilityCard();

    /* NOTE : Atau AbilityCard mau dibikin pair sama status : udah kepake/belum */

    // Setter
    void setDeckCard(vector<pair<int, char> > newDeckCards);
    void setTableCard(vector<pair<int, char> > newTableCards);
    void setAbilityCard(vector<string> newAblitiCards);

    // Generate Card From File
    void cardFromFile(string filePath);

    // Validasi Card From File
    bool validDeckCard(vector<pair<int, char> > deckCards);

    // Shuffle Card
    template <class T>
    void shuffleCard(T card);

    // Take A Deck Card
    pair<int, char> getADeckCard(vector<pair<int, char> > deckCards);

    // Return A Deck Card
    void retDeckCard(pair<int, char> card);

    // PrintCard
    void printCard();

private:
    vector<pair<int, char> > deckCards;
    vector<pair<int, char> > tableCards;
    vector<string> abilityCards;
    // vector<string> abilityCards = {"Re-Roll", "Quadruple", "Quarter", "Reverse", "Swap", "Switch", "Abilityless"};
    // no instance of constructor "std::Vector<_Tp, _Alloc>::Vector [with _Tp=std::string, _Alloc=std::allocator<std::string>]" matches the argument list
};
#endif

/*
Class: Deck : 52 Kartu, bagiKartu
Attr: array of number + ability card
Method: getCard (Husnia)
*/