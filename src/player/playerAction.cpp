#include "playerAction.hpp"

PlayerAction::PlayerAction():Player(){
    this->abilityUsed = false;
}

// void PlayerAction::getAbilityCard(vector<string>& AbilityCard){
//     int randNumber = rand() % AbilityCard.size();
//     this->PlayerAbility = AbilityCard[randNumber];
//     if(AbilityCard[randNumber] == "Re-Roll"){
//         this->ability = new Reroll();
//     }else if(AbilityCard[randNumber] == "Quadruple"){
//         this->ability = new Quadruple();
//     }else if(AbilityCard[randNumber] == "Quarter"){
//         this->ability = new Quarter();
//     }else if(AbilityCard[randNumber] == "ReverseDirection"){
//         this->ability = new ReverseDirection();
//     }else if(AbilityCard[randNumber] == "SwapCard"){
//         this->ability = new SwapCard();
//     }else if(AbilityCard[randNumber] == "Switch"){
//         this->ability = new Switch();
//     }else if(AbilityCard[randNumber] == "AbilityLess"){
//         this->ability = new AbilityLess();
//     }
//     AbilityCard.erase(AbilityCard.begin()+randNumber);

// }

// void PlayerAction::playerPlay(int currentRound, vector<PlayerAction>& player, GameState& state, Deck& deck, PlayerAction& currentPlayer){
//     printPlayerOption();
//     bool inputTrue = false;
//     while(!inputTrue){
//         try{
//             playerProcess(currentRound, player, state, deck, currentPlayer);
//             inputTrue = true;
//         }catch(WrongChoice e){
//             e.what();
//             cout << "Please reinput your choice" << endl;
//         }
//     }
// }

// void PlayerAction::playerProcess(int currentRound, vector<PlayerAction>& player, GameState& state, Deck& deck, PlayerAction& currentPlayer){
//     cout << "Please include the number : ";
//     int choice;
//     cin >> choice;
//     if(choice == 1){
//         DOUBLE(state);
//     }else if(choice == 2){
//         NEXT();
//     }else if(choice == 3){
//         HALF(state);
//     }else if(choice == 4){
//         ABILITY(player, state, deck, currentPlayer);
//     }else{
//         WrongChoice e;
//         throw e;
//     }
// }

// void PlayerAction::setUsed(bool abilityUsed){
//     this->abilityUsed = abilityUsed;
// }

// bool PlayerAction::getUsed(){
//     return this->abilityUsed;
// }

// void PlayerAction::DOUBLE(GameState& state){
//     state.doubleRewardPoint();
//     cout << "The table point has been doubled" << endl;
// }

// void PlayerAction::NEXT(){
//     cout << "Nothing done" << endl;
// }

// void PlayerAction::HALF(GameState& state){
//     state.halfRewardPoint();
//     cout << "The table point has been halfed" << endl;
// }

// string PlayerAction::getAbility(){
//     return this->PlayerAbility;
// }

// void PlayerAction::ABILITY(vector<PlayerAction>& player, GameState& state, Deck& deck, PlayerAction& currentPlayer){
//     this->ability->callCard(player, state, deck, currentPlayer);
//     this->abilityUsed = true;
// }

// void PlayerAction::getAbilityInfo(){
//     this->ability->getCardInfo();
// }

void PlayerAction::printPlayerInfo(){
    cout << "===================================" << endl;
    cout << "Nickname : " << this->nickName << endl;
    cout << "Point : " << this->playerPoint << endl;
    cout << "Card : " << endl;
    Player::getOwnedCard().printCard();
    cout << endl;
    // cout << "Ability Card : " << getAbility() << endl;
    // cout << "Description  : " << endl;
    // getAbilityInfo();
    // cout << endl;
    cout << "Status : ";
    if(this->abilityUsed){
        cout << "used";
    }else{
        cout << "not used";
    }
    cout << endl;
    cout << "===================================" << endl;
}
// // #include <iostream>
// // #include "playerAction.hpp"

// // using namespace std;

// // /*Function overriding here
// // Class: PlayerAction extends dari Player buatKombinasi
// // Attr: abilityCard
// // Method: getCombination, (double, next, half, useAbility (pure virtual))
// // */

// // // Constructor
// // PlayerAction::PlayerAction(Deck & fullCard, ) : Player(fullCard, abilityCards)
// // {
// //     abilityUsed = false;
// // }
// // // PlayerAction::PlayerAction(bool abilityUsed) : Player(Deck & fullCard, vector<string> & abilityCards)
// // // {
// // //     this->abilityUsed = abilityUsed;
// // // }

// // // Getter
// // // Menampilkan kombinasi yang mungkin dari kartu yang dimiliki oleh pemain
// // int PlayerAction::getCombination(Deck tableCard)
// // {
// //     Combination::Combination(tableCard, this->ownedCard);
// //     return Combination::getStrongestCombination();
// // }

// // // Aksi (next/double/half) yang dilakukan oleh pemain
// // void PlayerAction::setPlayerAction()
// // {
// //     string actionOption;
// //     cout << "Opsi Action Player : " << endl;
// //     cout << "   [NEXT] Randomize Card" << endl;
// //     cout << "   [HALF] Read From File" << endl;
// //     cout << "   [DOUBLE] Read From File" << endl;
// //     cout << "   [ABILITY] Read From File" << endl;
// //     cout << "Answer : ";
// //     cin >> actionOption;
// //     // Validasi input
// //     if (actionOption != "NEXT" && actionOption != "HALF" && actionOption != "DOUBLE" && actionOption != "ABILITY")
// //     {
// //         throw "Input Action Invalid!"; // EXCEPTION
// //     }
// //     else
// //     {
// //         if (actionOption == "NEXT")
// //             nextAction();
// //         else if (actionOption == "HALF")
// //             halfAction();
// //         else if (actionOption == "DOUBLE")
// //             doubleAction();
// //         else
// //         {
// //             useAbility();
// //         }
// //     }
// // }

// // // Aksi dimana tidak terjadi perubahan poin game dan langsung menuju pemain selanjutnya
// // void PlayerAction::nextAction()
// // {
// //     Gamestate::nextPlayerOrder();
// // }

// // // Aksi dimana poin game menjadi dua kali lipat dari sebelumnya
// // void PlayerAction::doubleAction()
// // {
// //     Gamestate::doubleRewardPoint();
// // }

// // // Aksi dimana poin game menjadi setengahnya
// // void PlayerAction::halfAction()
// // {
// //     GameState::halfRewardPoint();
// // }

// // // Aksi dimana pemain menggunakan kartu ability yang dimilikinya
// // void PlayerAction::useAbility()
// // {
// //     if (!abilityUsed)
// //     {
// //         /*
// //         switch(myAbility) {
// //             case "AbilityLess":
// //                 AbilityLess::callCard()
// //             case "Quadruple" :
// //                 Quadruple::callCard();
// //             case "Quarter" :
// //                 Quarter::callCard();
// //             case "Reroll" :
// //                 Reroll::callCard();
// //             case "ReverseDirection" :
// //                 ReverseDirection::callCard();
// //             case "SwapCard" :
// //                 SwapCard::callCard();
// //             case "Switch" :
// //                 Switch::callCard();
// //                 */
// //         // }
// //         abilityUsed = true;
// //     }
// //     else
// //     {
// //         throw "Your Ability Already Used\n"; // EXCEPTION
// //     }
// // }
