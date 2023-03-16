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

void PlayerAction::playerPlay(Deck& deck, GameState& state, vector<PlayerAction>& players){
    cout << "Turn: " << getNickName() << endl;
    printPlayerInfo();
    cout << "Command: ";
    string command;
    cin >> command;
    if(command == "NEXT" || command == "REROLL" || command == "DOUBLE" || command == "QUADRUPLE" || command == "HALF" || command == "QUARTER" || command == "REVERSE" || command == "SWAPCARDRANDOM" || command == "SWAPCARD" || command == "SWITCH" || command == "ABILITYLESS")
    {
        if(command == "NEXT"){
            NEXT();
        }else if(command == "REROLL"){
            try{
                REROLL(deck);
                setUsed(true);
            }catch(HaveBeenUsed e){
                cout << "Kartu Reroll " <<  e.what() << endl;
                playerPlay(deck, state, players);
            }catch (WrongAbilityCard e){
                cout << e.what() << "Reroll" << endl;
                playerPlay(deck, state, players);
            }
        }else if(command == "DOUBLE"){
            DOUBLE(state);
        }else if(command == "QUADRUPLE"){
            try{
                QUADRUPLE(state);
                setUsed(true);
            }catch(WrongAbilityCard e){
                cout << e.what() << "Quadruple" << endl;
                playerPlay(deck, state, players);
            }
        }else if(command == "HALF"){
            try{
                HALF(state);
            }catch(exception& e){
                cout << e.what() << endl;
            }
        }else if(command == "QUARTER"){
            try{
                QUARTER(state);
                setUsed(true);
            }catch(LeftOne e){
                cout << e.what() << endl;
            }catch(WrongAbilityCard e){
                cout << e.what() << endl;
                playerPlay(deck, state, players);
            }
        }else if(command == "REVERSE"){
            try{
                REVERSE(state);
                setUsed(true);
            }catch(HaveBeenUsed e){
                cout << "Oops, kartu ability reversemu telah dimatikan sebelumnya :(" << endl;
                cout << "Silahkan lakukan perintah lain." << endl;
                playerPlay(deck, state, players);
            }catch (WrongAbilityCard e){
                cout << e.what() << "Reverse" << endl;
                playerPlay(deck, state, players);
            }
        }else if(command == "SWAPCARDRANDOM"){
            try{
                SWAPCARD(players, true);
                setUsed(true);
            }catch(HaveBeenUsed e){
                cout << "Kartu Swapcard " <<  e.what() << endl;
                playerPlay(deck, state, players);
            }catch (WrongAbilityCard e){
                cout << e.what() << "Swapcard" << endl;
                playerPlay(deck, state, players);
            }
        }else if(command == "SWAPCARD"){
            try{
                SWAPCARD(players, false);
                setUsed(true);
            }catch(HaveBeenUsed e){
                cout << "Kartu Swapcard " <<  e.what() << endl;
                playerPlay(deck, state, players);
            }catch (WrongAbilityCard e){
                cout << e.what() << "Swapcard" << endl;
                playerPlay(deck, state, players);
            }
        }else if(command == "SWITCH"){
            try{
                SWITCH(players);
                setUsed(true);
            }catch(HaveBeenUsed e){
                cout << "Kartu Switch " <<  e.what() << endl;
                playerPlay(deck, state, players);
            }catch (WrongAbilityCard e){
                cout << e.what() << "Switch" << endl;
                playerPlay(deck, state, players);
            }
        }else if(command == "ABILITYLESS"){
            try{
                ABILITYLESS(players);
                setUsed(true);
            }catch(HaveBeenUsed e){
                cout << "Kartu AbilityLess " <<  e.what() << endl;
                playerPlay(deck, state, players);
            }catch (WrongAbilityCard e){
                cout << e.what() << "AbilityLess" << endl;
                playerPlay(deck, state, players);
            }
        }
    }else{
        cout << "Command Wrong" << endl;
        playerPlay(deck, state, players);
    }
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
    long long earlyReward = state.getRewardPoint();
    state.doubleRewardPoint();
    cout << getNickName() << " melakukan DOUBLE! Poin hadiah naik dari " << earlyReward << " menjadi " << state.getRewardPoint() << "!" << endl;
}

void PlayerAction::REROLL(Deck& deck){
    if(this->PlayerAbility == "Re-Roll"){
        if(abilityUsed){
            HaveBeenUsed e;
            throw e;
        } else {
            this->ownedCard - this->ownedCard.getACard(0);
            this->ownedCard - this->ownedCard.getACard(1);
            getCard(deck);
            cout << "Melakukan pembuangan kartu yang dimiliki" << endl;
            cout << "Kamu mendapatkan 2 kartu yang baru yaitu:" << endl;
            getOwnedCard().printCard();
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
            long long earlyReward = state.getRewardPoint();
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
            HaveBeenUsed e;
            throw e;
        }else{
            cout << getNickName() << " melakukan reverse!" << endl;
            state.setReverseStatus(true);
            state.setReverseStatusChange(true);
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
                    cout << e.what();
                }catch(WrongInput e){
                    cout << e.what() << endl;
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
                    cout << e.what() << endl;
                }catch(WrongInput e){
                    cout << e.what() << endl;
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
                    cout << "1. Kiri" << endl;
                    cout << "2. Kanan" << endl;
                    try{
                        index1 = getInput(2);
                        valid = true;
                    }catch(WrongChoice e){
                        cout << e.what() << endl;
                    }catch(WrongInput e){
                        cout << e.what() << endl;
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
                        cout << e.what() << endl;
                    }catch(WrongInput e){
                        cout << e.what() << endl;
                    }
                }
            }
            cout << "Kartu " << players[choice1].getNickName() << " sebelum adalah:" << endl;
            players[choice1].getOwnedCard().printCard();
            cout << "Kartu " << players[choice2].getNickName() << " sebelum adalah:" << endl;
            players[choice2].getOwnedCard().printCard();

            pair<int, char> firstCard = players[choice1].getOwnedCard().getACard(index1-1);
            pair<int, char> secondCard = players[choice2].getOwnedCard().getACard(index2-1);

            players[choice1].setACardPlayer(index1-1, secondCard);
            players[choice2].setACardPlayer(index2-1, firstCard);

            cout << "Kartu " << players[choice1].getNickName() << " sekarang adalah:" << endl;
            players[choice1].getOwnedCard().printCard();
            cout << "Kartu " << players[choice2].getNickName() << " sekarang adalah:" << endl;
            players[choice2].getOwnedCard().printCard();
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
                    cout << e.what() << endl;
                }catch(WrongInput e){
                    cout << e.what() << endl;
                }
            }
            choice = findIndex(target[choice-1], players);
            Deck temp = getOwnedCard();
            this->setOwnedCard(players[choice].getOwnedCard());
            players[choice].setOwnedCard(temp);
            cout << "Kedua kartu " << getNickName() << " telah ditukar dengan " << players[choice].getNickName() << endl;
            cout << "Kartumu sekarang adalah:" << endl;
            getOwnedCard().printCard();
            cout << "Kartu lawan: " << endl;
            players[choice].getOwnedCard().printCard();
        }
    }else{
        WrongAbilityCard e;
        throw e;
    }
}

void PlayerAction::setOwnedCard(const Deck& deck){
    this->ownedCard = deck;
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
                        cout << e.what() << endl;
                    }catch(WrongInput e){
                        cout << e.what() << endl;
                    }
                }
                choice = findIndex(target[choice-1], players);
                try{
                    players[choice].setUsed(true);
                    cout << "Kartu ability " << players[choice].getNickName() << " telah dimatikan." << endl;
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
    return -1;
}

int PlayerAction::getInput(int n){
    int choice;
    cin >> choice;
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        WrongInput e;
        throw e;
    }else{
        if(choice >= 1 && choice <=n){
            return choice;
        }else{
            WrongChoice e;
            throw e;
        }
    }
}

void PlayerAction::HALF(GameState& state){
    if(state.getRewardPoint()>1){
        long long earlyReward = state.getRewardPoint();
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
                long long earlyReward = state.getRewardPoint();
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
    cout << "Ability Card : " << this->getAbility() << endl;
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

bool PlayerAction::operator<(PlayerAction& other) {
    return this->getPlayerPoint() < other.getPlayerPoint();
}

bool PlayerAction::operator>(PlayerAction& other) {
    return this->getPlayerPoint() > other.getPlayerPoint();
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
