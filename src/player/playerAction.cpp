#include <iostream>
#include "Player.hpp"
#include "../Ability/AbilityLess.hpp"
#include "../Ability/Quadruple.hpp"
#include "../Ability/Quarter.hpp"
#include "../Ability/Reroll.hpp"
#include "../Ability/ReverseDirection.hpp"
#include "../Ability/SwapCard.hpp"
#include "../Ability/Switch.hpp"
// #include "GameState.hpp"

using namespace std;

/*Function overriding here
Class: PlayerAction extends dari Player buatKombinasi
Attr: abilityCard
Method: getCombination, (double, next, half, useAbility (pure virtual))
*/

// Constructor
PlayerAction::PlayerAction()
{
    enum abilityCard
    {
        AbilityLess,
        Quadruple,
        Quarter,
        Reroll,
        ReverseDirection,
        SwapCard,
        Switch
    } used = false;
}

// Getter
int PlayerAction::getCombination() // Menampilkan kombinasi yang mungkin dari kartu yang dimiliki oleh pemain
{
}

void PlayerAction::setPlayerAction()
{ // Aksi (next/double/half) yang dilakukan oleh pemain
    string actionOption;
    cout << "Opsi Action Player : " << endl;
    cout << "   [NEXT] Randomize Card" << endl;
    cout << "   [HALF] Read From File" << endl;
    cout << "   [DOUBLE] Read From File" << endl;
    cout << "   [ABILITY] Read From File" << endl;
    cout << "Answer : ";
    cin >> actionOption;
    // Validasi input
    if (actionOption != "NEXT" && actionOption != "HALF" && actionOption != "DOUBLE" && actionOption != "ABILITY")
    {
        throw "Input Action Invalid!"; // EXCEPTION
    }
    else
    {
        if (actionOption == "NEXT")
            nextAction();
        else if (actionOption == "HALF")
            halfAction();
        else if (actionOption == "DOUBLE")
            doubleAction();
        else
        {
            useAbility();
        }
    }
}
void PlayerAction::nextAction(string action) // Aksi dimana tidak terjadi perubahan poin game dan langsung menuju pemain selanjutnya
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

void PlayerAction::setUsed(){
    if(this->used){
        this->used = false;
    }else{
        HaveBeenUsed e;
        throw e;
    }
}