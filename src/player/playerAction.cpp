#include <iostream>
#include "Player.hpp"
using namespace std;

/*Function overriding here
Class: PlayerAction extends dari Player buatKombinasi
Attr: abilityCard
Method: getCombination, (double, next, half, useAbility (pure virtual)) 
*/

// Constructor    
PlayerAction::PlayerAction()
{
    enum AbilityCard{AbilityLess, Quadruple, Quarter, Reroll, ReverseDirection, SwapCard, Switch}
}


// Getter
int PlayerAction::getCombination() // Menampilkan kombinasi yang mungkin dari kartu yang dimiliki oleh pemain
{

}

void PlayerAction::nextAction(string action) // Aksi dimana tidak terjadi perubahan poin game dan langsung menuju pemain selanjutnya
{

}

void PlayerAction::doubleAction(string action) // Aksi dimana poin game menjadi dua kali lipat dari sebelumnya
{

}

void PlayerAction::halfAction(string action) // Aksi dimana poin game menjadi setengahnya
{

}

virtual void PlayerAction::useAbility() = 0; // Aksi dimana pemain menggunakan kartu ability yang dimilikinya