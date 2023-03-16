#include "Combination.hpp"

// Default Ctor
Combination::Combination(Deck tableCard, Deck playerCard, string nickname) : tableCard(tableCard), playerCard(playerCard)
{
    this->cardOwner = nickname;
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

Combination::Combination(const Combination &other)
{
    this->cardOwner = other.cardOwner;
    this->tableCard = other.tableCard;
    this->playerCard = other.playerCard;
    this->valueTable = other.valueTable;
    this->color = other.color;
    this->baseValue = other.baseValue;
    for (int i = 0; i < 4; i++)
    {
        this->avail_chars[i] = other.avail_chars[i];
    }
}

Combination &Combination::operator=(const Combination &other)
{
    if (this != &other)
    {
        this->cardOwner = other.cardOwner;
        this->tableCard = other.tableCard;
        this->playerCard = other.playerCard;
        this->valueTable = other.valueTable;
        this->color = other.color;
        this->baseValue = other.baseValue;
        for (int i = 0; i < 4; i++)
        {
            this->avail_chars[i] = other.avail_chars[i];
        }
    }
    return *this;
}

pair<bool, float> Combination::isStraightFlush()
{
    // check whether flush or not to continue check straight
    if (isFlush().first)
    {
        vector<pair<int, char>> mergedCard = mergeDeck(this->tableCard, playerCard);
        vector<pair<int, char>> flushCard;
        // filter out the non-flush type
        for (int i = 0; i < mergedCard.size(); i++)
        {
            if (mergedCard[i].second == isFlush().second.second)
                flushCard.push_back(mergedCard[i]);
        }
        // check straight for the filtered cards
        if (straightCombination(flushCard).first)
        {
            return {true, straightCombination(flushCard).second};
        }
    }
    return {false, 0.0};
}

pair<bool, int> Combination::isFourKind()
{
    vector<int> v(13, 0);
    vector<pair<int, char>> mergedCard = mergeDeck(this->tableCard, playerCard);
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

pair<bool, int> Combination::isFullHouse(bool checkTable)
{
    vector<pair<int, char>> v;
    if (!checkTable)
    {
        v = mergeDeck(this->tableCard, playerCard);
    }
    else
    {
        v = this->tableCard.getCards();
    }
    vector<pair<int, char>> filteredV = this->getNonSingle(v);
    vector<pair<int, char>> pair, triplet;
    map<int, int> freq;
    for (const auto ele : filteredV)
    {
        freq[ele.first]++;
    }
    for (int i = filteredV.size() - 1; i >= 0; i--)
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
    if (pair.size() == 0 && triplet.size() > 3)
        return {true, triplet[0].first};
    return {false, -1};
}

pair<bool, pair<int, char>> Combination::isFlush()
{
    // color count format = "Hijau", "Biru", "Kuning", "Merah"
    vector<int> v(4, 0);
    vector<pair<int, char>> mergedCard = mergeDeck(this->tableCard, playerCard);
    pair<bool, pair<int, char>> result = {false, {0, ' '}};
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
    // sort to get the max flush number
    mergedCard = sortDeck(mergedCard);
    // find flush color
    for (auto &ele : v)
    {
        index++;
        if (ele >= 5)
        {
            for (int i = mergedCard.size() - 1; i >= 0; i--)
            {
                if (mergedCard[i].second == this->avail_chars[index - 1])
                {
                    result = {true, {mergedCard[i].first, mergedCard[i].second}};
                    return result;
                }
            }
        }
    }
    return result;
}

pair<bool, float> Combination::isStraight()
{
    vector<pair<int, char>> mergedCard = mergeDeck(this->tableCard, playerCard);
    Deck mergedDeck(mergedCard);

    return straightCombination(mergedDeck);
}

pair<bool, float> Combination::straightCombination(Deck mergedDeck)
{
    pair<bool, float> result = {false, 0.0};
    int count = 0;
    vector<pair<int, char>> mergedCard = sortDeck(mergedDeck.getCards());
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

pair<int, char> Combination::findBiggest(vector<pair<int, char>> v, int number)
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

pair<bool, int> Combination::isThreeKind(bool checkTable)
{
    vector<pair<int, char>> v;
    if (!checkTable)
    {
        v = mergeDeck(this->tableCard, playerCard);
    }
    else
    {
        v = this->tableCard.getCards();
    }
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

pair<bool, vector<pair<int, char>>> Combination::isTwoPair(bool checkTable)
{
    vector<pair<int, char>> allPairs = findPair(checkTable);
    // for (auto ele : allPairs) {
    //     cout << ele.first << "," << ele.second << " | ";
    // }
    // cout << endl;
    pair<bool, vector<pair<int, char>>> result = {false, {}};
    if (allPairs.size() > 3)
    {
        result.first = true;
        for (int i = 0; i < 4; i++)
        {
            result.second.push_back(allPairs[i]);
        }
    }
    return result;
}

pair<bool, float> Combination::isPair(bool checkTable)
{
    vector<pair<int, char>> v;
    if (!checkTable)
    {
        v = mergeDeck(this->tableCard, playerCard);
    }
    else
    {
        v = this->tableCard.getCards();
    }
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

vector<pair<int, char>> Combination::findPair(bool checkTable)
{
    vector<pair<int, char>> pairV, temp;
    if (isPair(checkTable).first)
    {
        vector<pair<int, char>> v;
        if (!checkTable)
        {
            v = mergeDeck(this->tableCard, playerCard);
        }
        else
        {
            v = this->tableCard.getCards();
        }
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
    }

    return pairV;
}

vector<pair<int, char>> Combination::mergeDeck(Deck firstDeck, Deck secondDeck)
{
    return mergeDeck(firstDeck.getCards(), secondDeck.getCards());
}

vector<pair<int, char>> Combination::mergeDeck(vector<pair<int, char>> firstDeck, vector<pair<int, char>> secondDeck)
{
    vector<pair<int, char>> v = firstDeck;
    for (int i = 0; i < secondDeck.size(); i++)
    {
        v.push_back(secondDeck[i]);
    }
    return v;
}

vector<pair<int, char>> Combination::getNonSingle(Deck mergedDeck)
{
    vector<pair<int, char>> multiVector;
    // map each of the element into frequencies map
    map<int, int> freqEle;
    for (const auto pair : mergedDeck.getCards())
    {
        freqEle[pair.first]++;
    }
    // copy all element that have freq > 1
    for (const auto pair : mergedDeck.getCards())
    {
        if (freqEle[pair.first] > 1)
        {
            multiVector.push_back(pair);
        }
    }
    multiVector = sortDeck(multiVector);

    return multiVector;
}

vector<pair<int, char>> Combination::sortDeck(Deck mergedDeck)
{
    return sortDeck(mergedDeck.getCards());
}

vector<pair<int, char>> Combination::sortDeck(vector<pair<int, char>> mergedDeck)
{
    vector<pair<int, char>> multiVector = mergedDeck;
    sort(multiVector.begin(), multiVector.end(), [&](const pair<int, char> &p1, const pair<int, char> &p2)
         { return compare(p1, p2); });
    return multiVector;
}

float Combination::searchVal(pair<int, char> card) const
{
    return searchVal(card.first, card.second);
}

float Combination::searchVal(int number, char type) const
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
        cout << "cant find: {" << number << "," << type << "}" << endl;
        throw e;
    }
}
template <class T, class U>
bool Combination::compare(const pair<T, U> &p1, const pair<T, U> &p2)
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

pair<int, char> Combination::getHighCard()
{
    vector<pair<int, char>> v = playerCard.getCards();
    sort(v.begin(), v.end(), [&](const pair<int, char> &p1, const pair<int, char> &p2)
         { return compare(p1, p2); });
    return v[MAX_HAND_CARD - 1];
}

pair<float, string> Combination::getStrongestCombination()
{
    // Cek dari rendah -> paling bawah paling kuat override result
    pair<float, string> result = {searchVal(getHighCard()), "High Card"}; // defaults to high card
    auto pair = isPair();
    auto twoPair = isTwoPair();
    auto threeKind = isThreeKind();
    auto straight = isStraight();
    auto flush = isFlush();
    auto fullHouse = isFullHouse();
    auto fourKind = isFourKind();
    auto straightFlush = isStraightFlush();

    // Check each condition and update the result accordingly
    if (pair.first)
        result = {pair.second + PAIR_POINT, "Pair"};
    if (twoPair.first)
        result = {searchVal(twoPair.second[0]) + searchVal(twoPair.second[1]) + searchVal(twoPair.second[2]) + searchVal(twoPair.second[3]) + TWO_PAIR_POINT, "Two Pair"};
    if (threeKind.first)
        result = {searchVal(threeKind.second, 'M') + THREEKIND_POINT, "Three Of Kind"};
    if (straight.first)
        result = {straight.second + STRAIGHT_POINT, "Straight"};
    if (flush.first)
        result = {searchVal(flush.second.first, flush.second.second) + FLUSH_POINT, "Flush"};
    if (fullHouse.first)
        result = {searchVal(fullHouse.second, 'M') + FULLHOUSE_POINT, "Full House"};
    if (fourKind.first)
        result = {searchVal(fourKind.second, 'M') + FOURKIND_POINT, "Four of Kind"};
    if (straightFlush.first)
        result = {straightFlush.second + STRAIGHTFLUSH_POINT, "Straight Flush"};
    return result;
}

float Combination::getStrongestSelf()
{
    vector<pair<int, char>> playerCard = this->playerCard.getCards();
    if (playerCard[0].first == playerCard[1].first)
        return searchVal(playerCard[0]) + searchVal(playerCard[1]);
    else
        return searchVal(playerCard[0]) > searchVal(playerCard[1])
                   ? searchVal(playerCard[0])
                   : searchVal(playerCard[1]);
}

bool Combination::operator<(Combination &other)
{
    return this->getStrongestCombination() < other.getStrongestCombination();
}

bool Combination::operator>(Combination &other)
{
    return this->getStrongestCombination() > other.getStrongestCombination();
}

bool Combination::operator==(Combination &other)
{
    return this->getStrongestCombination() == other.getStrongestCombination();
}

Deck Combination::getPlayerCard() const
{
    return this->playerCard;
}

Deck Combination::getTableCard() const
{
    return this->tableCard;
}

string Combination::getOwnerCard() const
{
    return this->cardOwner;
}
