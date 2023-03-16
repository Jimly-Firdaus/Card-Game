#ifndef _PLAYERCOLLECTION_HPP_
#define _PLAYERCOLLECTION_HPP_
// #include "playerAction.hpp"
#include "../Comparator/Comparator.hpp"
// #include <bits/stdc++.h>
// #include <vector>
// using namespace std;

class PlayerCollection{
    private:
        vector<PlayerAction> player;
        int Neff;
    public:
        PlayerCollection();
        vector<PlayerAction> getPlayer();
        int getNeff();
        bool checkTarget(string nickNameTarget, string nickNameCurrent);
        void printAllPlayer();
        int getTargetIdx(string targetNickName);
};

#endif