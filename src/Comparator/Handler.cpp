#include "Handler.hpp"

pair<string, string> Handler::deepCompare(vector<Combination> arrOfPlayerCombination)
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

pair<string, string> Handler::straightFlushHandler(vector<Combination> arrOfPlayerCombination)
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

pair<string, string> Handler::fullHouseHandler(vector<Combination> arrOfPlayerCombination)
{
    Combination playerCombination = arrOfPlayerCombination[0];
    bool isTableFullHouse = playerCombination.isFullHouse(true).first;
    bool isTableTwoPair = playerCombination.isTwoPair(true).first;
    bool isTableThreeKind = playerCombination.isThreeKind(true).first && !playerCombination.isPair(true).first;
    float max = 0;
    int index = 0, winIndex = 0;
    if (isTableTwoPair)
    {
        int poloCard = playerCombination.isFullHouse().second;
        for (auto combination : arrOfPlayerCombination)
        {
            pair<int, char> firstCard = combination.getPlayerCard().getCards()[0];
            pair<int, char> secondCard = combination.getPlayerCard().getCards()[1];
            pair<int, char> playerPoloCard = firstCard.first == poloCard
                                                 ? firstCard
                                                 : secondCard;
            float playerPoloVal = combination.searchVal(playerPoloCard);
            if (max < playerPoloVal)
            {
                max = playerPoloVal;
                winIndex = index;
            }
            index++;
        }
        return {arrOfPlayerCombination[winIndex].getOwnerCard(), "Full House"};
    }
    if (isTableThreeKind)
    {
        max = 0;
        index = 0;
        winIndex = 0;
        for (auto combination : arrOfPlayerCombination)
        {
            float playerMaxPair = combination.isPair().second;
            if (max < playerMaxPair)
            {
                max = playerMaxPair;
                winIndex = index;
            }
            index++;
        }
        return {arrOfPlayerCombination[winIndex].getOwnerCard(), "Full House with Highest Pair"};
    }
    if (isTableFullHouse)
    {
        pair<string, string> result = getPossibleOfOne(arrOfPlayerCombination);
        return {result.first, "Full House with " + result.second};
    }
    return {"", ""};
}

pair<string, string> Handler::flushHandler(vector<Combination> arrOfPlayerCombination)
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

pair<string, string> Handler::threeKindHandler(vector<Combination> arrOfPlayerCombination)
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

pair<string, string> Handler::fourKindHandler(vector<Combination> arrOfPlayerCombination)
{
    pair<string, string> result = getPossibleOfOne(arrOfPlayerCombination);
    return {result.first, "Four of Kind with " + result.second};
}

pair<string, string> Handler::twoPairHandler(vector<Combination> arrOfPlayerCombination)
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

pair<string, string> Handler::pairHandler(vector<Combination> arrOfPlayerCombination)
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
            max2 = firstCard.first == pairNum
                       ? combination.searchVal(secondCard)
                       : combination.searchVal(firstCard);
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

pair<int, char> Handler::getSingleCard(vector<Combination> arrOfPlayerCombination)
{
    vector<pair<int, char>> tableCard = arrOfPlayerCombination[0].getTableCard().getCards();
    map<int, int> freq;
    // find the card without pair
    for (auto card : tableCard)
    {
        freq[card.first]++;
    }
    pair<int, char> singleCard = {-1, ' '};
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

pair<string, string> Handler::getPossibleOfOne(vector<Combination> arrOfPlayerCombination)
{
    pair<int, char> singleCard = getSingleCard(arrOfPlayerCombination).first == -1 ? make_pair(0, ' ') : getSingleCard(arrOfPlayerCombination);
    if (singleCard.first != -1)
    {

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
            return {c3[0].getOwnerCard(), "Three of Kind kicker"};
        }
        else
        {
            // pair
            if (c2.size() != 0)
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
                return c2.size() == 1
                           ? make_pair(c2[0].getOwnerCard(), "Pair kicker")
                           : make_pair(c2[winIndex].getOwnerCard(), "Pair kicker");
            }
            else
            {
                // high card
                float max = 0;
                int index = 0, winIndex = 0;
                for (auto combination : c1)
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
                return {c1[winIndex].getOwnerCard(), "High Card kicker"};
            }
        }
    }
    else
    {
        float max = 0;
        int index = 0, winIndex = 0;
        for (auto combination : arrOfPlayerCombination)
        {
            pair<int, char> firstCard = combination.getPlayerCard().getCards()[0];
            pair<int, char> secondCard = combination.getPlayerCard().getCards()[1];
            float max2 = combination.getStrongestSelf();
            if (max < max2)
            {
                max = max2;
                winIndex = index;
            }
            index++;
        }
        return {arrOfPlayerCombination[winIndex].getOwnerCard(), "High Card kicker"};
    }
}
