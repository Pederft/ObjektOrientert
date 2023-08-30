#include "Blackjack.h"

bool Blackjack::isAce(Card card){
    if(card.getRank() == Rank::ace){
        return true;
    } else{
        return false;
    }
}

int Blackjack::getCardValue(Card card){
    Rank rank = card.getRank();
    if(Blackjack::isAce(card)==true){
        return 11;
    } else if(static_cast<int>(rank)>=10){
        return 10;
    } else{
        return static_cast<int>(rank);
    }
}

int Blackjack::getHandScore(vector<Card> cards){
    int poeng = 0;
    for(int i = 0; i<static_cast<int>(cards.size()); i++){
        //Sjekker om begge kortene er et ess. Dersom det er tilfellet skal poengsummen returneres som 12;
        if((Blackjack::isAce(cards.at(i)) == true) && (playerHandSum > 10)){
            poeng += 1;
        } else{
            poeng += Blackjack::getCardValue(cards.at(i));
        }
    }
    return poeng;
}

bool Blackjack::askPlayerDrawCard(){
    cout << "Ønsker du å trekke et nytt kort?" << endl;
    string svar;
    cin >> svar;
    if((svar == "Ja")||(svar == "JA") || (svar == "ja")){
        return true;
    } else {
        return false;
    }
}

void Blackjack::drawPlayerCard(){
    Card card = deck.drawCard();
    playerHand.push_back(card);
    playerHandSum += getCardValue(card);
}

void Blackjack::drawDealerCard(){
    Card card = deck.drawCard();
    dealerHand.push_back(card);
    dealerHandSum += getCardValue(card);
}


void Blackjack::playGame(){
    bool spill = true;
    string svar;
    while(spill == true){
        deck.shuffle();
        drawPlayerCard();
        drawDealerCard();
        cout << "Delearen sitt første kort er: " << dealerHandSum << endl;
        while(playerHandSum < 21){
            cout << "\nDin poengsum er nå: " << playerHandSum << endl;
            if(askPlayerDrawCard() == true){
                drawPlayerCard();
            } else{
                break;
            }
        }
        while(dealerHandSum<17){
            drawDealerCard();
        }

        //Kunne alternativt laget det som en case for hurtigere kjøretid

        if((playerHandSum > dealerHandSum) && (playerHandSum < 21)){
            cout << "-----------------------------" << endl;
            cout << "\nDu har vunnet!!\n" << endl;
            cout << "Dealer sin hånd: " << dealerHandSum << endl;
            cout << "Din hånd:        " << playerHandSum << endl;
            cout << "Din hånd:        " << getHandScore(playerHand) << endl;
            break;
        } else if(dealerHandSum > 21){
            cout << "-----------------------------" << endl;
            cout << "\nDu har vunnet!! Dealeren fikk over 21\n" << endl;
            cout << "Dealer sin hånd: " << dealerHandSum << endl;
            cout << "Din hånd:        " << playerHandSum << endl;
            cout << "Din hånd:        " << getHandScore(playerHand) << endl;
            break;
        } else if(playerHandSum > 21){
            cout << "-----------------------------" << endl;
            cout << "\nDu har dessverre tapt runden\n" << endl;
            cout << "Dealer sin hånd: " << dealerHandSum << endl;
            cout << "Din hånd:        " << playerHandSum << endl;
            cout << "Din hånd:        " << getHandScore(playerHand) << endl;
            break;
        } else if(playerHandSum == dealerHandSum){
            cout << "-----------------------------" << endl;
            cout << "\nDet ble likt mellom dealer og spiller.\n" << endl;
            cout << "Dealer sin hånd: " << dealerHandSum << endl;
            cout << "Din hånd:        " << playerHandSum << endl;
            cout << "Din hånd:        " << getHandScore(playerHand) << endl;
            break;
        } else if((dealerHandSum > playerHandSum) && (dealerHandSum < 21)){
            cout << "-----------------------------" << endl;
            cout << "\nDu tapte dessverre.\n" << endl;
            cout << "Dealer sin hånd: " << dealerHandSum << endl;
            cout << "Din hånd:        " << playerHandSum << endl;
            cout << "Din hånd:        " << getHandScore(playerHand) << endl;
            break;
        }

        /*cout << "\n\nØnsker du å spille på ny?" << endl;
        cin >> svar;
        if(svar == "Ja"){
            spill = true;
        } else{
            spill = false;
        }*/
    }
    
}