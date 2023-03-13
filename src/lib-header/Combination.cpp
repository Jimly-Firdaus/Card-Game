#include "Combination.hpp"

// Default Ctor
Combination::Combination(Deck tableCard) : tableCard(tableCard)
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

pair<bool, float> Combination::isStraightFlush(Deck playerCard)
{
    // check whether flush or not to continue check straight
    if (isFlush(playerCard).first)
    {
        vector<pair<int, char>> mergedCard = mergeDeck(this->tableCard, playerCard);
        vector<pair<int, char>> flushCard;
        // filter out the non-flush type
        for (int i = 0; i < mergedCard.size(); i++)
        {
            if (mergedCard[i].second == isFlush(playerCard).second.second)
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

pair<bool, int> Combination::isFourKind(Deck playerCard)
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

pair<bool, int> Combination::isFullHouse(Deck playerCard)
{
    vector<pair<int, char>> v = mergeDeck(this->tableCard, playerCard);
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

pair<bool, pair<int, char>> Combination::isFlush(Deck playerCard)
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
            for (int i = mergedCard.size() - 1; i >= 0; i++)
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

pair<bool, float> Combination::isStraight(Deck playerCard)
{
    vector<pair<int, char>> mergedCard = mergeDeck(this->tableCard, playerCard);
    Deck mergedDeck(mergedCard);

    return straightCombination(mergedDeck);
}

pair<bool, float> Combination::straightCombination(Deck mergedDeck)
{
    pair<bool, float> result = {false, 0.0};
    int count = 0;
    vector<pair<int, char>> mergedCard = sortDeck(mergedDeck.getDeckCard());
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

pair<bool, int> Combination::isThreeKind(Deck playerCard)
{
    vector<pair<int, char>> v = mergeDeck(this->tableCard, playerCard);
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

pair<bool, vector<pair<int, char>>> Combination::isTwoPair(Deck playerCard)
{
    vector<pair<int, char>> mergedCard = mergeDeck(this->tableCard, playerCard);
    vector<pair<int, char>> allPairs = findPair(playerCard);
    pair<bool, vector<pair<int, char>>> result = {false, {}};

    if (allPairs.size() > 2)
    {
        result.first = true;
        for (int i = 0; i < 4; i++)
        {
            result.second.push_back(allPairs[i]);
        }
    }
    return result;
}

pair<bool, float> Combination::isPair(Deck playerCard)
{
    vector<pair<int, char>> v = mergeDeck(this->tableCard, playerCard);
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

vector<pair<int, char>> Combination::findPair(Deck playerCard)
{
    vector<pair<int, char>> pairV, temp;
    if (isPair(playerCard).first)
    {
        // Deck copyTable(this->tableCard);
        vector<pair<int, char>> v = mergeDeck(this->tableCard, playerCard);
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
    return mergeDeck(firstDeck.getDeckCard(), secondDeck.getDeckCard());
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
    multiVector = sortDeck(multiVector);

    return multiVector;
}

vector<pair<int, char>> Combination::sortDeck(Deck mergedDeck)
{
    return sortDeck(mergedDeck.getDeckCard());
}

vector<pair<int, char>> Combination::sortDeck(vector<pair<int, char>> mergedDeck)
{
    vector<pair<int, char>> multiVector = mergedDeck;
    sort(multiVector.begin(), multiVector.end(), [&](const pair<int, char> &p1, const pair<int, char> &p2)
         { return compare(p1, p2); });
    return multiVector;
}

float Combination::searchVal(pair<int, char> card)
{
    return searchVal(card.first, card.second);
}

float Combination::searchVal(int number, char type)
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

bool Combination::compare(const pair<int, char> &p1, const pair<int, char> &p2)
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

pair<int, char> Combination::getHighCard(Deck playerCard)
{
    Deck copyTable(this->tableCard);
    vector<pair<int, char>> v = mergeDeck(copyTable, playerCard);
    sort(v.begin(), v.end(), [&](const pair<int, char> &p1, const pair<int, char> &p2)
         { return compare(p1, p2); });
    return v[MAX_PLAYER_CARD - 1];
}

pair<float, string> Combination::getStrongestCombination(Deck playerCard)
{
    // Cek dari rendah -> paling bawah paling kuat override result
    pair<float, string> result = {searchVal(getHighCard(playerCard)), "High Card"}; // defaults to high card
    auto pair = isPair(playerCard);
    auto twoPair = isTwoPair(playerCard);
    auto threeKind = isThreeKind(playerCard);
    auto straight = isStraight(playerCard);
    auto flush = isFlush(playerCard);
    auto fullHouse = isFullHouse(playerCard);
    auto fourKind = isFourKind(playerCard);
    auto straightFlush = isStraightFlush(playerCard);

    // Check each condition and update the result accordingly
    if (pair.first)
        result = {pair.second + PAIR_POINT, "Pair"};
    if (twoPair.first)
        result = {searchVal(twoPair.second[0]) + searchVal(twoPair.second[1]) + TWO_PAIR_POINT, "Two Pair"};
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

    /**
     * case waktu ngebandingin sama player lain
     * Untuk Straight Flush:
     *      1. Kalau terbentuk di meja -> cari kombinasi lain (pair, two pair, three kind)
     * Untuk Full House:
     *      1. Kalau Polo nya sama tapi pairnya ga sama -> cari highest pair
     *      2. Kalau Polo nya sama + pairnya sama -> cari highest kicker (kartu satu lagi yang ada di hand). Ini kalau Full Housenya dibentuk dengan salah satu dari kartu di hand
     *      3. Kalau Polo nya sama + pairnya sama (Full House di table + gad player yang bs ngebentuk FullHouse di meja) -> cari kombinasi tertinggi dari current hand
     * Untuk Flush:
     *      1. Kalau Flushnya di table + ada yang punya warna yang sama (>2) -> cari yang bisa ngebentuk flush maximum (sama kayak straight, cari max yang bisa dibentuk)
     *      2. Kalau Flushnya di table + gad yang punya warna yang sama -> cari kombinasi lain antara current hand + table cards
     * Untuk Straight:
     *      1. Kalau ada yang max nya sama -> bandingin colornya
     * Untuk Three Kind:
     *      1. Kalau ada pair sama di meja + ada 2 player yang bisa dapet three kind -> cari highest kicker atau cari yang bisa ngebentuk fullhouse (ini udah dicounter di full house)
     */

    return result;
}