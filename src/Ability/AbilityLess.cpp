#include "AbilityLess.hpp"
#include <bits/stdc++.h>
using namespace std;

void AbilityLess::getCardInfo()
{
    cout << "Abilityless, mematikan kartu ability milik pemain lain. Harus digunakan saat giliran (preventif), tidak bisa mencegah seperti mematikan kartu ability ketika ada yang memakai. Sehingga, apabila semua pemain selain pemegang kemampuan ini sudah memakai kemampuan, maka secara tidak langsung pemegang kemampuan ini terkena abilityless (karena semua kartu kemampuan sudah dipakai) dan harus memilih aksi selain power." << endl;
}

void AbilityLess::callCard(PlayerAction &player)
{
    try
    {
        player.setUsed();
    }
    catch (HaveBeenUsed e)
    {
        e.what();
        cout << "Your card is useless now!" << endl;
    }
}