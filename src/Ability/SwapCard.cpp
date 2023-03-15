#include "SwapCard.hpp"
// #include <bits/stdc++.h>

using namespace std;

void SwapCard::getCardInfo()
{
    cout << "Swap Card, menukar 1 kartu main deck milik pemain lain dengan 1 kartu main deck milik pemain lain. Tidak boleh ditukar dengan kartu main deck diri sendiri." << endl;
}

int SwapCard::getCard(string choice)
{
    if (choice == "left")
    {
        return 0;
    }
    else if (choice == "right")
    {
        return 1;
    }
}

int SwapCard::getInput()
{
    int idx;
    bool validChoice = false;
    while (!validChoice)
    {
        try
        {
            string currentChoice = getChoice();
            validChoice = true;
            idx = getCard(currentChoice);
        }
        catch (WrongChoice e)
        {
            e.what();
            cout << endl;
        }
    }
    return idx;
}

void SwapCard::callCard(PlayerCollection &player, GameState &state, Deck &deck)
{
    cout << "This is your target" << endl;
    printTarget(player);
    bool inputValid = false;
    string targetNickName;
    while (!inputValid)
    {
        try
        {
            targetNickName = getTarget(player);
        }
        catch (WrongChoice e)
        {
            e.what();
        }
    }
    int idxTargetNickName = player.getTargetIdx(targetNickName);
    int idxCurrent;
    int idxTarget;
    cout << "Please choose your card, input left or right (LOWERCASE MATTER)" << endl;
    idxCurrent = getInput();
    cout << "Please choose target card, input left or right (LOWERCASE MATTER)" << endl;
    idxTarget = getInput();
    // swap(target, current, idxTarget, idxCurrent);
    pair<int, char> targetCard = player.getPlayer()[idxTargetNickName].getOwnedCard().getACard(idxTarget);
    pair<int, char> currentCard = this->getOwnedCard().getACard(idxCurrent);
    player.getPlayer()[idxTargetNickName].getOwnedCard().setACard(idxTarget, currentCard);
    this->getOwnedCard().setACard(idxCurrent, targetCard);
}

string SwapCard::getChoice()
{
    cout << "Please include your choice: " << endl;
    string choice;
    cin >> choice;
    if (choice != "left" && choice != "right")
    {
        WrongChoice e;
        throw e;
    }
    return choice;
}

void SwapCard::printTarget(PlayerCollection &player)
{
    int n = 1;
    for (int i = 0; i < 7; i++)
    {
        if (player.getPlayer()[i].getNickName() != this->nickName)
        {
            cout << n << ". " << player.getPlayer()[i].getNickName();
            n++;
        }
    }
}

string SwapCard::getTarget(PlayerCollection &player)
{
    cout << "Please include your choice (nickname) : ";
    string choice;
    cin >> choice;
    if (player.checkTarget(choice, this->nickName))
    {
        return choice;
    }
    else
    {
        WrongChoice e;
        throw e;
    }
}