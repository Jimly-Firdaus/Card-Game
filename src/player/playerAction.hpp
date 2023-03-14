#ifndef PLAYERACTION_HPP
#define PLAYERACTION_HPP

#include "player.hpp"
#include "../Ability/AbilityLess.hpp"
#include "../Ability/Quadruple.hpp"
#include "../Ability/Quarter.hpp"
#include "../Ability/Reroll.hpp"
#include "../Ability/ReverseDirection.hpp"
#include "../Ability/SwapCard.hpp"
#include "../Ability/Switch.hpp"
#include "../Combination/Combination.hpp"
#include "../GameState/GameState.hpp"
#include 
using namespace std;

/*Function overriding here
Class: PlayerAction extends dari Player buatKombinasi
Attr: abilityCard
Method: getCombination, (double, next, half, useAbility (pure virtual))
*/

class PlayerAction : public Player {
    private:
    string PlayerAbiliy;
    bool abilityUsed;

public:
    // Constructor
    PlayerAction();
    // PlayerAction(Deck & fullCard);
    // PlayerAction(bool abilityUsed);

    // // Getter
    // int getCombination(Deck tableCard); // Menampilkan kombinasi yang mungkin dari kartu yang dimiliki oleh pemain

    // virtual void setPlayerAction(); // Aksi (next/double/half) yang dilakukan oleh pemain
    // void nextAction();              // Aksi dimana tidak terjadi perubahan poin game dan langsung menuju pemain selanjutnya
    // void doubleAction();            // Aksi dimana poin game menjadi dua kali lipat dari sebelumnya
    // void halfAction();              // Aksi dimana poin game menjadi setengahnya

    // void useAbility(); // Aksi dimana pemain menggunakan kartu ability yang dimilikinya
    // // terima parameter abilityCard
    // // ability.pointer = new [call card]
    void setUsed(bool);
    // bool getUsed();
};

#endif