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
        getline(cin, fileName);
        string filePath = "../test/" + fileName;

        ifstream readFile;
        readFile.open(filePath.c_str());

        while (!readFile.is_open())
        {
            cout << "File not found. Try again!" << endl;

            getline(cin, fileName);
            readFile.open(filePath.c_str());
        }

        readFile.close();
        Deck::cardFromFile(filePath);

        while (!validDeckCard())
        {
            cout << "Masukkan nama file : ";
            getline(cin, fileName);
            string filePath = "../test/" + fileName;

            ifstream readFile;
            readFile.open(filePath.c_str());

            while (!readFile.is_open())
            {
                cout << "File not found. Try again!" << endl;

                getline(cin, fileName);
                readFile.open(filePath.c_str());
            }

            readFile.close();
            Deck::cardFromFile(filePath);
        }
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
Deck::Deck(vector<pair<int, char> > deckCards, vector<pair<int, char> > tableCards, vector<string> abilityCards)
{
    this->deckCards = deckCards;
    this->tableCards = tableCards;
    this->abilityCards = abilityCards;
}
/* NOTE :
    Boleh ga ya kalo Default Constructor buat Random Shuffle &&
    User-defined Constructor untuk Read Deck Card Form File
*/

// Getter
vector<pair<int, char> > Deck::getDeckCard()
{
    return deckCards;
}
vector<pair<int, char> > Deck::getTableCard()
{
    return tableCards;
}
vector<string> Deck::getAbilityCard()
{
    return abilityCards;
}

/* NOTE : Atau AbilityCard mau dibikin pair sama status : udah kepake/belum */

// Setter
void Deck::setDeckCard(vector<pair<int, char> > newDeckCards)
{
    deckCards = newDeckCards;
}
void Deck::setTableCard(vector<pair<int, char> > newTableCards)
{
    tableCards = newTableCards;
}
void Deck::setAbilityCard(vector<string> newAbilityCards)
{
    abilityCards = newAbilityCards;
}

// Generate Card From File
void Deck::cardFromFile(string filePath)
{
    string textRead, cardColor, cardNumber;
    // Read from the txt file
    ifstream readFile;
    readFile.open(filePath.c_str());

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(readFile, textRead))
    {
        if (textRead[2] == ' ')
        {
            deckCards.push_back(make_pair(textRead[0], textRead[2]));
        }
        else
        {
            abilityCards.push_back(textRead);
        }
    }

    readFile.close();
}

// Validasi Card From File
// NOTE : Atau ini mau pake exception?

bool Deck::validDeckCard()
{
    bool valid = true;
    char color[4] = {'M', 'B', 'H', 'K'};
    int i, j;
    for (i = 1; (i <= 13 && valid); i++)
    {
        for (j = 0; (j < 4 && valid); j++)
        {
            vector<pair<int, char> >::iterator itr = find(deckCards.begin(), deckCards.end(), make_pair(i, color[j]));
            if (itr == deckCards.end())
            {
                valid = false;
            }
        }
    }

    if (valid)
    {
        string ability[7] = {"Re-Roll", "Quadruple", "Quarter", "Reverse", "Swap", "Switch", "Abilityless"};
        for (i = 0; (i < 7 && valid); i++)
        {
            vector<string>::iterator itr = find(abilityCards.begin(), abilityCards.end(), ability[i]);
            if (itr == abilityCards.end())
            {
                valid = false;
            }
        }

        if (!valid)
        {
            cout << "Input ability card invalid!" << endl;
            cout << "<" << ability[i] << "> not found!" << endl;
        }
    }
    else
    {
        cout << "Input deck card invalid!" << endl;
        cout << "<" << i << "," << color[j] << "> not found!" << endl;
    }

    return valid;
}

// Shuffle Card
template <class T>
void Deck::shuffleCard(T card)
{
    auto rng = default_random_engine{};
    shuffle(card.begin(), card.end(), rng);
}

// Take A Deck Card
pair<int, char> Deck::getADeckCard(vector<pair<int, char> > deckCards)
{
    pair<int, char> card = deckCards[0];
    vector<pair<int, char> >::iterator itr = deckCards.begin();
    while (itr != deckCards.end())
    {
        if (*itr == card)
        {
            deckCards.erase(itr);
            break;
        }
        ++itr;
    }
    return card;
}

// Return A Deck Card
void Deck::retDeckCard(pair<int, char> card)
{
    deckCards.push_back(card);
}

// PrintCard
void Deck::printCard()
{
    cout << "---------- Deck Card ----------" << endl;
    for (int i = 0; i < deckCards.size(); i++)
    {
        cout << i + 1 << ". <" << deckCards[i].first << ", " << deckCards[i].second << ">" << endl;
    }
    cout << "\n---------- Ability Card ----------" << endl;
    for (int i = 0; i < abilityCards.size(); i++)
    {
        cout << i + 1 << ". " << abilityCards[i] << endl;
    }
}

/*
Class: Deck : 52 Kartu, bagiKartu
Attr: array of number + ability card
Method: getCard (Husnia)
*/