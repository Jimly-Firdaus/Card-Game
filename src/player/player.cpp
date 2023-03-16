#include "player.hpp"

Player::Player()
{
    this->playerPoint = 0;
    this->nickName = "none";
}

void Player::getCard(Deck &Deck)
{
    pair<int, char> firstCard = Deck.getTopCard();
    Deck - firstCard;
    pair<int, char> secondCard = Deck.getTopCard();
    Deck - secondCard;
    this->ownedCard + firstCard;
    this->ownedCard + secondCard;
}

long long Player::getPlayerPoint()
{
    return this->playerPoint;
}

string Player::getNickName()
{
    return this->nickName;
}

void Player::setPlayerPoint(long long playerPoint)
{
    this->playerPoint = playerPoint;
}

void Player::setNickName(string nickName)
{
    this->nickName = nickName;
}

Deck Player::getOwnedCard()
{
    return this->ownedCard;
}

void Player::setACardPlayer(int idx, pair<int, char> card)
{
    this->ownedCard.setACard(idx, card);
}
