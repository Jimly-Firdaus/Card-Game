#include <iostream>
#include "Player.hpp"
#include "../Ability/AbilityLess.hpp"
#include "../Ability/Quadruple.hpp"
#include "../Ability/Quarter.hpp"
#include "../Ability/Reroll.hpp"
#include "../Ability/ReverseDirection.hpp"
#include "../Ability/SwapCard.hpp"
#include "../Ability/Switch.hpp"
#include "Combination.hpp"
// #include "GameState.hpp"

using namespace std;

/*Function overriding here
Class: PlayerAction extends dari Player buatKombinasi
Attr: abilityCard
Method: getCombination, (double, next, half, useAbility (pure virtual))
*/

// Constructor
PlayerAction::PlayerAction(Deck & fullCard, vector<string> & abilityCards) : Player()
{
    abilityUsed = false;
}
PlayerAction::PlayerAction(bool abilityUsed) : Player(Deck & fullCard, vector<string> & abilityCards)
{
    this->abilityUsed = abilityUsed;
}

// Getter
// Menampilkan kombinasi yang mungkin dari kartu yang dimiliki oleh pemain
int PlayerAction::getCombination(Deck tableCard)
{
    Combination::Combination(tableCard, this->ownedCard);
    return Combination::getStrongestCombination();
}

// Aksi (next/double/half) yang dilakukan oleh pemain
void PlayerAction::setPlayerAction()
{
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

// Aksi dimana tidak terjadi perubahan poin game dan langsung menuju pemain selanjutnya
void PlayerAction::nextAction()
{
    Gamestate::nextPlayerOrder();
}

// Aksi dimana poin game menjadi dua kali lipat dari sebelumnya
void PlayerAction::doubleAction()
{
    Gamestate::doubleRewardPoint();
}

// Aksi dimana poin game menjadi setengahnya
void PlayerAction::halfAction()
{
    GameState::halfRewardPoint();
}

// Aksi dimana pemain menggunakan kartu ability yang dimilikinya
void PlayerAction::useAbility()
{
    if (!abilityUsed)
    {
        switch(myAbility) {
            case "AbilityLess":
                AbilityLess::callCard()
            case "Quadruple" :
                Quadruple::callCard();
            case "Quarter" :
                Quarter::callCard();
            case "Reroll" :
                Reroll::callCard();
            case "ReverseDirection" :
                ReverseDirection::callCard();
            case "SwapCard" :
                SwapCard::callCard();
            case "Switch" :
                Switch::callCard();
        }
        abilityUsed = true;
    }
    else
    {
        throw "Your Ability Already Used\n" // EXCEPTION
    }
}