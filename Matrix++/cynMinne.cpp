#include "dynMinne.h"


void fillInFibonacciNumbers(int* result, int length){
    int a = 0, b = 1; //Starttallene i Fibonacci
    for(int i = 0; i < length; i++){
        result[i] = a;
        int next = a + b; //Regner ut det neste Fib. tallet
        a = b;
        b = next;
    }
}

void printArray(int* arr, int length){
    for(int i = 0; i < length; i++){
        std::cout << "Verdien er: " << arr[i] << std::endl;
    }
}

void createFibonacci() {
// 1. Spør brukeren hvor mange tall som skal genereres
    int length;
    std::cout << "Hvor mange tall skal genereres: ", std::cin >> length;
    
// 2. Alloker minne til en tabell som er stor nok til tallrekka 
    int* arr = new int[length];
// 3. Fylle tabellen med fillInFibonacciNumbers()
    fillInFibonacciNumbers(arr, length);
// 4. Skriv ut resultatet til skjerm med printArray()
    printArray(arr, length);
// 5. Frigjør minnet du har reservert
    delete[] arr;
}
