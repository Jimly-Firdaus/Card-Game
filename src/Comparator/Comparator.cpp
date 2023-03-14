#include "Comparator.hpp"

pair<string, string> Comparator::compare(vector<Combination> arrOfPlayerCombination) {
    string type = arrOfPlayerCombination[0].getStrongestCombination().second;
    if (type == "Straight Flush") return straightFlushHandler(arrOfPlayerCombination);
    if (type == "Full House") return fullHouseHandler(arrOfPlayerCombination);
    if (type == "Flush") return flushHandler(arrOfPlayerCombination);
    if (type == "Three of Kind") return threeKindHandler(arrOfPlayerCombination);
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