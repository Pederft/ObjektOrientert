#pragma once
#include "std_lib_facilities.h"
#include <map>
#include <string>
#include <cmath>



enum class Suit{clubs, diamonds, hearts, spades};
enum class Rank{two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};

string suitToString(Suit type);
string rankToString(Rank type);

const std::map< Suit, std::string> nameSuitMap{
    {Suit::clubs,    "Clubs"},
    {Suit::diamonds, "Diamonds"},
    {Suit::hearts,   "Hearts"},
    {Suit::spades,   "Spades"}
};

const std::map< Rank, std::string> nameRankMap{
    {Rank::two,   "Two"},
    {Rank::three, "Three"},
    {Rank::four,  "Four"},
    {Rank::five,  "Five"},
    {Rank::six,   "Six"},
    {Rank::seven, "Seven"},
    {Rank::eight, "Eight"},
    {Rank::nine,  "Nine"},
    {Rank::ten,   "Ten"},
    {Rank::jack,  "Jack"},
    {Rank::queen, "Queen"},
    {Rank::king,  "King"},
    {Rank::ace,   "Ace"},
};

class Card{
    Suit s;
    Rank r;

    public:
        Card(Suit s, Rank r);
        Suit getSuit();
        Rank getRank();
        string toString();
};

