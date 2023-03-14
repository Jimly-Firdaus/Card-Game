#ifndef PLAYERACTION_HPP
#define PLAYERACTION_HPP

#include "Player.hpp"

/*Function overriding here
Class: PlayerAction extends dari Player buatKombinasi
Attr: abilityCard
Method: getCombination, (double, next, half, useAbility (pure virtual))
*/

class PlayerAction : public Player
{
private:
    bool abilityUsed;

public:
    // Constructor
    PlayerAction(Deck & fullCard, vector<string> & abilityCards);
    PlayerAction(bool abilityUsed);

    // Getter
    int getCombination(Deck tableCard); // Menampilkan kombinasi yang mungkin dari kartu yang dimiliki oleh pemain

    virtual void setPlayerAction(); // Aksi (next/double/half) yang dilakukan oleh pemain
    void nextAction();              // Aksi dimana tidak terjadi perubahan poin game dan langsung menuju pemain selanjutnya
    void doubleAction();            // Aksi dimana poin game menjadi dua kali lipat dari sebelumnya
    void halfAction();              // Aksi dimana poin game menjadi setengahnya

    void useAbility(); // Aksi dimana pemain menggunakan kartu ability yang dimilikinya
    // terima parameter abilityCard
    // ability.pointer = new [call card]
};

#endif