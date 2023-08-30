# include "utilities.h"


int randomWithLimits(int ovreGrense, int nedreGrense){
    random_device rd;
    default_random_engine generator(rd()); 
    std::uniform_int_distribution<int> distribution(ovreGrense,nedreGrense);
    int number = distribution(generator); 
    return number;
}


