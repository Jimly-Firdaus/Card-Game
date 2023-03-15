#include "playerAction.hpp"

PlayerAction::PlayerAction() : Player() {
    this->abilityUsed = false;
    this->PlayerAbility = "none";
}

void PlayerAction::getAbilityCard(vector<string>& AbilityCard){
    int randNumber = rand() % AbilityCard.size();
    this->PlayerAbility = AbilityCard[randNumber];
    AbilityCard.erase(AbilityCard.begin()+randNumber);
}

void PlayerAction::playerPlay(){
    
}

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

void PlayerAction::DOUBLE(GameState& state){
    int earlyReward = state.getRewardPoint();
    state.doubleRewardPoint();
    cout << getNickName() << " melakukan DOUBLE! Poin hadiah naik dari " << earlyReward << " menjadi " << state.getRewardPoint() << "!" << endl;
}

void PlayerAction::REROLL(Deck& deck){
    if(this->PlayerAbility == "Re-Roll"){
            if(abilityUsed){
            HaveBeenUsed e;
            throw e;
        }else{
            getOwnedCard().getCards().clear();
            getCard(deck);
            cout << "Melakukan pembuangan kartu yang dimiliki" << endl;
            cout << "Kamu mendapatkan 2 kartu yang baru yaitu:" << endl;
            deck.printCard();
        }
    }else{
        WrongAbilityCard e;
        throw e;
    }
}

void PlayerAction::QUADRUPLE(GameState& state){
    if(this->PlayerAbility == "Quadruple"){
            if(abilityUsed){
            HaveBeenUsed e;
            throw e;
        }else{
            int earlyReward = state.getRewardPoint();
            state.fourtimesRewardPoint();
            cout << getNickName() << " melakukan QUADRUPLE! Poin hadiah naik dari " << earlyReward << " menjadi " << state.getRewardPoint() << "!" << endl;
        }
    }else{
        WrongAbilityCard e;
        throw e;
    }
}

void PlayerAction::REVERSE(GameState& state){
    if(this->PlayerAbility == "ReverseDirection"){
        if(abilityUsed){
            cout << "Oops, kartu ability reversemu telah dimatikan sebelumnya :(" << endl;
            cout << "Silahkan lakukan perintah lain." << endl;
        }else{
            cout << getNickName() << " melakukan reverse!" << endl;
            
        }
    }else{
        WrongAbilityCard e;
        throw e;
    }
}

void PlayerAction::NEXT(){
    cout << "Giliran dilanjut ke pemain selanjutnya." << endl;
}

void PlayerAction::SWAPCARD(vector<PlayerAction>& players, bool random){
    if(this->PlayerAbility == "SwapCard"){
        if(abilityUsed){
            HaveBeenUsed e;
            throw e;
        }else{
            cout << getNickName() << " melakukan SWAPCARD." << endl;
            int choice1;
            int choice2;
            vector<PlayerAction> target;
            bool valid = false;
            while(!valid){
                cout << "Silahkan pilih pemain yang kartunya ingin anda tukar:" << endl;
                target = printTarget(getNickName(), players, "0");
                try{
                    choice1 = getInput(target.size());
                    valid = true;
                }catch(WrongChoice e){
                    e.what();
                }
            }
            string firstPick = target[choice1-1].getNickName();
            choice1 = findIndex(target[choice1-1], players);
            target.clear();
            valid = false;
            while(!valid){
                cout << "Silahkan pilih pemain yang kartunya ingin anda tukar:" << endl;
                target = printTarget(getNickName(), players, firstPick);
                try{
                    choice2 = getInput(target.size());
                    valid = true;
                }catch(WrongChoice e){
                    e.what();
                }
            }
            choice2 = findIndex(target[choice2-1], players);
            int index1;
            int index2;
            if(random){
                index1 = rand() % 2 + 1;
                index2 = rand() % 2 + 1;
            }else{
                valid = false;
                while(!valid){
                    cout << "Silahkan pilih kartu kanan/kiri " << players[choice1].getNickName() << endl;
                    cout << "1. Kanan" << endl;
                    cout << "2. Kiri" << endl;
                    try{
                        index1 = getInput(2);
                        valid = true;
                    }catch(WrongChoice e){
                        e.what();
                    }
                }
                valid = false;
                while(!valid){
                    cout << "Silahkan pilih kartu kanan/kiri " << players[choice2].getNickName() << endl;
                    cout << "1. Kanan" << endl;
                    cout << "2. Kiri" << endl;
                    try{
                        index2 = getInput(2);
                        valid = true;
                    }catch(WrongChoice e){
                        e.what();
                    }
                }
            }
            pair<int, char> firstCard = players[choice1].getOwnedCard().getACard(index1-1);
            pair<int, char> secondCard = players[choice2].getOwnedCard().getACard(index2-1);
            players[choice1].getOwnedCard().setACard(index1-1, secondCard);
            players[choice2].getOwnedCard().setACard(index2-1, firstCard);
        }
    }else{
        WrongAbilityCard e;
        throw e;
    }
}

void PlayerAction::SWITCH(vector<PlayerAction>& players){
    if(this->PlayerAbility == "Switch"){
        if(abilityUsed){
            HaveBeenUsed e;
            throw e;
        }else{
            cout << getNickName() << " melakukan switch!" << endl;
            int choice;
            vector<PlayerAction> target;
            cout << "Kartumu sekarang adalah:" << endl;
            getOwnedCard().printCard();
            bool valid = false;
            while(!valid){
                cout << "Silahkan pilih pemain yang kartunya ingin anda tukar:" << endl;
                target = printTarget(getNickName(), players, "0");
                try{
                    choice = getInput(target.size());
                    valid = true;
                }catch(WrongChoice e){
                    e.what();
                }
            }
            choice = findIndex(target[choice-1], players);
            Deck temp = getOwnedCard();
            getOwnedCard() = players[choice].getOwnedCard();
            players[choice].getOwnedCard() = temp;
            cout << "Kedua kartu " << getNickName() << " telah ditukar dengan " << players[choice].getNickName() << endl;
            cout << "Kartumu sekarang adalah:" << endl;
            getOwnedCard().printCard();
        }
    }else{
        WrongAbilityCard e;
        throw e;
    }
}

void PlayerAction::ABILITYLESS(vector<PlayerAction>& players){
    if(this->PlayerAbility == "AbilityLess"){
        if(abilityUsed){
            HaveBeenUsed e;
            throw e;
        }else{
            if(allTargetUsedAbilityCard(players, getNickName())){
                AllTargetUsedAbilityCard e;
                throw e;
            }else{
                cout << getNickName() << " akan mematikan ability lawan!" << endl;
                int choice;
                vector<PlayerAction> target;
                bool valid = false;
                while(!valid){
                    cout << "Silahkan pilih pemain yang kartu abilitinya ingin anda matikan:" << endl;
                    target = printTarget(getNickName(), players, "0");
                    try{
                        choice = getInput(target.size());
                        valid = true;
                    }catch(WrongChoice e){
                        e.what();
                    }
                }
                choice = findIndex(target[choice-1], players);
                try{
                    players[choice].setUsed(true);
                }catch(HaveBeenUsed e){
                    cout << "Kartu ability " << players[choice].getNickName() << " telah dipakai sebelumnya. Yah, sayang penggunaan kartu ini sia-sia." << endl;
                }
            }
        }
    }else{
        WrongAbilityCard e;
        throw e;
    }
}

void PlayerAction::setUsed(bool abilityUse){
    if(this->abilityUsed){
        HaveBeenUsed e;
        throw e;
    }else{
        this->abilityUsed = true;
    }
}

bool PlayerAction::allTargetUsedAbilityCard(vector<PlayerAction> players, string nickName){
    for(int i= 0; i< players.size(); i++){
        if(players[i].getNickName() != nickName && !players[i].getUsed()){
            return false;
        }
    }
    return true;
}

bool PlayerAction::getUsed(){
    return abilityUsed;
}

vector<PlayerAction> PlayerAction::printTarget(string nickName, vector<PlayerAction>& players, string firstPick){
    int number = 1;
    vector<PlayerAction> target;
    if(firstPick == "0"){
        for(auto player: players){
            if(player.getNickName() != nickName){
                cout << number << ". " << player.getNickName() << endl;
                target.push_back(player);
                number++;
            }
        }
    }else{
        for(auto player: players){
            if(player.getNickName() != nickName && player.getNickName() != firstPick){
                cout << number << ". " << player.getNickName() << endl;
                target.push_back(player);
                number++;
            }
        }
    }
    return target;
}

int PlayerAction::findIndex(PlayerAction target, vector<PlayerAction>& players){
    for(int i= 0; i< players.size(); i++){
        if(target.getNickName() == players[i].getNickName()){
            return i;
        }
    }
}

int PlayerAction::getInput(int n){
    int choice;
    cin >> choice;
    if(choice >= 1 && choice <=n){
        return choice;
    }else{
        WrongChoice e;
        throw e;
    }
}

void PlayerAction::HALF(GameState& state){
    if(state.getRewardPoint()>1){
        int earlyReward = state.getRewardPoint();
        state.halfRewardPoint();
        cout << getNickName() << " melakukan HALF! Poin hadiah turun dari " << earlyReward << " menjadi " << state.getRewardPoint() << "!" << endl;
    }else{
        LeftOne e;
        throw e;
    }
}

void PlayerAction::QUARTER(GameState& state){
    if(this->PlayerAbility == "Quarter"){
        if(abilityUsed){
            HaveBeenUsed e;
            throw e;
        }else{
            if(state.getRewardPoint()>1){
                int earlyReward = state.getRewardPoint();
                state.quarterRewardPoint();
                cout << getNickName() << " melakukan QUARTER! Poin hadiah turun dari " << earlyReward << " menjadi " << state.getRewardPoint() << "!" << endl;
            }else{
                LeftOne e;
                throw e;
            }
        }
    }else{
        WrongAbilityCard e;
        throw e;
    }
}

string PlayerAction::getAbility(){
    return this->PlayerAbility;
}

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
    cout << "Ability Card : " << getAbility() << endl;
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
