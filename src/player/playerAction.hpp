#ifndef PLAYERACTION_HPP
#define PLAYERACTION_HPP

#include "player.hpp"

/*Function overriding here
Class: PlayerAction extends dari Player buatKombinasi
Attr: abilityCard
Method: getCombination, (double, next, half, useAbility (pure virtual))
*/

<<<<<<< HEAD
class PlayerAction : public Player {
    private:
    enum abilityCard
    {
        AbilityLess,
        Quadruple,
        Quarter,
        Reroll,
        ReverseDirection,
        SwapCard,
        Switch
    };
    bool used;
=======
class PlayerAction : public Player
{
private:
    bool abilityUsed;
>>>>>>> c3533a0fd79f605c581b5eb8c95784aa8e607232

public:
    // Constructor
    PlayerAction();
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
    void setUsed(bool);
    // bool getUsed();
};

#endif