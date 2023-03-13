#include "Comparator.hpp"

pair<string, string> Comparator::compare(Combination *arrOfPlayerCombination) {
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

pair<string, string> Comparator::straightFlushHandler(Combination *arrOfPlayerCombination) {
    // TODO: implement
    // karena di meja udha straight flush -> cari kombinasi di bawah 4 kartu -> three kind, two pair, pair Per player
    // save point ke array baru
    // cari max point -> save index
    // pake index buat cari nickname terkuat
    // return


}

pair<string, string> Comparator::fullHouseHandler(Combination *arrOfPlayerCombination) {
    // TODO: pseudo code
}

pair<string, string> Comparator::flushHandler(Combination *arrOfPlayerCombination) {
    char color = arrOfPlayerCombination[0].getTableCard().getCards()[0].second;
    // TODO: implement
    // setiap player punya 2 card -> loop keduanya cari yang colornya sama dengan flush color
    // save setiap angka ke new arr
    // bandingin index max -> cari nickname terkuat berdasarkan index max
    // return
    
}

pair<string, string> Comparator::threeKindHandler(Combination *arrOfPlayerCombination) {
    // TODO: implement
    // karena case yang buat cari full house udah di counter di full house handler -> maka cuman bandingin kicker disini
    // cari pair yang di meja tersebut (udah pasti two pair di meja, cari angkanya buat ngematchin sama salah satu card player)
    // sisa 1 card itu jadi kicker buat pembanding pke high card
    // cari max, return
}