#include "Deck.hpp"

using namespace std;

// Constructor
// Default Constructor
Deck::Deck()
{
    vector<pair<int, char> > deckCards;
    vector<pair<int, char> > tableCards;

    // Generate Deck Card
    int generateCardOption;
    cout << "Opsi Generate Kartu Pada Deck : " << endl;
    cout << "   [1] Randomize Card" << endl;
    cout << "   [2] Read From File" << endl;
    cout << "Answer : ";
    cin >> generateCardOption;

    // Validasi input
    while (1 < generateCardOption < 2)
    {
        cout << "Invalid Input! Try Again";
        cout << "Answer : ";
        cin >> generateCardOption;
    };

    if (generateCardOption == 1)
    {
        char color[4] = {'M', 'B', 'H', 'K'};
        for (int i = 1; i < 14; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                deckCards.push_back(make_pair(i, color[j]));
            }
        }
        Deck::shuffleCard(deckCards);
    }
    else
    {
        string fileName;
        cout << "Masukkan nama file : ";
        cin >> fileName;
        string filePath = "../test/" + fileName;
        Deck::cardFromFile(filePath);
    }

    // Generate Ability Cards
    vector<string> abilityCards;
    abilityCards.push_back("Re-Roll");
    abilityCards.push_back("Quadruple");
    abilityCards.push_back("Quarter");
    abilityCards.push_back("Reverse");
    abilityCards.push_back("Swap");
    abilityCards.push_back("Switch");
    abilityCards.push_back("Abilityless");
    Deck::shuffleCard(abilityCards);
}

// User-defined Constructor
Deck::Deck(vector<pair<int, char> > deckCards)
{
    this->deckCards = deckCards;
    // this->tableCards = tableCards;
    // this->abilityCards = abilityCards;
}
/* NOTE :
    Boleh ga ya kalo Default Constructor buat Random Shuffle &&
    User-defined Constructor untuk Read Deck Card Form File
*/

// Getter
vector<pair<int, char> > Deck::getDeckCard()
{
    return this->deckCards;
}
// vector<pair<int, char> > Deck::getTableCard()
// {
//     return tableCards;
// }
// vector<string> Deck::getAbilityCard()
// {
//     return abilityCards;
// }

/* NOTE : Atau AbilityCard mau dibikin pair sama status : udah kepake/belum */

// Setter
// void Deck::setDeckCard(vector<pair<int, char> > newDeckCards)
// {
//     deckCards = newDeckCards;
// }
// void Deck::setTableCard(vector<pair<int, char> > newTableCards)
// {
//     tableCards = newTableCards;
// }
// void Deck::setAbilityCard(vector<string> newAbilityCards)
// {
//     abilityCards = newAbilityCards;
// }

// Generate Card From File
void Deck::cardFromFile(string filePath)
{
    string textRead, cardColor, cardNumber;
    // Read from the txt file
    ifstream readFile("filePath");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(readFile, textRead))
    {
        if (textRead[2] == ' ')
        {
            this->deckCards.push_back(make_pair(textRead[0], textRead[2]));
        }
        else
        {
            this->abilityCards.push_back(textRead);
        }
    }

    readFile.close();
}

// Validasi Card From File
// NOTE : Atau ini mau pake exception?
// bool Deck::validDeckCard(vector<pair<int, char> > deckCards)
// {
//     bool valid = true;
//     // while (valid && cekPair in deckCards){}
//     return valid;
// }

// Shuffle Card
template <class T>
void Deck::shuffleCard(T card) {}

// Take A Deck Card
pair<int, char> Deck::getADeckCard(vector<pair<int, char> > deckCards)
{
    // Modify-----
    pair<int, char> card = deckCards[0];
    // get the iterator that points to the first element
    auto it = this->deckCards.begin();
    // erase the element pointed by it
    this->deckCards.erase(it);
    return card;
}

// Return A Deck Card
void Deck::retDeckCard(pair<int, char> card)
{
    this->deckCards.push_back(card);
}

// PrintCard
void Deck::printCard() {}

/*
Class: Deck : 52 Kartu, bagiKartu
Attr: array of number + ability card
Method: getCard (Husnia)
*/