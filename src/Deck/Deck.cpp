#include "Deck.hpp"

using namespace std;

// Constructor
// Default Constructor
Deck::Deck()
{
    vector<pair<int, char>> cards;
}

// User-defined Constructor
Deck::Deck(vector<pair<int, char>> Cards)
{
    this->cards = Cards;
}

// Assignment Operator
Deck &Deck::operator=(const Deck &otherCard)
{
    cards = otherCard.cards;
    return *this;
}

// Getter
vector<pair<int, char>> Deck::getCards()
{
    return cards;
}

// Setter
void Deck::setCards(vector<pair<int, char>> newCards)
{
    cards = newCards;
}

// Getter A Card
pair<int, char> Deck::getACard(int idx)
{
    return cards[idx];
}

// Generate Card From File
vector<pair<int, char>> Deck::cardFromFile(string fileName)
{
    string textRead, cardColor, cardNumber;
    vector<pair<int, char>> result;
    // Read from the txt file
    ifstream readFile;
    string filePath = "../../test/" + fileName + ".txt";
    readFile.open(filePath.c_str(), ios::in);

    // Read the file line by line
    while (getline(readFile, textRead))
    {
        string el1 = "";
        string el2 = "";
        size_t itr = textRead.find(' ');
        pair<int, char> newElement;
        if (itr != string::npos)
        {
            for (int i = 0; i < itr; i++)
            {
                el1 += textRead[i];
            }
            for (int i = itr + 1; i < textRead.length(); i++)
            {
                el2 += textRead[i];
            }

            int number = 0;
            for (int k = 0; k < el1.length(); k++)
            {
                number *= 10;
                number += (el1[k] - '0');
            }
            newElement = make_pair(number, el2[0]);
            result.push_back(newElement);
        }
        else
        {
            newElement = make_pair(0, textRead[0]);
            result.push_back(newElement);
        }
    }

    readFile.close();
    return result;
}

// Shuffle Card
void Deck::shuffleCard()
{
    // random_shuffle(cards.begin(), cards.end());
}

// Get Top of Card
pair<int, char> Deck::getTopCard()
{
    return cards[0];
}

// Add A Card
Deck &Deck::operator+(const pair<int, char> &otherCard)
{
    cards.push_back(otherCard);
    return *this;
}

// Throw A Card
Deck &Deck::operator-(const pair<int, char> &otherCard)
{
    vector<pair<int, char>>::iterator itr = cards.begin();
    itr = find(cards.begin(), cards.end(), otherCard);
    if (itr != cards.end())
    {
        cards.erase(itr);
    }
    return *this;
}

// PrintCard
void Deck::printCard()
{
    for (int i = 0; i < cards.size(); i++)
    {
        cout << i + 1 << ". <" << cards[i].first << ", " << cards[i].second << ">" << endl;
    }
}
