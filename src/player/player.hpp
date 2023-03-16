#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../GameState/GameState.hpp"

class Player
{
protected:
    Deck ownedCard; // Hand card yang dimiliki oleh setiap pemain (termasuk ability card)
    long long playerPoint;
    string nickName;

public:
    Player();
    void getCard(Deck& Deck); 
    long long getPlayerPoint(); 
    void setPlayerPoint(long long playerPoint); 
    void setNickName(string nickName);
    string getNickName();
    Deck getOwnedCard();
    void setACardPlayer(int idx, pair<int, char> card);
};

#endif