#include "opg3.h"

void dummyTest() { 
    Dummy a;
    *a.num = 4;
    Dummy b{a};
    Dummy c;
    c = a;
    std::cout << "a: " << *a.num << '\n'; // a: 4
    std::cout << "b: " << *b.num << '\n'; // b: 4
    std::cout << "c: " << *c.num << '\n'; // c: 4
    *b.num = 3;
    *c.num = 5;
    std::cout << "\n" << std::endl;
    std::cout << "a: " << *a.num << '\n'; // a: 4
    std::cout << "b: " << *b.num << '\n'; // b: 3
    std::cout << "c: " << *c.num << '\n'; // c: 5
}


/*
Siden vi ikke har noe kopi-konstruktør vil en oppdaterin av én av klassene
a-,b- eller c oppdatere num veridien til alle siden de alle peker på samme adresse.

For å løse dette kan vi lage en kopikonstruktør, eller evt burke en std::unique_ptr eller
std::shared_ptr
*/


