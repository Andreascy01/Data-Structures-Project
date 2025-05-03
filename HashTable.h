#ifndef PROJECT_HASHTABLE_H
#define PROJECT_HASHTABLE_H
#include<string>
#include<iostream>

using namespace std;

class HashTable {

private:
    long long int size, lekseis;
    struct KAST *HashTab;


public:
    HashTable();

    long long int HashValue(string);

    void Insert(string);
    int Search(string);
    void display();
};

#endif //PROJECT_HASHTABLE_H

/* ☺☺☺☺☺☺☺☺☺☺ ΣΤΕΦΑΝΟΣ ΑΝΑΣΤΑΣΙΑΔΗΣ ΑΕΜ 4023 ☺☺☺☺☺☺☺☺☺☺ */

/* ☺☺☺☺☺☺☺☺☺☺ ΑΝΤΡΕΑΣ  ΚΑΤΣΟΝΟΥΡΗΣ  ΑΕΜ 4054 ☺☺☺☺☺☺☺☺☺☺ */