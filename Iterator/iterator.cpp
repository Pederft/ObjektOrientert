#include "iterator.h"

std::vector<std::string>::iterator it;
std::set<std::string>::iterator it2;


void vecFor(std::vector<std::string> h){
    for(it = h.begin(); it != h.end(); it++){
        std::cout << *it << std::endl;
    }
}


void vecBak(std::vector<std::string> h){
    std::vector<std::string>::reverse_iterator rit = h.rbegin();
    while(rit != h.rend()){
        std::cout << *rit << std::endl;
        rit++;
    }
}

void Hei(std::vector<std::string>& h, std::string old, std::string replacement){
    for(it = h.begin(); it != h.end(); it++){
        if(*it == old){
            it = h.erase(it);
            it = h.insert(it, replacement);
            //*it = replacement;
        }
    }
    vecFor(h);
}

//--------------------------------------------
// Set:

void setFor(std::set<std::string> h){
    for(it2 = h.begin(); it2 != h.end(); it2++){
        std::cout << *it2 << std::endl;
    }
}

void setBak(std::set<std::string> h){
    std::set<std::string>::reverse_iterator rit2 = h.rbegin();
    
    while(rit2 != h.rend()){
        std::cout << *it2 << std::endl;
        rit2++;
    }
}


// Set tar inn og automatisk sorterer listen, og fjerner repeterende ord
void Hallaisen(std::set<std::string>& h, std::string old, std::string replacement){
    for(it2 = h.begin(); it2 != h.end(); it2++){
        if(*it2 == old){
            it2 = h.erase(it2);
            it2 = h.insert(it2, replacement);
        }
    }
    setFor(h);
}


/*
Hva er forskjellen på set og vektor, og når bør en bruke dem forskjellig?

Svar: 
Vektor: er et dynamisk minne, som betyr at den kan endre størrelse mens programmet kjører. Vektorer er 
        effektive hvis du vil ha en beholder som har tilfeldig tilgang (for eks. indeks basert), og som du vil
        kunne endre størrelsen til underveis.

Set:    er en samling av ulike verdier i sortert rekkefølge. Settet er implementert som et balansert binærtre
        og gir dermed rask tilgang og innsetting av elementer. Siden verdien i settet alltid er sortert, er
        det raskt å finne elementer og sjekke om en verdi finnes eller ikke. 
        
*/