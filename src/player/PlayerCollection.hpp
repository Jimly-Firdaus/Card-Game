#ifndef _PLAYERCOLLECTION_HPP_
#define _PLAYERCOLLECTION_HPP_
#include "playerAction.hpp"
#include <bits/stdc++.h>
using namespace std;

class PlayerCollection : public PlayerAction{
    private:
        vector<PlayerAction> player;
        int Neff;
    public:
        PlayerCollection();
        vector<PlayerAction> getPlayer();
        int getNeff();
        int printAllPlayer();
};

#endif