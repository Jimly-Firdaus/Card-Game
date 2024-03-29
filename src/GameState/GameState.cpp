#include "GameState.hpp"
#include <cmath>

int GameState::totalTurn = 0;
int GameState::round = 1;
int GameState::gameNumber = 1;

GameState::GameState()
{
    this->rewardPoint = 64;
    this->tableCard.setCards({});
    for (int i = 0; i < PLAYERORDER_LENGTH; i++)
    {
        this->playerOrder[i] = 0;
    }
    this->currentTurn = 1;
    this->reverseStatus = false;
    this->reverseStatusChange = false;
}

long long GameState::getRewardPoint()
{
    return this->rewardPoint;
}

void GameState::setRewardPoint(long long x)
{
    this->rewardPoint = x;
}

int GameState::getCurrentTurn()
{
    return this->currentTurn;
}

void GameState::showTableCard()
{
    for (int i = 0; i < this->tableCard.getCards().size(); i++)
    {
        cout << this->tableCard.getCards()[i].first << this->tableCard.getCards()[i].second << " ";
        if (i == 4)
        {
            cout << endl;
        }
    }
}

bool GameState::getReverseStatus()
{
    return this->reverseStatus;
}

bool GameState::getReverseStatusChange()
{
    return this->reverseStatusChange;
}

int GameState::getTotalTurn()
{
    return totalTurn;
}

int GameState::getGameNumber()
{
    return gameNumber;
}

void GameState::setCurrentTurn(int x)
{
    this->currentTurn = x;
}

void GameState::setReverseStatus(bool status)
{
    this->reverseStatus = status;
}

void GameState::setReverseStatusChange(bool status)
{
    this->reverseStatusChange = status;
}

void GameState::setTotalTurn(int x)
{
    totalTurn = x;
}

void GameState::setGameNumber(int x)
{
    gameNumber = x;
}

void GameState::addTableCard(Deck &d)
{
    pair<int, char> firstCard = d.getTopCard();
    d - firstCard;
    this->tableCard + firstCard;
}

void GameState::fourtimesRewardPoint()
{
    this->setRewardPoint(4 * this->getRewardPoint());
}

void GameState::doubleRewardPoint()
{
    this->setRewardPoint(2 * this->getRewardPoint());
}

void GameState::halfRewardPoint()
{
    this->setRewardPoint(0.5 * this->getRewardPoint());
}

void GameState::quarterRewardPoint()
{
    this->setRewardPoint(0.25 * this->getRewardPoint());
}

void GameState::nextPlayerOrder()
{
    this->playerOrder[totalTurn] = this->currentTurn;
    if (round == 1)
    {
        if (!this->reverseStatus)
        {
            if (!this->reverseStatusChange)
            {
                this->currentTurn = (this->currentTurn + 1) % 7;
                if (this->currentTurn <= 0)
                    this->currentTurn += 7;
                totalTurn++;
            }
            else
            {
                this->currentTurn = (this->currentTurn + 1 + totalTurn) % 7;
                if (this->currentTurn <= 0)
                    this->currentTurn += 7;
                this->reverseStatusChange = false;
                totalTurn++;
            }

            if (totalTurn == 7)
            {
                round++;
                totalTurn = 0;
                this->currentTurn = this->playerOrder[1];
            }
        }
        else
        {
            if (!this->reverseStatusChange)
            {
                this->currentTurn = (this->currentTurn - 1) % 7;
                if (this->currentTurn <= 0)
                    this->currentTurn += 7;
                totalTurn++;
            }
            else
            {
                this->currentTurn = (this->currentTurn - 1 - totalTurn) % 7;
                if (this->currentTurn <= 0)
                    this->currentTurn += 7;
                this->reverseStatusChange = false;
                totalTurn++;
            }

            if (totalTurn == 7)
            {
                totalTurn = 0;
                round++;
                this->currentTurn = this->playerOrder[1];
            }
        }
    }
    else
    {
        if (!this->reverseStatus)
        {
            if (!this->reverseStatusChange)
            {
                this->currentTurn = (this->currentTurn + 1) % 7;
                if (this->currentTurn <= 0)
                    this->currentTurn += 7;
                totalTurn++;
            }
            else
            {
                this->currentTurn = (this->currentTurn + 1 + totalTurn) % 7;
                if (this->currentTurn <= 0)
                    this->currentTurn += 7;
                this->reverseStatusChange = false;
                totalTurn++;
            }

            if (totalTurn == 7)
            {
                round++;
                totalTurn = 0;
                this->currentTurn = this->playerOrder[1];
            }
        }
        else
        {
            if (!this->reverseStatusChange)
            {
                this->currentTurn = (this->currentTurn - 1) % 7;
                if (this->currentTurn <= 0)
                    this->currentTurn += 7;
                totalTurn++;
            }
            else
            {
                this->currentTurn = (this->currentTurn - 1 - totalTurn) % 7;
                if (this->currentTurn <= 0)
                    this->currentTurn += 7;
                this->reverseStatusChange = false;
                totalTurn++;
            }

            if (totalTurn == 7)
            {
                round++;
                totalTurn = 0;
                this->currentTurn = this->playerOrder[1];
            }
        }
    }

    if (round == 7)
    {
        round = 1;
        gameNumber++;
    }
}

void GameState::showPlayerOrder()
{
    for (int i = 0; i < PLAYERORDER_LENGTH; i++)
    {
        cout << this->playerOrder[i] << " ";
        if (i == PLAYERORDER_LENGTH - 1)
        {
            cout << endl;
        }
    }
}

void GameState::reset()
{
    this->rewardPoint = 64;

    // Empty Table Card
    this->tableCard.getCards().clear();

    for (int i = 0; i < PLAYERORDER_LENGTH; i++)
    {
        this->playerOrder[i] = 0;
    }

    this->currentTurn = 1;
    this->reverseStatus = false;
    this->reverseStatusChange = false;
}

Deck GameState::getTableCard()
{
    return this->tableCard;
}
