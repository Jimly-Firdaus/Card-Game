#ifndef COMPARATOR_HPP
#define COMPARATOR_HPP

#include "Handler.hpp"

template <class T>
class Comparator : public Handler {
    public:
        vector<T> sortVector(vector<T>);
};

template <>
class Comparator<Combination> : public Handler {
    public:
        pair<string, string> compare(const vector<Combination>&);
};

#endif