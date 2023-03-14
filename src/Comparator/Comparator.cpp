#include "Comparator.hpp"

pair<string, string> Comparator::compare(vector<Combination> arrOfPlayerCombination) {
    string type = arrOfPlayerCombination[0].getStrongestCombination().second;
    cout << "Type: " << type << endl;
    if (type == "Straight Flush") return straightFlushHandler(arrOfPlayerCombination);
    if (type == "Four Kind");
    if (type == "Full House") return fullHouseHandler(arrOfPlayerCombination);
    if (type == "Flush") return flushHandler(arrOfPlayerCombination);
    if (type == "Three of Kind") return threeKindHandler(arrOfPlayerCombination);
    if (type == "Two Pair");
    if (type == "Pair") return pairHandler(arrOfPlayerCombination);
    // if (type == "High Card") return highCardHandler(arrOfPlayerCombination);
    else {
        UncounterCombo e;
        throw e;
    }
}



pair<string, string> Comparator::straightFlushHandler(vector<Combination> arrOfPlayerCombination) {
    // TODO: implement
    // karena di meja udh straight flush -> cari kombinasi di bawah 4 kartu -> three kind, two pair, pair Per player
    // save point ke array baru
    // cari max point -> save index
    // pake index buat cari nickname terkuat
    // return
    pair<string, string> result;
    vector<bool> possibleThreeKind(arrOfPlayerCombination.size(), false);
    vector<bool> possibleTwoPair(arrOfPlayerCombination.size(), false);
    vector<bool> possiblePair(arrOfPlayerCombination.size(), false);
    int i = 0;
    for (auto combination : arrOfPlayerCombination) {
        if (combination.isThreeKind().first) possibleThreeKind[i] = true;
        i++;
    }
    if (count(possibleThreeKind.begin(), possibleThreeKind.end(), true) > 1) {
        int j = 0, max = 0;
        for (auto combination : arrOfPlayerCombination) {
            int currentCard = combination.isThreeKind().second;
            if (possibleThreeKind[j]) {
                if (max < currentCard) {
                    max = currentCard;
                    result.first = combination.getOwnerCard();
                    result.second = "Three of Kind";    
                }
            }
        }
    }

}

pair<string, string> Comparator::fullHouseHandler(vector<Combination> arrOfPlayerCombination) {
    // TODO: pseudo code
}

pair<string, string> Comparator::flushHandler(vector<Combination> arrOfPlayerCombination) {
    cout << "Called here\n"; 
    char color = arrOfPlayerCombination[0].getTableCard().getCards()[0].second;
    // TODO: implement
    // setiap player punya 2 card -> loop keduanya cari yang colornya sama dengan flush color
    // save setiap angka ke new arr
    // bandingin index max -> cari nickname terkuat berdasarkan index max
    // return
    int winIndex = 0;
    vector<int> numbersCollection;
    // each of the player must have the same color with table flush (at least one)
    for (int i = 0; i < arrOfPlayerCombination.size(); i++) {
        pair<int, char> firstCard = arrOfPlayerCombination[i].getPlayerCard().getCards()[0];
        pair<int, char> secCard = arrOfPlayerCombination[i].getPlayerCard().getCards()[1];
        if (firstCard.second == color) {
            numbersCollection.push_back(firstCard.first);
        }
        if (secCard.second == color) {
            if (numbersCollection.size() == i + 1) {
                if (numbersCollection[i] < secCard.first) {
                    numbersCollection[i] = secCard.first;
                }
            } else {
                numbersCollection.push_back(secCard.first);
            }
        }
    }
    // Find the maximum element
    auto it = max_element(numbersCollection.begin(), numbersCollection.end());

    // Find the index of the maximum element
    int index = distance(numbersCollection.begin(), it);
    cout << index << endl;
    return {arrOfPlayerCombination[index].getOwnerCard(), "Flush"};
}

pair<string, string> Comparator::threeKindHandler(vector<Combination> arrOfPlayerCombination) {
    // TODO: implement
    // karena case yang buat cari full house udah di counter di full house handler -> maka cuman bandingin kicker disini
    // cari pair yang di meja tersebut (udah pasti two pair di meja, cari angkanya buat ngematchin sama salah satu card player)
    // sisa 1 card itu jadi kicker buat pembanding pke high card
    // cari max, return
}

pair<string, string> Comparator::fourKindHandler(vector<Combination> arrOfPlayerCombination) {
    // TODO: implement
    
}

pair<string, string> Comparator::twoPairHandler(vector<Combination> arrOfPlayerCombination) {
    // TODO: implement
    
}

pair<string, string> Comparator::pairHandler(vector<Combination> arrOfPlayerCombination) {
    vector<pair<int, char>> pairCard = arrOfPlayerCombination[0].findPair(); // get all the pairs
    int pairNum = pairCard[0].first;
    bool containPair = arrOfPlayerCombination[0].getPlayerCard().getCards()[0].first == pairNum 
        ? true
        : arrOfPlayerCombination[0].getPlayerCard().getCards()[1].first == pairNum;
    float max = 0;
    int index = 0;
    int winIndex = 0;
    for (auto combination : arrOfPlayerCombination) {
        pair<int, char> firstCard = combination.getPlayerCard().getCards()[0];
        pair<int, char> secondCard = combination.getPlayerCard().getCards()[1];
        float max2;
        if (containPair) {
            // if there are hand that can produce pair
            max2 = firstCard.first == pairNum ? combination.searchVal(secondCard) : combination.searchVal(firstCard);
        } else {
            // if no hand can produce pair
            max2 = combination.searchVal(firstCard) > combination.searchVal(secondCard)
                ? combination.searchVal(firstCard)
                : combination.searchVal(secondCard);
        }
        if (max < max2) {
            max = max2;
            winIndex = index;
        }
        index++;
    }
    cout << "Index: " << containPair << endl;
    return {arrOfPlayerCombination[winIndex].getOwnerCard(), "Pair"};
}


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

