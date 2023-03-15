#ifndef COMPARATOR_HPP
#define COMPARATOR_HPP

#include "Handler.hpp"

template <class T>
class Comparator : public Handler {
    public:
        /**
         * Sort the given vector. Defaults to ascending
         * @param asc 
         * @return * vector<T> 
         */
        vector<T> sortVector(vector<T>, bool asc = true);
        /**
         * Descending callback function for sortVector
         * @return true 
         * @return false 
         */
        bool descCallbackFn(T, T);
        pair<string, string> compare(const vector<Combination>&);
        
};

template <>
class Comparator<Combination> : public Handler {
    public:
        pair<string, string> compare(const vector<Combination>&);
};

#endif