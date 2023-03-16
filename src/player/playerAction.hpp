// #ifndef PLAYERACTION_HPP
// #define PLAYERACTION_HPP

#include "player.hpp"
// #include "../Ability/AbilityLess.hpp"
// #include "../Ability/Quadruple.hpp"
// #include "../Ability/Quarter.hpp"
// #include "../Ability/Reroll.hpp"
// #include "../Ability/ReverseDirection.hpp"
// #include "../Ability/SwapCard.hpp"
// #include "../Ability/Switch.hpp"
// #include "../Combination/Combination.hpp"
// #include "../GameState/GameState.hpp"
// // #include "../Ability/Ability.hpp"
// // using namespace std;
// class Ability;

// /*Function overriding here
// Class: PlayerAction extends dari Player buatKombinasi
// Attr: abilityCard
// Method: getCombination, (double, next, half, useAbility (pure virtual))
// */

class PlayerAction : public Player {
    private:
    // Ability *ability;
    string PlayerAbility;
    bool abilityUsed;

public:
    // Constructor
    PlayerAction();
    void getAbilityCard(vector<string>& AbilityCard); // partial
    void playerPlay(Deck& deck, GameState& state, vector<PlayerAction>& players);
    // void playerProcess(int currentRound, vector<PlayerAction>& player, GameState& state, Deck& deck, PlayerAction& currentPlayer);
    void setUsed(bool abilityUse);
    bool getUsed();
    string getAbility(); // done
    void REROLL(Deck& deck);
    void QUADRUPLE(GameState& state);
    void DOUBLE(GameState& state); // done
    void REVERSE(GameState& state); 
    void SWAPCARD(vector<PlayerAction>& players, bool random);
    vector<PlayerAction> printTarget(string nickName, vector<PlayerAction>& players, string firstPick);
    int findIndex(PlayerAction target, vector<PlayerAction>& players);
    void SWITCH(vector<PlayerAction>& players);
    void ABILITYLESS(vector<PlayerAction>& players);
    bool allTargetUsedAbilityCard(vector<PlayerAction> players, string nickName);
    int getInput(int n);
    void NEXT(); // done
    void HALF(GameState& state); // done
    void QUARTER(GameState& state);
    // void ABILITY(vector<PlayerAction>& player, GameState& state, Deck& deck, PlayerAction& currentPlayer);
    // void getAbilityInfo();
    void printPlayerInfo(); // done
    bool operator<(PlayerAction& other);
    bool operator>(PlayerAction& other);
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

// #endif