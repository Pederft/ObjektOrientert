#include "list.h"

void Person::print(){
    std::cout << fornavn << " " << etternavn << std::endl;
}

void insertOrdered(std::list<Person> &l, const Person& p){
    l.push_back(p);

    l.sort();
}


void printList(std::list<Person> &l){
    std::list<Person>::iterator itr;

    for(itr = l.begin(); itr != l.end(); itr++){
        std::cout << itr->fornavn << " " << itr->etternavn  << std::endl;
    }

}

void test(){
    Person P("Peder", "Time");
    Person O( "Oda", "Time");
    Person E("Eirik", "Time");
    Person S("Siri", "Time");
    Person I("Inger Lise", "Faltinsen");

    Person K("Karsten", "Hund");

    //P.print();


    //------------------------------
    // Linked lists:

    std::list<Person> Personer{P, O, E, S, I};
    std::list<Person> test;
    Personer.sort();
    printList(Personer);

    std::cout << " --------- " << std::endl;

    insertOrdered(test, K);

    printList(test);

}