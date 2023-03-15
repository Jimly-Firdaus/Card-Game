#include "Comparator.hpp"

template <class T>
vector<T> Comparator<T>::sortVector(vector<T> v, bool asc) {
    if (asc) return sort(v.begin(), v.end()); 
    else return sort(v.begin(), v.end(), descCallbackFn);
}

template <class T>
bool Comparator<T>::descCallbackFn(T a, T b) {
    return a > b;
}

template <class T>
pair<string, string> Comparator<T>::compare(const vector<Combination>& v) {
    return Handler::compare(v);
}

pair<string, string> Comparator<Combination>::compare(const vector<Combination>& arrOfPlayerCombination) {
    vector<Combination> checker;
    double maxCombo = 0;
    for (auto combination : arrOfPlayerCombination) {
        if (combination.getStrongestCombination().first > maxCombo) maxCombo = combination.getStrongestCombination().first;
    }
    for (auto combination : arrOfPlayerCombination) {
        if (combination.getStrongestCombination().first == maxCombo) {
            checker.push_back(combination);
        }
    }
    if (checker.size() == 1) return {checker[0].getOwnerCard(), checker[0].getStrongestCombination().second};
    else return deepCompare(checker);
}