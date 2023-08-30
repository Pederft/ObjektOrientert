#pragma once
#include "std_lib_facilities.h"
#include <map>
#include <string>
#include <cmath>
#include "Card.h"


class CardDeck{
        vector<Card> cards; 
    public:
        CardDeck();
        void print();
        void swap(int indeks1, int indeks2); //Hvorfor public?
        void shuffle(); 
        Card drawCard();
};

//Random funksjon
int randomWithLimits(int ovreGrense, int nedreGrense);