#include "Deck.hpp"

// Constructor
// Default Constructor
Deck::Deck() {}

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
pair<vector<pair<int, char>>, vector<string>> Deck::cardFromFile(string fileName)
{
    string textRead, cardColor, cardNumber;
    pair<vector<pair<int, char>>, vector<string>> result;
    vector<pair<int, char>> deck;
    vector<string> ability;
    int idx = 0;
    do
    {
        // Read from the txt file
        ifstream readFile;
        string filePath = "./test/" + fileName + ".txt";
        readFile.open(filePath.c_str(), ios::in);
        if (!readFile)
        {
            FileNotFound e;
            throw e;
        }

        // Read the file line by line
        pair<int, char> newElement;
        while (getline(readFile, textRead))
        {
            if (idx < 19)
            {
                string el1 = "";
                string el2 = "";
                size_t itr = textRead.find(' ');
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
                    deck.push_back(newElement);
                }
            }
            else
            {
                ability.push_back(textRead);
            }
            idx++;
        }
        readFile.close();

        // Auto-fill deck card
        char color[4] = {'M', 'B', 'K', 'H'};
        for (int i = 1; i < 14; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                vector<pair<int, char>>::iterator itr = find(deck.begin(), deck.end(), make_pair(i, color[j]));
                if (itr == deck.end()) // Card not found
                {
                    newElement = make_pair(i, color[j]);
                    deck.push_back(newElement);
                }
            }
        }
        result = make_pair(deck, ability);
    } while (!validDeckCard(result));

    return result;
}

// Validasi Card From File
bool Deck::validDeckCard(pair<vector<pair<int, char>>, vector<string>> result)
{
    vector<pair<int, char>> deck = result.first;
    vector<string> ability = result.second;
    bool valid = true;
    int i, j;

    for (i = 0; i < deck.size() - 1 && valid; i++)
    {
        if (count(deck.begin(), deck.end(), deck[i]) > 1)
        {
            cout << "Deck <" << deck[i].first << ", " << deck[i].second << "> more than one" << endl;
            valid = false;
        }
    }
    for (i = 0; i < ability.size() - 1 && valid; i++)
    {
        if (count(ability.begin(), ability.end(), ability[i]) > 1)
        {
            cout << "Ability <" << ability[i] << "> more than one" << endl;
            valid = false;
        }
    }

    if (deck.size() != 52 && ability.size() != 7 && valid)
    {
        valid = false;
    }
    else
    {

        bool valid = true;
        char color[4] = {'M', 'B', 'K', 'H'};
        for (i = 1; i < 14 && valid; i++)
        {
            for (j = 0; j < 4 && valid; j++)
            {
                vector<pair<int, char>>::iterator itr = find(deck.begin(), deck.end(), make_pair(i, color[j]));
                if (itr == deck.end())
                {
                    cout << "Cant find card <" << i << "," << color[j] << ">" << endl;
                    valid = false;
                }
            }
        }

        string abilityList[7] = {"Re-Roll", "Quadruple", "Quarter", "Reverse", "Swap", "Switch", "Abilityless"};
        for (i = 0; i < 7 && valid; i++)
        {
            vector<string>::iterator itr = find(ability.begin(), ability.end(), abilityList[i]);
            if (itr == ability.end())
            {
                valid = false;
            }
        }
    }
    if (!valid)
    {
        MapElementNotFound e;
        throw e;
    }
    return valid;
}
// Shuffle Card
void Deck::shuffleCard()
{
    random_device rd;
    mt19937 g(rd());
    shuffle(cards.begin(), cards.end(), g);
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
    if (cards.size() == 0)
    {
        cout << "There is no card\n";
    }
    else
    {
        for (int i = 0; i < cards.size(); i++)
        {
            cout << i + 1 << ". <" << cards[i].first << ", " << cards[i].second << ">" << endl;
        }
    }
}

void Deck::setACard(int idx, pair<int, char> card)
{
    this->cards[idx] = card;
}
