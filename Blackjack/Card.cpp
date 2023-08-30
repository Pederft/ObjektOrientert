#include "Card.h"

string suitToString(Suit type){
    return nameSuitMap.at(type);
}
string rankToString(Rank type){
    return nameRankMap.at(type);
}

Card::Card(Suit suit, Rank rank): s{suit}, r{rank}{}

Suit Card::getSuit(){
    return s;
}

Rank Card::getRank(){
    return r;
}

string Card::toString(){
    string suit = suitToString(s);
    string rank = rankToString(r);
    return( rank + " of " + suit);
}