#pragma once 
#include <iostream> 
#include <utility>

class Dummy { 
    public:
    //std::unique_ptr<int> num; 
    int* num;

    Dummy() {
        num = new int{0}; 
    }

    Dummy(const Dummy& other){
        //this->num = new int{};
        //*num = other.get();

        this->num = new int;
        *num = *other.num;
    }

    /*int get() const {
        return *num;
    }*/

    Dummy& operator=(Dummy rhs){
    std::swap(num, rhs.num); //Bytter på pekerne
    return *this;
    }

    ~Dummy() { 
        delete num; 
    } 
};

void dummyTest();


class Example { 
    private:
        int *anInt;
    public: 
    
    Example(int i) {
        anInt = new int{i}; 
    }
    
    Example() {
        anInt = new int{0};
    }
    ~Example() { 
        delete anInt;
    }
    int get() const { return *anInt; } 
};