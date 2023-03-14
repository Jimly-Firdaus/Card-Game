#include "Comparator.hpp"

pair<string, string> Comparator::compare(vector<Combination> arrOfPlayerCombination)
{
    string type = arrOfPlayerCombination[0].getStrongestCombination().second;
    cout << "Type: " << type << endl;
    if (type == "Straight Flush")
        return straightFlushHandler(arrOfPlayerCombination);
    if (type == "Four of Kind")
        return fourKindHandler(arrOfPlayerCombination);
    if (type == "Full House")
        return fullHouseHandler(arrOfPlayerCombination);
    if (type == "Flush")
        return flushHandler(arrOfPlayerCombination);
    if (type == "Three Of Kind")
        return threeKindHandler(arrOfPlayerCombination);
    if (type == "Two Pair")
        return twoPairHandler(arrOfPlayerCombination);
    if (type == "Pair")
        return pairHandler(arrOfPlayerCombination);
    // if (type == "High Card") return highCardHandler(arrOfPlayerCombination);
    else
    {
        UncounterCombo e;
        throw e;
    }
}

pair<string, string> Comparator::straightFlushHandler(vector<Combination> arrOfPlayerCombination)
{
    vector<pair<int, char>> sortedTableDeck = arrOfPlayerCombination[0].sortDeck(arrOfPlayerCombination[0].getTableCard());
    char color = sortedTableDeck[0].second;
    int index = 0;
    // search for three kind
    int max = 0, indexWin = 0;
    index = 0;
    for (auto combination : arrOfPlayerCombination)
    {
        vector<pair<int, char>> mergedCard = combination.mergeDeck(combination.getTableCard(), combination.getPlayerCard());
        map<int, int> freq;
        for (auto ele : mergedCard)
        {
            freq[ele.first]++;
        }
        for (auto ele : mergedCard)
        {
            if (freq[ele.first] == 3)
            {
                if (max < ele.first)
                {
                    max = ele.first;
                    indexWin = index;
                }
            }
        }
        index++;
    }
    if (max != 0)
        return {arrOfPlayerCombination[indexWin].getOwnerCard(), "Straight Flush"};
    else
    {
        // search for pair
        int max = 0;
        index = 0;
        for (auto combination : arrOfPlayerCombination)
        {
            float pairValue = 0;
            int counter = 0;
            vector<pair<int, char>> mergedCard = combination.mergeDeck(combination.getTableCard(), combination.getPlayerCard());
            map<int, int> freq;
            for (auto ele : mergedCard)
            {
                freq[ele.first]++;
            }

            for (auto ele : mergedCard)
            {
                if (freq[ele.first] == 2)
                {
                    counter++;
                    pairValue += combination.searchVal(ele);
                    if (max < pairValue && counter == 2)
                    {
                        max = pairValue;
                        indexWin = index;
                    }
                }
            }
            index++;
        }
        if (max != 0)
        {
            return {arrOfPlayerCombination[indexWin].getOwnerCard(), "Straight Flush"};
        }
        else
        {
            // search for high card
            int max = 0, indexWin = 0;
            index = 0;
            for (auto combination : arrOfPlayerCombination)
            {
                float playerHighCardVal = combination.getStrongestSelf();
                if (max < playerHighCardVal)
                {
                    max = playerHighCardVal;
                    indexWin = index;
                }
                index++;
            }
            return {arrOfPlayerCombination[indexWin].getOwnerCard(), "Straight Flush"};
        }
    }
}

pair<string, string> Comparator::fullHouseHandler(vector<Combination> arrOfPlayerCombination)
{
    // TODO: pseudo code
}

pair<string, string> Comparator::flushHandler(vector<Combination> arrOfPlayerCombination)
{
    char color = arrOfPlayerCombination[0].getTableCard().getCards()[0].second;
    int winIndex = 0;
    vector<int> numbersCollection;
    // each of the player must have the same color with table flush (at least one)
    for (int i = 0; i < arrOfPlayerCombination.size(); i++)
    {
        pair<int, char> firstCard = arrOfPlayerCombination[i].getPlayerCard().getCards()[0];
        pair<int, char> secCard = arrOfPlayerCombination[i].getPlayerCard().getCards()[1];
        if (firstCard.second == color)
        {
            numbersCollection.push_back(firstCard.first);
        }
        if (secCard.second == color)
        {
            if (numbersCollection.size() == i + 1)
            {
                if (numbersCollection[i] < secCard.first)
                {
                    numbersCollection[i] = secCard.first;
                }
            }
            else
            {
                numbersCollection.push_back(secCard.first);
            }
        }
    }
    // Find the maximum element
    auto it = max_element(numbersCollection.begin(), numbersCollection.end());

    // Find the index of the maximum element
    int index = distance(numbersCollection.begin(), it);
    return {arrOfPlayerCombination[index].getOwnerCard(), "Flush"};
}

pair<string, string> Comparator::threeKindHandler(vector<Combination> arrOfPlayerCombination)
{
    vector<pair<int, char>> tableCard = arrOfPlayerCombination[0].getTableCard().getCards();
    map<int, int> freq;
    bool threeKind = false;
    for (auto card : tableCard)
    {
        freq[card.first]++;
        if (freq[card.first] == 3)
        {
            threeKind = true;
            break;
        }
    }
    float max = 0;
    int index = 0, winIndex = 0;
    if (threeKind)
    {
        for (auto combination : arrOfPlayerCombination)
        {
            double playerCardValue = combination.getStrongestSelf();
            if (max < playerCardValue)
            {
                max = playerCardValue;
                winIndex = index;
            }
            index++;
        }
    }
    else
    {
        int threeKindCard = arrOfPlayerCombination[0].isThreeKind().second;
        for (auto combination : arrOfPlayerCombination)
        {
            pair<int, char> firstCard = combination.getPlayerCard().getCards()[0];
            pair<int, char> secondCard = combination.getPlayerCard().getCards()[1];
            float max2;
            max2 = firstCard.first == threeKindCard
                       ? combination.searchVal(secondCard)
                       : combination.searchVal(firstCard);
            if (max < max2)
            {
                max = max2;
                winIndex = index;
            }
            index++;
        }
    }
    return {arrOfPlayerCombination[winIndex].getOwnerCard(), "Three of Kind"};
}

pair<string, string> Comparator::fourKindHandler(vector<Combination> arrOfPlayerCombination)
{
    pair<int, char> singleCard = getSingleCard(arrOfPlayerCombination);
    vector<Combination> c3;
    vector<Combination> c2;
    vector<Combination> c1;
    for (auto combination : arrOfPlayerCombination)
    {
        int i = 0;
        pair<int, char> firstCard = combination.getPlayerCard().getCards()[0];
        pair<int, char> secondCard = combination.getPlayerCard().getCards()[1];
        if (firstCard.first == singleCard.first)
            i++;
        if (secondCard.first == singleCard.first)
            i++;
        if (i == 2)
            c3.push_back(combination);
        if (i == 1 || firstCard.first == secondCard.first)
            c2.push_back(combination);
        if (i == 0)
            c1.push_back(combination);
    }
    if (c3.size() != 0)
    {
        // three kind
        return {c3[0].getOwnerCard(), "Four of Kind"};
    }
    else
    {
        // pair
        if (c2.size() != 0)
        {
            if (c2.size() == 1)
                return {c2[0].getOwnerCard(), "Four of Kind"};
            else
            {
                float max = 0;
                int index = 0, winIndex = 0;
                for (auto combination : c2)
                {
                    pair<int, char> firstCard = combination.getPlayerCard().getCards()[0];
                    pair<int, char> secondCard = combination.getPlayerCard().getCards()[1];
                    float max2;
                    if (firstCard.first != secondCard.first)
                    {
                        max2 = firstCard.first == singleCard.first
                                   ? combination.searchVal(firstCard) + combination.searchVal(singleCard)
                                   : combination.searchVal(secondCard) + combination.searchVal(singleCard);
                    }
                    else
                    {
                        max2 = combination.searchVal(firstCard) + combination.searchVal(secondCard);
                    }
                    if (max < max2)
                    {
                        max = max2;
                        winIndex = index;
                    }
                    index++;
                }
                return {c2[winIndex].getOwnerCard(), "Four of Kind"};
            }
        }
        else
        {
            // high card
            float max = 0;
            int index = 0, winIndex = 0;
            for (auto combination : c2)
            {
                pair<int, char> firstCard = combination.getPlayerCard().getCards()[0];
                pair<int, char> secondCard = combination.getPlayerCard().getCards()[1];
                float max2 = firstCard.first > secondCard.first
                                 ? combination.searchVal(firstCard)
                                 : combination.searchVal(secondCard);
                if (max < max2)
                {
                    max = max2;
                    winIndex = index;
                }
                index++;
            }
            return {c1[winIndex].getOwnerCard(), "Four of Kind"};
        }
    }
}

pair<string, string> Comparator::twoPairHandler(vector<Combination> arrOfPlayerCombination)
{
    pair<int, char> singleCard = getSingleCard(arrOfPlayerCombination);

    // check whether the hand can make a pair with singleCard
    bool pairable = arrOfPlayerCombination[0].getPlayerCard().getCards()[0].first == singleCard.first
                        ? true
                        : arrOfPlayerCombination[0].getPlayerCard().getCards()[1].first == singleCard.first;
    float max = 0;
    int index = 0;
    int winIndex = 0;
    for (auto combination : arrOfPlayerCombination)
    {
        pair<int, char> firstCard = combination.getPlayerCard().getCards()[0];
        pair<int, char> secondCard = combination.getPlayerCard().getCards()[1];
        float max2;
        if (pairable)
        {
            max2 = firstCard.first == singleCard.first
                       ? combination.searchVal(firstCard)
                       : combination.searchVal(secondCard);
        }
        else
        {
            max2 = combination.searchVal(firstCard) > combination.searchVal(secondCard)
                       ? combination.searchVal(firstCard)
                       : combination.searchVal(secondCard);
        }
        if (max < max2)
        {
            max = max2;
            winIndex = index;
        }
        index++;
    }
    return {arrOfPlayerCombination[winIndex].getOwnerCard(), "Two Pair"};
}

pair<string, string> Comparator::pairHandler(vector<Combination> arrOfPlayerCombination)
{
    vector<pair<int, char>> pairCard = arrOfPlayerCombination[0].findPair(); // get all the pairs
    int pairNum = pairCard[0].first;
    bool containPair = arrOfPlayerCombination[0].getPlayerCard().getCards()[0].first == pairNum
                           ? true
                           : arrOfPlayerCombination[0].getPlayerCard().getCards()[1].first == pairNum;
    float max = 0;
    int index = 0;
    int winIndex = 0;
    for (auto combination : arrOfPlayerCombination)
    {
        pair<int, char> firstCard = combination.getPlayerCard().getCards()[0];
        pair<int, char> secondCard = combination.getPlayerCard().getCards()[1];
        float max2;
        if (containPair)
        {
            // if there are hand that can produce pair
            max2 = firstCard.first == pairNum ? combination.searchVal(secondCard) : combination.searchVal(firstCard);
        }
        else
        {
            // if no hand can produce pair
            max2 = combination.searchVal(firstCard) > combination.searchVal(secondCard)
                       ? combination.searchVal(firstCard)
                       : combination.searchVal(secondCard);
        }
        if (max < max2)
        {
            max = max2;
            winIndex = index;
        }
        index++;
    }
    return {arrOfPlayerCombination[winIndex].getOwnerCard(), "Pair"};
}

pair<int, char> Comparator::getSingleCard(vector<Combination> arrOfPlayerCombination)
{
    vector<pair<int, char>> tableCard = arrOfPlayerCombination[0].getTableCard().getCards();
    map<int, int> freq;
    // find the card without pair
    for (auto card : tableCard)
    {
        freq[card.first]++;
    }
    pair<int, char> singleCard;
    for (auto card : tableCard)
    {
        if (freq[card.first] == 1)
        {
            singleCard = card;
            break;
        }
    }
    return singleCard;
}

// FOUR KIND CASE:
// table : 6 6 6 6 2
// p1 : 1 3
// p2 : 1 2

// PAIR CASE:
// table : 6 2 1 3 5
// p1 : 6 8
// p2 : 6 8
// p3 : 6 8

// table : 6 6 1 3 5
// p1 : 9 8
// p2 : 9 8
// p3 : 9 8
// ini cari dlu pairnya apa, trus bandingin playerCard yang bukan card pair

// TWO PAIR CASE:
// table : 1 2 8 9 5
// p1 : 1 2
// p2 : 1 2
// p3 : 1 2

// atau
// table : 1 2 7 9 2
// p1 : 1 8
// p2 : 1 3
// p3 : 1 4

// atau
// table : 1 2 1 9 2
// p1 : 8 7
// p2 : 8 7
// p3 : 8 7

// atau
// table : 5 5 3 3 2
// p1 : 2 7
// p2 : 2 7
// p3 : 2 7
