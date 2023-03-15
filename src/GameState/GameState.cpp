#include "GameState.hpp"

using namespace std;

int GameState::totalTurn = 0;
int GameState::round = 1;

GameState::GameState() {
    this->rewardPoint = 64;

    // // Empty Table Card
    // this->tableCard.setCards({});

    for (int i = 0; i < PLAYERORDER_LENGTH; i++) {
        this->playerOrder[i] = 0;
    }

    this->currentTurn = 1;
    this->reverseStatus = false;
    this->reverseStatusChange = false;
}

int GameState::getRewardPoint() {
    return this->rewardPoint;
}

void GameState::setRewardPoint(int x) {
    this->rewardPoint = x;
}

int GameState::getCurrentTurn() {
    return this->currentTurn;
}

// void GameState::showTableCard() {
//     for (int i = 0; i < this->tableCard.getCards().size(); i++) {
//         cout << this->tableCard.getCards()[i].first << this->tableCard.getCards()[i].second << " ";
//         if (i == 4) {
//             cout << endl;
//         }
//     }
// }

bool GameState::getReverseStatus() {
    return this->reverseStatus;
}

bool GameState::getReverseStatusChange() {
    return this->reverseStatusChange;
}

int GameState::getTotalTurn() {
    return totalTurn;
}

void GameState::setCurrentTurn(int x) {
    this->currentTurn = x;
}

void GameState::setReverseStatus(bool status) {
    this->reverseStatus = status;
}

void GameState::setReverseStatusChange(bool status) {
    this->reverseStatusChange = status;
}

void GameState::setTotalTurn(int x) {
    totalTurn = x;
}

void GameState::addTableCard(Deck& d) {
    this->tableCard.getCards().push_back(d.getCards()[0]);
    d.getCards().erase(d.getCards().begin());
}

void GameState::fourtimesRewardPoint() {
    this->setRewardPoint(4 * this->getRewardPoint());
}

void GameState::doubleRewardPoint() {
    this->setRewardPoint(2 * this->getRewardPoint());
}

void GameState::halfRewardPoint() {
    this->setRewardPoint(0.5 * this->getRewardPoint());
}

void GameState::quarterRewardPoint() {
    this->setRewardPoint(0.25 * this->getRewardPoint());
}

void GameState::nextPlayerOrder() {
    int copyPlayerOrder[7];
    this->playerOrder[totalTurn] = this->currentTurn; 
    if (!this->reverseStatus) {
        if (round == 1) {
            if (!this->reverseStatusChange) {
                this->currentTurn = (this->currentTurn + 1) % 7;
                if (this->currentTurn == 0) this->currentTurn += 7;
                totalTurn++;
            } else {
                this->currentTurn = (this->currentTurn + totalTurn + 1) % 7;
                if (this->currentTurn == 0) this->currentTurn += 7;
                totalTurn++;
                this->reverseStatusChange = false;
            }
            if (totalTurn == 6) {
                totalTurn = 0;
                round++;
                if (round == 7) round = 1;
                this->currentTurn = playerOrder[1];
                this->reverseStatusChange = false;
                for (int i = 0; i < PLAYERORDER_LENGTH; i++) {
                    copyPlayerOrder[i] = this->playerOrder[i];
                    cout << copyPlayerOrder[i] << " ";
                    if (i == PLAYERORDER_LENGTH - 1) cout << endl; // BENAR
                }
            }
        } else {
            totalTurn++;
            if (totalTurn + 1 <= 6) {
                this->currentTurn = copyPlayerOrder[totalTurn + 1];
            } else {
                this->currentTurn = copyPlayerOrder[0];
            }
            this->playerOrder[totalTurn] = this->currentTurn;
            if (totalTurn == 7) {
                totalTurn = 0;
                for (int i = 0; i < PLAYERORDER_LENGTH; i++) {
                    copyPlayerOrder[i] = this->playerOrder[i];
                    cout << copyPlayerOrder[i] << " ";
                    if (i == PLAYERORDER_LENGTH - 1) cout << endl;
                }
            }
            round++;
            if (round == 7) round = 1;
        }
    } else {
        if (round == 1) {
            if (!this->reverseStatusChange) { 
                this->currentTurn = (this->currentTurn - 1) % 7;
                if (this->currentTurn <= 0) this->currentTurn += 7;
                totalTurn++;
            } else {
                currentTurn = (currentTurn - totalTurn - 1) % 7;
                if (this->currentTurn <= 0) this->currentTurn += 7;
                totalTurn++;
                this->reverseStatusChange = false; 
            }
            if (totalTurn == 7) {
                totalTurn = 0;
                round++;
                if (round == 7) round = 1;
                this->currentTurn = playerOrder[1];
                this->reverseStatusChange = false;
                for (int i = 0; i < PLAYERORDER_LENGTH; i++) {
                    copyPlayerOrder[i] = this->playerOrder[i];
                    cout << copyPlayerOrder[i] << " ";
                    if (i == PLAYERORDER_LENGTH - 1) cout << endl;
                }
            }
        } else {
            totalTurn--;
            if (totalTurn <= 0) totalTurn += 7;
            if (totalTurn - 1 >= 0) {
                this->currentTurn = copyPlayerOrder[totalTurn - 1];
            } else {
                this->currentTurn = copyPlayerOrder[6];
            }
            this->playerOrder[totalTurn] = this->currentTurn;
            if (totalTurn == 6) {
                totalTurn = 0;
                for (int i = 0; i < PLAYERORDER_LENGTH; i++) {
                    copyPlayerOrder[i] = this->playerOrder[i];
                    cout << copyPlayerOrder[i] << " ";
                    if (i == PLAYERORDER_LENGTH - 1) cout << endl;
                }
            }
            round++;
            if (round == 7) round = 1;
        }
        
    }
}

void GameState::showPlayerOrder() {
    for (int i = 0; i < PLAYERORDER_LENGTH; i++) {
        cout << this->playerOrder[i] << " ";
        if (i == PLAYERORDER_LENGTH - 1) {
            cout << endl;
        }
    }
}


// bool GameState::isWin(vector<Player> P) {
//     bool result = false;
//     int i = 0;
//     while (!result && i < P.size()) {
//         if (P[i].getPlayerPoint() >= pow(2, 32)) {
//             result = true;
//         }
//         i++;
//     }
//     return result;
// }

void GameState::reset() {
    this->rewardPoint = 64;

    // Empty Table Card
    for (int i = 0; i < this->tableCard.getCards().size(); i++) {
        this->tableCard.getCards().erase(this->tableCard.getCards().begin());
    }

    for (int i = 0; i < PLAYERORDER_LENGTH; i++) {
        this->playerOrder[i] = 0;
    }

    this->currentTurn = 1;
    this->reverseStatus = false;
    this->reverseStatusChange = false;
}