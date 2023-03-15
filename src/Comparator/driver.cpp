#include "../Combination/Combination.hpp"
#include "Comparator.hpp"
#include <iostream>

int main()
{
    // vector<pair<int, char>> _table = {{2, 'M'},{3, 'M'},{4, 'M'},{5, 'M'},{6, 'M'}};
    // vector<pair<int, char>> _table = {{6, 'B'},{6, 'M'},{6, 'K'},{6, 'H'},{1, 'M'}};
    vector<pair<int, char>> _table = {{3, 'B'},{3, 'K'},{3, 'H'},{2, 'H'},{2, 'M'}};
    Deck table(_table);


    // Straight Flush
    vector<pair<int, char>> testDeck1 = {{1, 'H'},{9, 'B'}};
    // Flush
    vector<pair<int, char>> testDeck2 = {{2, 'K'},{8, 'M'}};
    vector<pair<int, char>> testDeck3 = {{13, 'B'},{13, 'K'}};
    
    Deck deck1(testDeck1);  
    Deck deck2(testDeck2);
    Deck deck3(testDeck3);

    Combination p1_combination (table, deck1, "Nickname1");
    Combination p2_combination (table, deck2, "Nickname2");
    Combination p3_combination (table, deck3, "Nickname3");
    cout << "TestVal : " << p2_combination.searchVal(1, 'H') << endl;
    cout << "TestVal : " << p2_combination.searchVal(1, 'B') << endl;
    cout << "TestVal : " << p2_combination.searchVal(1, 'K') << endl;
    cout << "TestVal : " << p2_combination.searchVal(1, 'M') << endl;
    vector<Combination> allPlayerCombination;
    // cout << p1_combination.getStrongestCombination().first << endl;
    cout << "---------------------" << endl;
    allPlayerCombination.push_back(p1_combination);
    allPlayerCombination.push_back(p2_combination);
    allPlayerCombination.push_back(p3_combination);
    // cout << allPlayerCombination[0].getStrongestCombination().first << "points" << endl;
    vector<Combination> checker;
    double maxCombo = 0;
    for (int i = 0; i < 3; i++) {
        if (allPlayerCombination[i].getStrongestCombination().first > maxCombo) maxCombo = allPlayerCombination[i].getStrongestCombination().first;
    }
    for (int i = 0; i < 3; i++) {
        if (allPlayerCombination[i].getStrongestCombination().first == maxCombo) {
            checker.push_back(allPlayerCombination[i]);
        }
    }
    if (checker.size() > 1) {
        cout << "Found: " << checker.size() << " player that have the same combo" << endl;
        cout << "Combo: " << checker[0].getStrongestCombination().second << endl;
        Comparator comparator;
        pair<string, string> winner = comparator.compare(checker);
        cout << "Winner: " << winner.first << "\nCombo: " << winner.second << endl;
    } else {
        cout << "Not found\n";
    }


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
    cout << "Nickname: " << p3_combination.getOwnerCard() << endl;
    cout << "Strongest Combo p3: " << p3_combination.getStrongestCombination().second << endl;
    if (p1_combination > p2_combination) {
        cout << "p1 > p2";
    } 
    else if (p1_combination == p2_combination) cout << "p1 == p2";
    else {
        cout << "p1 < p2";
    }

    return 0;
}
