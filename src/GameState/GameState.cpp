#include "GameState.hpp"
#include <iostream>
using namespace std;

GameState::GameState()
{
    this->rewardPoint = 64;

    // Empty Table Card
    for (int i = 0; i < 5; i++)
    {
        tableCard.getDeckCard().push_back({0, ' '});
    }

    // Initial Order (1,2,3,4,5,6,7)
    for (int i = 0; i < 7; i++)
    {
        this->playerOrder[i] = i + 1;
    }
}

int GameState::getRewardPoint()
{
    return this->rewardPoint;
}

void GameState::setRewardPoint(int x)
{
    this->rewardPoint = x;
}

void GameState::showTableCard()
{
    for (int i = 0; i < 5; i++)
    {
        cout << this->tableCard.getDeckCard().first << this->tableCard.getDeckCard().second << " ";
        if (i == 4)
        {
            cout << endl;
        }
    }
}

void GameState::showPlayerOrder()
{
    for (int i = 0; i < 7; i++)
    {
        cout << this->playerOrder[i] << " ";
        if (i == 6)
        {
            cout << endl;
        }
    }
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
    int first = this->playerOrder[0];
    for (int i = 1; i < 7; i++)
    {
        this->playerOrder[i - 1] = this->playerOrder[i];
    }
    this->playerOrder[6] = first;
}