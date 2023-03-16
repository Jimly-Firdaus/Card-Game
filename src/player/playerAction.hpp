#ifndef PLAYERACTION_HPP
#define PLAYERACTION_HPP

#include "player.hpp"

class PlayerAction : public Player
{
private:
    string PlayerAbility;
    bool abilityUsed;

public:
    // Constructor
    PlayerAction();
    void getAbilityCard(vector<string> &AbilityCard);
    void playerPlay(Deck &deck, GameState &state, vector<PlayerAction> &players);
    void setUsed(bool abilityUse);
    bool getUsed();
    string getAbility();
    void REROLL(Deck &deck);
    void QUADRUPLE(GameState &state);
    void DOUBLE(GameState &state);
    void REVERSE(GameState &state);
    void SWAPCARD(vector<PlayerAction> &players, bool random);
    vector<PlayerAction> printTarget(string nickName, vector<PlayerAction> &players, string firstPick);
    int findIndex(PlayerAction target, vector<PlayerAction> &players);
    void SWITCH(vector<PlayerAction> &players);
    void ABILITYLESS(vector<PlayerAction> &players);
    bool allTargetUsedAbilityCard(vector<PlayerAction> players, string nickName);
    int getInput(int n);
    void NEXT();
    void HALF(GameState &state);
    void QUARTER(GameState &state);
    void printPlayerInfo();
    void setOwnedCard(const Deck &deck);
    bool operator<(PlayerAction &other);
    bool operator>(PlayerAction &other);
};

#endif