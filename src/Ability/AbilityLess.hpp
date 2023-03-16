#ifndef _ABILITYLESS_HPP_
#define _ABILITYLESS_HPP_
#include "Ability.hpp"

class AbilityLess : public Ability
{
public:
    void callCard(vector<PlayerAction>& player, GameState& state, Deck& deck, PlayerAction& currentPlayer);
    void getCardInfo();
    void setCardOff(PlayerAction& chosenPlayer);
    string getInput(vector<PlayerAction>& player, PlayerAction& currentPlayer);
    void printTarget(vector<PlayerAction>& player, PlayerAction& currentPlayer);
    int getTargetIdx(string targetNickName);
    bool checkTarget(string nickNameTarget, string nickNameCurrent,vector<PlayerAction>& player);
};



// int PlayerCollection::getTargetIdx(string targetNickName){
//     for(int i= 0; i<7; i++){
//         if(this->player[i].getNickName() == targetNickName){
//             return i;
//         }
//     }
// }

#endif