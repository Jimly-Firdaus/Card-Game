#include "Combination.hpp"
#include <iostream>

int main()
{
    vector<pair<int, char>> _table = {{3, 'M'},{3, 'B'},{1, 'H'},{2, 'K'},{2, 'M'}};
    Deck table(_table);


    // Straight Flush
    vector<pair<int, char>> testDeck1 = {{2, 'H'},{13, 'K'}};
    // Flush
    vector<pair<int, char>> testDeck2 = {{2, 'B'},{6, 'K'}};

    
    Deck deck1(testDeck1);  
    Deck deck2(testDeck2);

    Combination p1_combination (table, deck1, "Nickname1");
    Combination p2_combination (table, deck2, "Nickname2");
    cout << "TestVal : " << p2_combination.searchVal(13, 'H') << endl;
    cout << "TestVal : " << p2_combination.searchVal(13, 'B') << endl;
    cout << "TestVal : " << p2_combination.searchVal(13, 'K') << endl;
    cout << "TestVal : " << p2_combination.searchVal(13, 'M') << endl;

    if (p1_combination.isTwoPair(true).first) cout << "Table two pair\n";
    else cout << "No table\n";
    if (p1_combination.isTwoPair().first) cout << "Full house combo!\n";
    else cout << "No full house\n";

    // if (combination.isFlush(deck2).first) {
    //     cout << "Flush!" << endl;
    //     cout << "Type : " << combination.isFlush(deck2).second.second << endl;
    //     cout << "Max num : " << combination.isFlush(deck2).second.first << endl;
    // }
    // else cout << "No Flush!\n";

    // if (combination.isStraight(deck1).first) {
    //     cout << "Straight \n";
    //     cout << "Straight value : " << combination.isStraight(deck1).second << endl;
    // } else cout << "No Straight\n";

    // if (combination.isFourKind(deck1).first) {
    //     cout << "Four Kind \n";
    //     cout << "Four Kind card : " << combination.isFourKind(deck1).second << endl;
    // } else cout << "No Four Kind\n";

    // if (combination.isStraightFlush(deck1).first) {
    //     cout << "Straight Flush\n";
    //     cout << "Straight Flush value : " << combination.isStraightFlush(deck1).second << endl;
    // } else cout << "No Straight\n";

    // if (combination.isPair(table, deck1).first) {
    //     cout << "Pair value " << combination.isPair(table, deck1).second << endl;
    // } else {
    //     cout << "No Pair" << endl;
    // }

    // if (combination.isTwoPair(deck1).first) {
    //     cout << "Two pair value " << combination.isPair(deck1).second << endl;
    //     for (auto& p : combination.isTwoPair(deck1).second) {
    //         cout << "{" << p.first << "," << p.second << "} ";
    //     }
    //     cout << endl;
    // } else {
    //     cout << "No Two Pair" << endl;
    // }

    // if (combination.isThreeKind(table, deck1).first) {
    //     cout << "Three of Kind Card: " << combination.isThreeKind(table, deck1).second << endl;
    //     cout << endl;
    // } else {
    //     cout << "No Three Kind" << endl;
    // }

    // if (combination.isFullHouse(deck1).first) {
    //     cout << "Polo Card: " << combination.isFullHouse(deck1).second << endl;
    //     cout << endl;
    // } else {
    //     cout << "No Full House gohome" << endl;
    // }
    cout << "Deck valuation: " << p1_combination.getStrongestCombination().first << "," << p2_combination.getStrongestCombination().first << endl;
    cout << "Nickname: " << p1_combination.getOwnerCard() << endl;
    cout << "Strongest Combo p1: " << p1_combination.getStrongestCombination().second << endl;
    cout << "Nickname: " << p2_combination.getOwnerCard() << endl;
    cout << "Strongest Combo p2: " << p2_combination.getStrongestCombination().second << endl;
    if (p1_combination > p2_combination) {
        cout << "p1 < p2";
    } 
    else if (p1_combination == p2_combination) cout << "p1 == p2";
    else {
        cout << "p1 > p2";
    }

    return 0;
}
