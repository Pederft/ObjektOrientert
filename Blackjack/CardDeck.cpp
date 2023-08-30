#include "CardDeck.h"

CardDeck::CardDeck(){
    for(int i = 0; i<4; i++){
        Suit type = static_cast<Suit>(i);
        for(int k = 2; k < 15; k++){
            //Bruker Card-klassen for å lage kortene og samle dem i vektoren til CardDeck
            Rank verdi = static_cast<Rank>(k);
            Card kort{type, verdi};
            cards.push_back(kort);
        }
    }
}

void CardDeck::print(){
    for(int i = 0; i<cards.size() ; i++){
        //Bruker Card klassen til å lage kortene og printe dem
        Card visKort = cards.at(i);
        cout << visKort.toString() << endl; 
    }     
}

void CardDeck::swap(int indeks1, int indeks2){
    Card en = cards.at(indeks1);
    Card to = cards.at(indeks2);
    cards.at(indeks1) = to;
    cards.at(indeks2) = en;
}

//Bruker random funksjonen fra øving 3
int randomWithLimits(int ovreGrense, int nedreGrense){
    random_device rd;
    default_random_engine generator(rd()); 
    std::uniform_int_distribution<int> distribution(ovreGrense,nedreGrense);
    int number = distribution(generator); 
    return number;
}

void CardDeck::shuffle(){
    for(int i = 0; i < 52; i++){
        swap(randomWithLimits(0,51), randomWithLimits(0,51));
    }
}

Card CardDeck::drawCard(){
    Card oversteKort = cards.at(cards.size()-1);
    cards.pop_back();
    return oversteKort;
}