#include "LinkedList.h"
#include "list.h"
#include "iterator.h"





int main(){
    std::vector<std::string> hola{ "Consectetur", "Amet", "Sit", "Dolor", "Ipsum", "Lorem"};
    std::vector<std::string> hei{ "Lorem", "Amet", "Lorem", "Dolor", "Ipsum", "Lorem"};
    std::set<std::string> hallaisen2{"Lorem", "Amet", "Lorem", "Dolor", "Ipsum", "Lorem"};

    std::set<std::string> hallaballa(hei.begin(), hei.end());

    //vecBak(hola);

    //Hallaisen(hallaballa, "Lorem", "Latin");


    test();


    return 0;
}