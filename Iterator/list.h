#pragma once

#include <memory>
#include <ostream>
#include <string>
#include <iostream>
#include <list>
#include <algorithm>

// test code 
void testLinkedList();





class Person{
    std::string fornavn;
    std::string etternavn;

public:
    Person(std::string fornavn, std::string etternavn) : fornavn{fornavn}, etternavn{etternavn}{};
    void print();

    /*friend std::ostream& operator<<(std::ostream out, const Person &person){
        out << person.fornavn << " " << person.etternavn;
        return out;
    }*/

    bool operator<(const Person& other) const {
        if (fornavn != other.fornavn) {
            return fornavn < other.fornavn;
        } else {
            return etternavn < other.etternavn;
        }
    }

    friend void printList(std::list<Person> &l);

};

void printList(std::list<Person> &l);
void insertOrdered(std::list<Person> &l, const Person& p);

void test();