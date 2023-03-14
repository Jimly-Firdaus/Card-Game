#include "Comparator.hpp"

Comparator::Comparator()
{
    this->avail_chars[0] = 'H';
    this->avail_chars[1] = 'B';
    this->avail_chars[2] = 'K';
    this->avail_chars[3] = 'M';

    for (int i = 0; i < MAX_AVAIL_NUMBER; i++)
    {
        float incValue = 0.0;
        for (int j = 0; j < MAX_AVAIL_CHAR; j++)
        {
            this->valueTable.insert(make_pair(make_pair(i + 1, avail_chars[j]), baseValue + incValue));
            incValue += 0.03;
        }
        this->baseValue += 0.1;
    }
}

pair<bool, float> Comparator::isStraightFlush(Deck tableCard, Deck playerCard)
{
    if (isFlush(tableCard, playerCard).first)
    {
        vector<pair<int, char>> mergedCard = mergeDeck(tableCard, playerCard);
        vector<pair<int, char>> flushCard;
        for (int i = 0; i < mergedCard.size(); i++)
        {
            if (mergedCard[i].second == isFlush(tableCard, playerCard).second)
                flushCard.push_back(mergedCard[i]);
        }
        if (isStraight(flushCard).first)
        {
            return {true, isStraight(flushCard).second};
        }
    }
    return {false, 0.0};
}

pair<bool, int> Comparator::isFourKind(Deck tableCard, Deck playerCard)
{
    vector<int> v(13, 0);
    vector<pair<int, char>> mergedCard = mergeDeck(tableCard, playerCard);
    for (const auto &pair : mergedCard)
    {
        v[pair.first - 1]++;
    }
    int index = 0;
    for (auto &ele : v)
    {
        index++;
        if (ele == 4)
        {
            return {true, index};
        }
    }
    return {false, -1};
}
bool Comparator::isFullHouse(Deck tableCard, Deck playerCard)
{
    //
}

pair<bool, char> Comparator::isFlush(Deck tableCard, Deck playerCard)
{
    // color count format = "Hijau", "Biru", "Kuning", "Merah"
    vector<int> v(4, 0);
    vector<pair<int, char>> mergedCard = tableCard.getDeckCard();
    for (int i = 0; i < playerCard.getDeckCard().size(); i++)
    {
        mergedCard.push_back(playerCard.getDeckCard()[i]);
    }
    for (const auto &pair : mergedCard)
    {
        switch (pair.second)
        {
        case 'H':
            v[0]++;
            break;
        case 'B':
            v[1]++;
            break;
        case 'K':
            v[2]++;
            break;
        case 'M':
            v[3]++;
            break;
        }
    }
    int index = 0;
    for (auto &ele : v)
    {
        index++;
        if (ele >= 5)
        {
            return {true, this->avail_chars[index - 1]};
        }
    }
    return {false, ' '};
}

pair<bool, float> Comparator::isStraight(Deck tableCard, Deck playerCard)
{

    vector<pair<int, char>> mergedCard = mergeDeck(tableCard, playerCard);
    Deck mergedDeck(mergedCard);

    return straightComparator(mergedDeck);
}

pair<bool, float> Comparator::isStraight(Deck mergedCard)
{
    return straightComparator(mergedCard);
}

pair<bool, float> Comparator::straightComparator(Deck mergedDeck)
{
    pair<bool, float> result = {false, 0.0};
    int count = 0;
    vector<pair<int, char>> mergedCard = mergedDeck.getDeckCard();
    sort(mergedCard.begin(), mergedCard.end());

    for (int i = MAX_PLAYER_CARD - 1; i > 0; i--)
    {
        if (mergedCard[i].first - mergedCard[i - 1].first == 1)
        {
            count++;
            if (count < 5)
            {
                pair<int, char> selectedPair = findBiggest(mergedCard, mergedCard[i].first);
                result.second += this->searchVal(selectedPair.first, selectedPair.second);
            }
            if (count == 4)
            {
                pair<int, char> selectedPair = findBiggest(mergedCard, mergedCard[i - 1].first);
                result.second += this->searchVal(selectedPair.first, selectedPair.second);
                result.first = true;
                break;
            }
        }
        else if (mergedCard[i].first - mergedCard[i - 1].first != 1 && mergedCard[i].first - mergedCard[i - 1].first != 0)
        {
            count = 0;
            result.second = 0.0;
        }
    }
    return result;
}

// find biggest among the same numbers
pair<int, char> Comparator::findBiggest(vector<pair<int, char>> v, int number)
{
    vector<pair<int, char>> filteredV;
    copy_if(v.begin(), v.end(), back_inserter(filteredV), [number](pair<int, char> x)
            { return x.first - number == 0; });
    float maxVal = 0.0;
    pair<int, char> resultPair = filteredV[0];
    if (filteredV.size() > 1)
    {
        for (const pair<int, char> ele : filteredV)
        {
            if (maxVal < this->searchVal(ele.first, ele.second))
            {
                maxVal = this->searchVal(ele.first, ele.second);
                resultPair = ele;
            }
        }
    }
    return resultPair;
}

bool Comparator::isThreeKind(Deck tableCard, Deck playerCard)
{
}
bool Comparator::isTwoPair(Deck tableCard, Deck playerCard)
{
}

vector<pair<int, char>> Comparator::mergeDeck(Deck firstDeck, Deck secondDeck)
{
    vector<pair<int, char>> v = firstDeck.getDeckCard();
    for (int i = 0; i < secondDeck.getDeckCard().size(); i++)
    {
        v.push_back(secondDeck.getDeckCard()[i]);
    }
    return v;
}

float Comparator::getStrongestCombination(Deck gameCard, Deck playerCard)
{
    // Cek dari tinggi
}

float Comparator::searchVal(int number, char type)
{
    float result = 0.0;

    auto it = this->valueTable.find(make_pair(number, type));
    if (it != this->valueTable.end())
    {
        // key found
        result = it->second;
        return result;
    }
    else
    {
        // key not found
        MapElementNotFound e;
        throw e;
    }
}
