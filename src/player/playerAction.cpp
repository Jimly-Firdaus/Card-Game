#include <iostream>
#include "Player.hpp"
#include "AbilityLess.hpp"
#include "Quadruple.hpp"
#include "Quarter.hpp"
#include "Reroll.hpp"
#include "ReverseDirection.hpp"
#include "SwapCard.hpp"
#include "Switch.hpp"
#include "GameState.hpp"

using namespace std;

/*Function overriding here
Class: PlayerAction extends dari Player buatKombinasi
Attr: abilityCard
Method: getCombination, (double, next, half, useAbility (pure virtual)) 
*/

// Constructor    
PlayerAction::PlayerAction(enum abilityCardList)
{
    enum abilityCard{AbilityLess, Quadruple, Quarter, Reroll, ReverseDirection, SwapCard, Switch}
    used = false;
}

PlayerAction::PlayerAction(enum abilityCard)
{
    
}

// Getter
int PlayerAction::getCombination() // Menampilkan kombinasi yang mungkin dari kartu yang dimiliki oleh pemain
{

}

int PlayerAction::nextAction() // Aksi dimana tidak terjadi perubahan poin game dan langsung menuju pemain selanjutnya
{
    
}

void PlayerAction::doubleAction() // Aksi dimana poin game menjadi dua kali lipat dari sebelumnya
{
    Gamestate::doubleRewardPoint();
}

void PlayerAction::halfAction() // Aksi dimana poin game menjadi setengahnya
{
    GameState::halfRewardPoint();
}

void PlayerAction::useAbility() // Aksi dimana pemain menggunakan kartu ability yang dimilikinya
{
    
}