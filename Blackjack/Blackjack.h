#pragma once
#include "Card.h"
#include "CardDeck.h"

class Blackjack{
private:
    CardDeck deck;
    vector<Card> playerHand;
    vector<Card> dealerHand;
    int playerHandSum = 0;
    int dealerHandSum = 0;
public:
    bool isAce(Card card);
    int getCardValue(Card card);
    int getHandScore(vector<Card> cards);
    bool askPlayerDrawCard();
    void drawPlayerCard();
    void drawDealerCard();
    void playGame();
};