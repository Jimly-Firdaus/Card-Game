#include "AbilityLess.hpp"
// #include <bits/stdc++.h>

void AbilityLess::getCardInfo()
{
    cout << "Abilityless, mematikan kartu ability milik pemain lain. Harus digunakan saat giliran (preventif), tidak bisa mencegah seperti mematikan kartu ability ketika ada yang memakai. Sehingga, apabila semua pemain selain pemegang kemampuan ini sudah memakai kemampuan, maka secara tidak langsung pemegang kemampuan ini terkena abilityless (karena semua kartu kemampuan sudah dipakai) dan harus memilih aksi selain power." << endl;
}

void AbilityLess::callCard(PlayerCollection &player, GameState &state, Deck &deck)
{
    cout << "Here is your target!" << endl;
    printTarget(player);
    bool correctInput = false;
    string choice;
    while (!correctInput)
    {
        try
        {
            choice = getInput(player);
            correctInput = true;
        }
        catch (WrongChoice e)
        {
            e.what();
        }
    }
    int idx = player.getTargetIdx(choice);
    setCardOff(player.getPlayer()[idx]);
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

string AbilityLess::getInput(PlayerCollection &player)
{
    cout << "Please choose which player you want to target (include nickname) : ";
    string choice;
    cin >> choice;
    if (!player.checkTarget(choice, this->nickName))
    {
        WrongChoice e;
        throw e;
    }
    else
    {
        return choice;
    }
}

void AbilityLess::printTarget(PlayerCollection &player)
{
    int n = 1;
    for (int i = 0; i < 7; i++)
    {
        if (player.getPlayer()[i].getNickName() != this->nickName)
        {
            cout << n << ". " << player.getPlayer()[i].getNickName();
            n++;
        }
    }
}