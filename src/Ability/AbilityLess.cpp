#include "AbilityLess.hpp"
// #include <bits/stdc++.h>

void AbilityLess::getCardInfo()
{
    cout << "Abilityless, mematikan kartu ability milik pemain lain. Harus digunakan saat giliran (preventif), tidak bisa mencegah seperti mematikan kartu ability ketika ada yang memakai. Sehingga, apabila semua pemain selain pemegang kemampuan ini sudah memakai kemampuan, maka secara tidak langsung pemegang kemampuan ini terkena abilityless (karena semua kartu kemampuan sudah dipakai) dan harus memilih aksi selain power." << endl;
}

void AbilityLess::callCard(vector<PlayerAction> &player, GameState &state, Deck &deck, PlayerAction& currentPlayer)
{
    cout << "Here is your target!" << endl;
    printTarget(player, currentPlayer);
    bool correctInput = false;
    string choice;
    while (!correctInput)
    {
        try
        {
            choice = getInput(player, currentPlayer);
            correctInput = true;
        }
        catch (WrongChoice e)
        {
            e.what();
        }
    }
    int idx = player.getTargetIdx(choice);
    setCardOff(player[idx]);
}

void AbilityLess::setCardOff(PlayerAction &chosenPlayer)
{
    try
    {
        chosenPlayer.setUsed(true);
    }
    catch (HaveBeenUsed e)
    {
        e.what();
        cout << "Your card is useless now!" << endl;
    }
}

string AbilityLess::getInput(vector<PlayerAction> &player, PlayerAction& currentPlayer)
{
    cout << "Please choose which player you want to target (include nickname) : ";
    string choice;
    cin >> choice;
    if (!player.checkTarget(choice, currentPlayer.getNickName()))
    {
        WrongChoice e;
        throw e;
    }
    else
    {
        return choice;
    }
}

void AbilityLess::printTarget(vector<PlayerAction> &player, PlayerAction& currentPlayer)
{
    int n = 1;
    for (int i = 0; i < 7; i++)
    {
        if (player[i].getNickName() != currentPlayer.getNickName())
        {
            cout << n << ". " << player.getPlayer()[i].getNickName();
            n++;
        }
    }
}

bool AbilityLess::checkTarget(string nickNameTarget, string nickNameCurrent, vector<PlayerAction>& player){
    if(nickNameTarget == nickNameCurrent){
        WrongChoice e;
        throw e;
    }else{
        for(int i= 0; i< player.size(); i++){
            if(player[i].getNickName() == nickNameTarget){
                return true;
            }else{
                WrongChoice e;
                throw e;
            }
        }
    }
    return false;
}