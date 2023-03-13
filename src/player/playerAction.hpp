#ifndef PLAYERACTION_HPP
#define PLAYERACTION_HPP

#include "Player.hpp"

/*Function overriding here
Class: PlayerAction extends dari Player buatKombinasi
Attr: abilityCard
Method: getCombination, (double, next, half, useAbility (pure virtual)) 
*/

class PlayerAction : public player {
    public:
    // Getter
    int getCombination(); // Menampilkan kombinasi yang mungkin dari kartu yang dimiliki oleh pemain

    void nextAction(string action); // Aksi dimana tidak terjadi perubahan poin game dan langsung menuju pemain selanjutnya
    void doubleAction(string action); // Aksi dimana poin game menjadi dua kali lipat dari sebelumnya
    void halfAction(string action); // Aksi dimana poin game menjadi setengahnya

    virtual void useAbility() = 0; // Aksi dimana pemain menggunakan kartu ability yang dimilikinya
};

#endif