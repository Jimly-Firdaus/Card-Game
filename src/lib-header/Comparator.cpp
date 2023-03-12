#include "Comparator.hpp"

// Default Ctor
Comparator::Comparator()
{
    // construct look up constant table
    this->avail_chars[0] = 'H';
    this->avail_chars[1] = 'B';
    this->avail_chars[2] = 'K';
    this->avail_chars[3] = 'M';
    this->color['H'] = 1;
    this->color['B'] = 2;
    this->color['K'] = 3;
    this->color['M'] = 4;
    for (int i = 0; i < MAX_AVAIL_NUMBER; i++)
    {
        float incValue = 0.0;
        for (int j = 0; j < MAX_AVAIL_CHAR; j++)
        {
            // insert all possible cards & constant value
            this->valueTable.insert(make_pair(make_pair(i + 1, avail_chars[j]), baseValue + incValue));
            incValue += 0.03;
        }
        this->baseValue += 0.1;
    }
}

pair<bool, float> Comparator::isStraightFlush(Deck tableCard, Deck playerCard)
{
    // check whether flush or not to continue check straight
    if (isFlush(tableCard, playerCard).first)
    {
        vector<pair<int, char>> mergedCard = mergeDeck(tableCard, playerCard);
        vector<pair<int, char>> flushCard;
        // filter out the non-flush type
        for (int i = 0; i < mergedCard.size(); i++)
        {
            if (mergedCard[i].second == isFlush(tableCard, playerCard).second)
                flushCard.push_back(mergedCard[i]);
        }
        // check straight for the filtered cards
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
    // increment each of card if avail in table card + hand
    for (const auto &pair : mergedCard)
    {
        v[pair.first - 1]++;
    }
    int index = 0;
    // search for the counter == 4 inside `v` vector
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

pair<bool, int> Comparator::isFullHouse(Deck tableCard, Deck playerCard)
{
    vector<pair<int, char>> v = mergeDeck(tableCard, playerCard);
    vector<pair<int, char>> filteredV = this->getNonSingle(v);
    vector<pair<int, char>> pair, triplet;
    map<int, int> freq;
    for (const auto ele : filteredV)
    {
        freq[ele.first]++;
    }
    for (int i = filteredV.size() - 1; i > 0; i--)
    {
        if (freq[filteredV[i].first] == 3)
        {
            triplet.push_back(filteredV[i]);
        }
        if (freq[filteredV[i].first] == 2)
        {
            pair.push_back(filteredV[i]);
        }
    }
    if (pair.size() != 0 && triplet.size() != 0)
        return {true, triplet[0].first};
    if (pair.size() == 0 && triplet.size() > 1)
        return {true, triplet[0].first};
    return {false, -1};
}

pair<bool, char> Comparator::isFlush(Deck tableCard, Deck playerCard)
{
    // color count format = "Hijau", "Biru", "Kuning", "Merah"
    vector<int> v(4, 0);
    vector<pair<int, char>> mergedCard = mergeDeck(tableCard, playerCard);
    // check each color count
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
    // find flush color
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
    // loop all cards
    for (int i = MAX_PLAYER_CARD - 1; i > 0; i--)
    {
        if (mergedCard[i].first - mergedCard[i - 1].first == 1)
        {
            count++;
            // find the biggest type for this card to maximize combo
            if (count < 5)
            {
                pair<int, char> selectedPair = findBiggest(mergedCard, mergedCard[i].first);
                result.second += this->searchVal(selectedPair.first, selectedPair.second);
            }
            if (count == 4)
            {
                // if count == 4, exit loop
                pair<int, char> selectedPair = findBiggest(mergedCard, mergedCard[i - 1].first);
                result.second += this->searchVal(selectedPair.first, selectedPair.second);
                result.first = true;
                break;
            }
        }
        // reset count if found uncomplete pattern
        else if (mergedCard[i].first - mergedCard[i - 1].first != 1 && mergedCard[i].first - mergedCard[i - 1].first != 0)
        {
            count = 0;
            result.second = 0.0;
        }
    }
    return result;
}

pair<int, char> Comparator::findBiggest(vector<pair<int, char>> v, int number)
{
    vector<pair<int, char>> filteredV;
    // filtered out the other numbers except `number`
    copy_if(v.begin(), v.end(), back_inserter(filteredV), [number](pair<int, char> x)
            { return x.first - number == 0; });
    float maxVal = 0.0;
    pair<int, char> resultPair = filteredV[0];
    // if more than 1 `number` in total cards
    if (filteredV.size() > 1)
    {
        // find the biggest type
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

pair<bool, int> Comparator::isThreeKind(Deck tableCard, Deck playerCard)
{
    vector<pair<int, char>> v = mergeDeck(tableCard, playerCard);
    vector<pair<int, char>> filteredV = this->getNonSingle(v);
    map<int, int> freq;
    for (const auto ele : filteredV)
    {
        freq[ele.first]++;
    }
    for (int i = filteredV.size() - 1; i >= 0; i--)
    {
        if (freq[filteredV[i].first] == 3)
        {
            return {true, filteredV[i].first};
        }
    }
    return {false, -1};
}

pair<bool, vector<pair<int, char>>> Comparator::isTwoPair(Deck tableCard, Deck playerCard)
{
    vector<pair<int, char>> v = mergeDeck(tableCard, playerCard);
    vector<pair<int, char>> allPairs = findPair(tableCard, playerCard);
    pair<bool, vector<pair<int, char>>> result = {false, {}};

    if (allPairs.size() > 1)
    {
        result.first = true;
        for (int i = 0; i < 4; i++)
        {
            result.second.push_back(allPairs[i]);
        }
    }
    return result;
}

pair<bool, float> Comparator::isPair(Deck tableCard, Deck playerCard)
{
    vector<pair<int, char>> v = mergeDeck(tableCard, playerCard);
    vector<pair<int, char>> filteredV = this->getNonSingle(v);
    map<int, int> freq;
    for (const auto ele : filteredV)
    {
        freq[ele.first]++;
    }
    for (int i = filteredV.size() - 1; i > 0; i--)
    {
        if (freq[filteredV[i].first] == 2)
        {
            return {true, searchVal(filteredV[i]) + searchVal(filteredV[i - 1])};
        }
    }
    return {false, -1};
}

vector<pair<int, char>> Comparator::findPair(Deck tableCard, Deck playerCard)
{
    if (isPair(tableCard, playerCard).first)
    {
        vector<pair<int, char>> pairV, temp;
        vector<pair<int, char>> v = mergeDeck(tableCard, playerCard);
        temp = this->getNonSingle(v);
        map<int, int> freq;
        for (const auto ele : temp)
        {
            freq[ele.first]++;
        }
        for (int i = temp.size() - 1; i >= 0; i--)
        {
            if (freq[temp[i].first] == 2)
            {
                pairV.push_back(temp[i]);
            }
        }

        return pairV;
    }
    else
    {
        NoPairFound e;
        throw e;
    }
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

vector<pair<int, char>> Comparator::mergeDeck(vector<pair<int, char>> firstDeck, vector<pair<int, char>> secondDeck)
{
    vector<pair<int, char>> v = firstDeck;
    for (int i = 0; i < secondDeck.size(); i++)
    {
        v.push_back(secondDeck[i]);
    }
    return v;
}

vector<pair<int, char>> Comparator::getNonSingle(Deck mergedDeck)
{
    vector<pair<int, char>> multiVector;
    // map each of the element into frequencies map
    map<int, int> freqEle;
    for (const auto pair : mergedDeck.getDeckCard())
    {
        freqEle[pair.first]++;
    }
    // copy all element that have freq > 1
    for (const auto pair : mergedDeck.getDeckCard())
    {
        if (freqEle[pair.first] > 1)
        {
            multiVector.push_back(pair);
        }
    }
    sort(multiVector.begin(), multiVector.end(), [&](const pair<int, char> &p1, const pair<int, char> &p2)
         { return compare(p1, p2); });

    return multiVector;
}

float Comparator::getStrongestCombination(Deck gameCard, Deck playerCard)
{
    // Cek dari tinggi
}

float Comparator::searchVal(pair<int, char> card)
{
    return searchVal(card.first, card.second);
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

bool Comparator::compare(const pair<int, char> &p1, const pair<int, char> &p2)
{
    // If the first elements are different, compare them
    if (p1.first != p2.first)
    {
        return p1.first < p2.first;
    }
    // If the first elements are equal, compare the second elements using the map values
    else
    {
        return this->color.at(p1.second) < this->color.at(p2.second);
    }
}
