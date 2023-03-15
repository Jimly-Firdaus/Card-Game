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
// #include "../Ability/Ability.hpp"
using namespace std;
class Ability;

/*Function overriding here
Class: PlayerAction extends dari Player buatKombinasi
Attr: abilityCard
Method: getCombination, (double, next, half, useAbility (pure virtual))
*/

class PlayerAction : public Player {
    private:
    Ability *ability;
    string PlayerAbility;
    bool abilityUsed;

public:
    // Constructor
    PlayerAction();
    void getAbilityCard(vector<string>& AbilityCard);
    void playerPlay(int currentRound, PlayerCollection& player, GameState& state, Deck& deck);
    void playerProcess(int currentRound, PlayerCollection& player, GameState& state, Deck& deck);
    void setUsed(bool);
    bool getUsed();
    string getAbility();
    void DOUBLE(GameState& state);
    void NEXT();
    void HALF(GameState& state);
    void ABILITY(PlayerCollection& player, GameState& state, Deck& deck);
    void getAbilityInfo();
    void printPlayerInfo();
    bool operator<(const PlayerAction& other);
    bool operator>(const PlayerAction& other);
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
    // bool getUsed();
};

#endif