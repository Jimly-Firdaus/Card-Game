#ifndef COMPARATOR_HPP
#define COMPARATOR_HPP

#include "Handler.hpp"
#include "../player/playerAction.hpp"

template <class T>
class Comparator : public Handler {
    public:
        void sortVector(vector<T>&, bool asc);
        bool descCallbackFn(T, T);
        pair<string, string> compare(const vector<Combination>&);
        
};

template <>
class Comparator<Combination> : public Handler {
    public:
        pair<string, string> compare(const vector<Combination>&);
};

#endif