
#include "Card.h"
#include "CardDeck.h"
#include "Blackjack.h"
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------'


int main() {
    /*
    cout << "\n\n----------------\n\n" << endl;
    CardDeck tester{};
    tester.shuffle();
    cout << (tester.drawCard()).toString() << endl;
    cout << "\n\n----------------\n\n" << endl;
    tester.print();
    cout << "\n\n----------------\n\n" << endl;*/


    Blackjack b;
    b.playGame();
    return 0;
}

//------------------------------------------------------------------------------

